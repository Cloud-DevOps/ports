# $OpenBSD: Makefile,v 1.45 2017/01/17 14:46:19 gonzalo Exp $

BROKEN-alpha =	MetalinkParserStateV4Impl.cc:219:1: internal compiler error: Segmentation fault

COMMENT =		lightweight multi-protocol & multi-source download utility
V =			1.31.0
DISTNAME =		aria2-${V}
CATEGORIES =		www
HOMEPAGE =		https://aria2.github.io/

MAINTAINER =		Gonzalo L. R. <gonzalo@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		https://github.com/aria2/aria2/releases/download/release-${V}/

MODULES =		gcc4
MODGCC4_ARCHS =		*
MODGCC4_LANGS =		c c++

LIB_DEPENDS =		databases/sqlite3 \
			devel/gettext \
			net/libcares \
			security/libssh2

BUILD_DEPENDS =		devel/m4 \
			devel/cppunit

TEST_DEPENDS =		${BUILD_DEPENDS}

WANTLIB += c cares crypto expat iconv intl m pthread sqlite3 ssh2 ssl z

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS +=	--disable-rpath \
			--with-sqlite3 \
			--with-libz \
			--with-libcares \
			--with-libexpat \
			--with-libssh2 \
			--with-openssl \
			--without-gnutls \
			--without-libxml2

.include <bsd.port.mk>
