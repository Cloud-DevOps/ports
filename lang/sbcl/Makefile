# $OpenBSD: Makefile,v 1.33 2017/02/06 12:23:14 sthen Exp $

# not yet ported to other arches
ONLY_FOR_ARCHS =	amd64 i386 powerpc
USE_WXNEEDED =		Yes

COMMENT=		compiler and runtime system for ANSI Common Lisp

V =			1.3.10
REVISION=		1
DISTNAME=		sbcl-${V}-source
PKGNAME=		sbcl-${V}
WRKDIST=		${WRKDIR}/sbcl-${V}
EXTRACT_SUFX=		.tar.bz2

CATEGORIES=		lang
HOMEPAGE=		http://www.sbcl.org/
MAINTAINER =		Joshua Elsasser <joshe@openbsd.org>

# Public domain and BSD
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sbcl/}

MODULES=		gcc4
MODGCC4_ARCHS=		i386
MODGCC4_LANGS=		c

WANTLIB=		c m util

PSEUDO_FLAVORS=		native_bootstrap
FLAVORS=		threads
FLAVOR?=

EXTRA_PARAMS=
.if ${FLAVOR:Mthreads}
ONLY_FOR_ARCHS =	amd64
EXTRA_PARAMS+=		--with-sb-thread
WANTLIB+=		pthread
.endif

.if ${FLAVOR:Mnative_bootstrap}
BUILD_DEPENDS+=		lang/sbcl
BOOTSTRAP_CMD=		${LOCALBASE}/bin/sbcl \
			--disable-debugger --no-sysinit --no-userinit
.else
BUILD_DEPENDS +=	lang/clisp
BOOTSTRAP_CMD =		${LOCALBASE}/bin/clisp -q -norc
.endif
TEST_DEPENDS =		devel/gmp

USE_GMAKE=		Yes
PORTHOME=		${TMPDIR}
MAKE_ENV=		GNUMAKE=${GMAKE} INSTALL_ROOT=${PREFIX} \
			MAN_DIR=${PREFIX}/man INFO_DIR=${PREFIX}/info \
			PORTS_CFLAGS="${CFLAGS}"

# Upstream asks that packagers append something like this to the
# version to distinguish official tarballs from third-party packages.
.if defined(REVISION) && !empty(REVISION)
LOCAL_VERSION =		openbsd.${REVISION}
.else
LOCAL_VERSION =		openbsd
.endif
VERSION_FILE =		${WRKSRC}/version.lisp-expr

pre-configure:
	sed 's/^"\([0-9.]*\)"$$/"\1.${LOCAL_VERSION}"/' \
		< ${VERSION_FILE} > ${VERSION_FILE}.new
	mv ${VERSION_FILE}.new ${VERSION_FILE}
	sed -i 's,egcc,${CC},g' ${WRKSRC}/src/runtime/Config.*-openbsd

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} /bin/sh make.sh \
		--prefix=${PREFIX} --xc-host="${BOOTSTRAP_CMD}" ${EXTRA_PARAMS}
	cd ${WRKSRC}/doc/manual && touch sbcl.texinfo && \
		${SETENV} ${MAKE_ENV} ${GMAKE} asdf.info sbcl.info

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} /bin/sh install.sh

post-install:
	chown -R 0:0 ${PREFIX}/lib/sbcl

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} DONT_CLEAN_SBCL_CONTRIB=1 \
	    /bin/sh make-target-contrib.sh
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} /bin/sh run-tests.sh

.include <bsd.port.mk>
