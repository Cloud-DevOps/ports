# $OpenBSD: Makefile,v 1.2 2016/12/28 14:10:36 zhuk Exp $

COMMENT=	PostgreSQL RDBMS (previous version, for pg_upgrade)

VERSION=	9.5.5
DISTNAME=	postgresql-${VERSION}
PKGNAME=	postgresql-previous-${VERSION}

CATEGORIES=	databases
SHARED_LIBS=	ecpg		7.7 \
		ecpg_compat	4.7 \
		pgtypes		4.6 \
		pq		6.8

HOMEPAGE=	http://www.postgresql.org/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	https://ftp.postgresql.org/pub/source/v${VERSION}/ \
		ftp://ftp.postgresql.org/pub/source/v${VERSION}/

MAKE_FILE=	GNUmakefile

SUBST_VARS=	VERSION

USE_GMAKE=	Yes
USE_GROFF=	Yes

CONFIGURE_STYLE=gnu

MODULES=	lang/python gcc4
MODPY_RUNDEP=	No
POSTGRESQL_DIR=	postgresql-${VERSION:C/.[0-9]+$//}

# for __sync_lock_test_and_set                   
MODGCC4_ARCHS= arm                         

CONFIGURE_ENV=	ac_cv_path_PYTHON=${MODPY_BIN} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-openssl=/usr \
		--with-perl \
		--without-python \
		--with-pam=no \
		--with-uuid=bsd \
		--enable-integer-datetimes \
		--bindir="${PREFIX}/bin/${POSTGRESQL_DIR}" \
		--libdir="${PREFIX}/lib/${POSTGRESQL_DIR}" \
		--includedir="${PREFIX}/include/${POSTGRESQL_DIR}" \
		--datadir="${PREFIX}/share/${POSTGRESQL_DIR}" \
		--with-includes="${INCLUDES}" \
		--with-libraries="${LOCALBASE}/lib/" \
		--with-system-tzdata="/usr/share/zoneinfo" \
		--with-openssl \
		--with-libxml \
		--disable-thread-safety

# There is no spinlock support for hppa and alpha yet. Until we have access to
# a system to get this working, disable them for now. There is
# (apparently) a serious performance hit doing this.

.if ${MACHINE_ARCH} == "hppa" || ${MACHINE_ARCH} == "alpha"
CONFIGURE_ARGS+=--disable-spinlocks
.endif

MODGNU_CONFIG_GUESS_DIRS=	${WRKSRC}/config

ALL_TARGET=	all
INSTALL_TARGET=	install

LIB_DEPENDS = textproc/libxml
WANTLIB += c crypto m readline ssl termcap z xml2 perl util

MAKE_ENV=	LIBpq_MAJOR=${LIBpq_VERSION:R} \
		LIBpq_MINOR=${LIBpq_VERSION:E} \
		LIBecpg_MAJOR=${LIBecpg_VERSION:R} \
		LIBecpg_MINOR=${LIBecpg_VERSION:E} \
		LIBecpg_compat_MAJOR=${LIBecpg_compat_VERSION:R} \
		LIBecpg_compat_MINOR=${LIBecpg_compat_VERSION:E} \
		LIBpgtypes_MAJOR=${LIBpgtypes_VERSION:R} \
		LIBpgtypes_MINOR=${LIBpgtypes_VERSION:E}

# Work around Makefile issue where it attempts to rebuild
# the documentation even if it is not necessary.
pre-build:
	touch ${WRKSRC}/doc/src/sgml/*-stamp

post-build:
	cd ${WRKSRC}/contrib && gmake

SUBST_VARS +=	POSTGRESQL_DIR

INSTALL_REPLACE = 's/^install_bin = .*$$/ifdef BSD_INSTALL_SCRIPT\ninstall_bin
INSTALL_REPLACE += = \$$\(subst -m 755,,\$${BSD_INSTALL_SCRIPT}\)
INSTALL_REPLACE += \nelse\ninstall_bin = \/usr\/bin\/install -c -o ${BINOWN}
INSTALL_REPLACE += -g ${BINGRP}\nendif/'
post-install:
	cd ${WRKSRC}/contrib && gmake install
	perl -i -pe ${INSTALL_REPLACE} \
		${PREFIX}/lib/${POSTGRESQL_DIR}/pgxs/src/Makefile.global

.include <bsd.port.mk>
