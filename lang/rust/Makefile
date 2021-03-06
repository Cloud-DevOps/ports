# $OpenBSD: Makefile,v 1.36 2017/02/02 08:02:50 landry Exp $

# snapshots are only available for amd64 and i386, for now
ONLY_FOR_ARCHS =	amd64 i386

COMMENT-main =		compiler for Rust Language
COMMENT-doc =		html documentation for rustc

V =			1.14.0
BV-amd64 =		1.14.0-20161221
BV-i386 =		1.14.0-20161221
DISTNAME =		rustc-${V}-src
REVISION =		0

#RUST_HASH !=		echo -n ${V} | md5 | cut -c1-8
RUST_HASH =		f5a209a9
SUBST_VARS +=		RUST_HASH
BV =			${BV-${MACHINE_ARCH}}

PKGNAME =		rust-${V}
PKGNAME-main =		rust-${V}
PKGNAME-doc =		rust-doc-${V}

MULTI_PACKAGES =	-main -doc

CATEGORIES =		lang

HOMEPAGE =		http://www.rust-lang.org/
MAINTAINER =		Sebastien Marie <semarie@online.fr>

# both MIT and Apache2.0
# with portions covered by various BSD-like licenses
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB-main =		${WANTLIB} c m pthread z
WANTLIB-doc =

MASTER_SITES =		https://static.rust-lang.org/dist/
MASTER_SITES0 =		http://kapouay.odns.fr/pub/rust/

DIST_SUBDIR =		rust
DISTFILES =		${DISTNAME}${EXTRACT_SUFX} \
			${BOOTSTRAP}

BOOTSTRAP =		${BOOTSTRAP-${MACHINE_ARCH}}
.for m in i386 amd64
BOOTSTRAP-$m =		rustc-bootstrap-${m}-${BV-$m}.tar.gz:0
SUPDISTFILES +=		${BOOTSTRAP-$m}
.endfor

WRKDIST =		${WRKDIR}/${DISTNAME:S/-src//}

# MACHINE_ARCH to TRIPLE_ARCH conversion
.if "${MACHINE_ARCH}" == "amd64"
TRIPLE_ARCH =		x86_64-unknown-openbsd
.elif "${MACHINE_ARCH}" == "i386"
TRIPLE_ARCH =		i686-unknown-openbsd
.endif
SUBST_VARS +=		TRIPLE_ARCH

# PFRAG
.if ${MACHINE_ARCH} == amd64
PKG_ARGS += -Db64=1
.else
PKG_ARGS += -Db64=0
.endif

.if ${MACHINE_ARCH} == i386
PKG_ARGS += -Db32=1
.else
PKG_ARGS += -Db32=0
.endif

MODULES +=		gcc4 \
			lang/python
BUILD_DEPENDS +=	devel/cmake
MODPY_RUNDEP =		No

# rustllvm need c++11
MODGCC4_LANGS =		c++
MODGCC4_ARCHS =		*

# need to be keep in sync
LIBESTDC_VERSION =	17.0

# note: VERBOSE permit to unhide Makefile processing
# 	RUSTFLAGS extra flags passed to rust
# 		-L modgcc-libs : disambiguate libestdc++.so
#       RUST_LOG helper
MAKE_ENV =		VERBOSE=1 \
			RUSTFLAGS="-L ${WRKDIR}/modgcc-libs" \
			RUST_LOG="${RUST_LOG}"


# build/configuration variables
#
SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes

CONFIGURE_STYLE =	simple
CONFIGURE_ARGS +=	--disable-valgrind-rpass \
			--disable-codegen-tests \
			--release-channel=stable \
			--local-rust-root="${WRKDIR}/rustc-bootstrap-${MACHINE_ARCH}-${BV}" \
			--prefix="${LOCALBASE}" \
			--mandir="${LOCALBASE}/man"

# VERSION and BOOTSTRAP are same major version
.if ${V:C/\.[0-9]+$//} == ${BV:C/\.[0-9]+-[0-9]+$//}
CONFIGURE_ARGS +=	--enable-local-rebuild
.endif

CONFIGURE_ENV +=	ac_cv_header_execinfo_h=no

# need for libbacktrace
USE_LIBTOOL =		gnu

ALL_TARGET +=		rustc-stage2 docs
TEST_TARGET =		check
TEST_ENV +=		ALLOW_NONZERO_RLIMIT_CORE=1
TEST_DEPENDS +=		devel/git

# - check datasize limit before configuring (and building)
pre-configure:
	@if [ `ulimit -d` -lt 1572864 ]; then \
		echo datasize limit is too low - amd64 build takes approx 1.5GB; \
		exit 1; fi

# - remove autodetected programs
# - copy libestdc++ from MODGCC4 to specific directory
#   in order to disambiguate version linking (having multiple libestdc++
#   at build time)
# - copy bootstrap in stage0 (permit copying bootstrapped libs in stage0)
post-configure:
.for _v in CFG_CURL CFG_GIT CFG_CLANG CFG_VALGRIND CFG_PERF CFG_ISCC \
	CFG_JAVAC CFG_ANTLR4 CFG_BISON CFG_PANDOC CFG_GDB CFG_LLDB \
	CFG_GDB_VERSION CFG_ADB
	perl -pi -e 's/^${_v} .*/${_v} := /' ${WRKBUILD}/config.mk
.endfor
	rm -rf ${WRKDIR}/modgcc-libs
	mkdir ${WRKDIR}/modgcc-libs
	cp ${LOCALBASE}/lib/libestdc++.so.${LIBESTDC_VERSION} ${WRKDIR}/modgcc-libs
	cp ${WRKDIR}/rustc-bootstrap-${MACHINE_ARCH}-${BV}/bin/rustc \
		${WRKBUILD}/${TRIPLE_ARCH}/stage0/bin
	cp ${WRKDIR}/rustc-bootstrap-${MACHINE_ARCH}-${BV}/lib/lib*.so* \
		${WRKBUILD}/${TRIPLE_ARCH}/stage0/lib

post-install:
	# cleanup
	rm ${PREFIX}/lib/rustlib/{install.log,uninstall.sh,rust-installer-version}


# bootstrap target permits to regenerate the bootstrap archive
# it is based on stage3 binary
BOOTSTRAPDIR=${WRKDIR}/rustc-bootstrap-${MACHINE_ARCH}-${V}-new
bootstrap: configure
	rm -rf ${BOOTSTRAPDIR}
	mkdir -p ${BOOTSTRAPDIR}/{bin,lib}
	cd ${WRKBUILD} && exec ${SETENV} ${MAKE_ENV} ${GMAKE} rustc-stage3
	cp ${WRKBUILD}/${TRIPLE_ARCH}/stage3/bin/rustc ${BOOTSTRAPDIR}/bin
	strip ${BOOTSTRAPDIR}/bin/rustc
	ldd ${BOOTSTRAPDIR}/bin/rustc \
		| sed -ne 's,.* \(/.*/lib/lib.*\.so.[.0-9]*\)$$,\1,p' \
		| xargs -r -J % cp % \
			${BOOTSTRAPDIR}/lib

.include <bsd.port.mk>
