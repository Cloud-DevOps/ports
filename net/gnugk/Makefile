# $OpenBSD: Makefile,v 1.65 2016/12/31 10:19:05 ajacoutot Exp $

BROKEN-hppa=	libpt.so.7.0: undefined reference to __sync_fetch_and_or_4

COMMENT=	H.323 gatekeeper

DISTNAME=	gnugk-4.2-2
PKGNAME=	gnugk-4.2.2
REVISION=	1
WRKDIST=	${WRKDIR}/gnugk-4.2

CATEGORIES=	net telephony

HOMEPAGE=	http://www.gnugk.org/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += GeoIP SDL c crypto expat h323 kvm lber ldap ldap_r
WANTLIB += lua${MODLUA_VERSION} m netsnmp netsnmpagent netsnmpmibs pt pthread
WANTLIB += sasl2 ssh ssl stdc++ z

MODULES=	lang/lua

# uses luaL_newlib, lua_setglobal
MODLUA_VERSION=	5.2

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openh323gk/}

BUILD_DEPENDS=	databases/mariadb \
		databases/postgresql

LIB_DEPENDS=	net/GeoIP \
		net/h323plus \
		net/net-snmp \
		security/libssh

ALL_TARGET=	optshared
USE_GMAKE=	Yes
NO_TEST=	Yes

CONFIGURE_STYLE=gnu

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		OPENH323DIR=${LOCALBASE}/include/openh323 \
		OPENH323MAKEDIR=${LOCALBASE}/share/openh323 \
		PTLIBDIR=${LOCALBASE}/share/ptlib

CONFIGURE_ARGS=	--disable-sqlite \
		--disable-unixodbc \
		--with-pgsql-include-dir=${LOCALBASE}/include/postgresql \
		--with-lua-include-dir=${MODLUA_INCL_DIR} \
		--with-lua-lib-dir=${LOCALBASE}/lib

# sync with net/h323plus
CONFIGURE_ARGS +=--disable-h46018
CONFIGURE_ARGS +=--disable-h46023

MAKE_ENV=	VERBOSE=1
MAKE_FLAGS=	PTLIB_LIBDIR=$$(pkg-config --variable libdir ptlib) \
		OH323_LIBDIR=${LOCALBASE}/lib \
		OBJDIR=.

pre-configure:
	sed -i 's,-llua,-llua${MODLUA_VERSION} -lm,g' ${WRKSRC}/configure

post-build:
	cd ${WRKSRC}/addpasswd && \
		${MAKE_ENV} PTLIBDIR=${LOCALBASE}/share/ptlib ${MAKE_PROGRAM} ${MAKE_FLAGS}

# gmake: *** No rule to make target 'install'.  Stop.
do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/gnugk \
		${PREFIX}/bin

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnugk/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnugk/
	${INSTALL_MAN} ${WRKSRC}/docs/gnugk.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/gnugk/
	cp ${WRKSRC}/etc/*.* ${PREFIX}/share/examples/gnugk/
	${INSTALL_PROGRAM} ${WRKSRC}/addpasswd/addpasswd \
		${PREFIX}/bin/addpasswd

.include <bsd.port.mk>
