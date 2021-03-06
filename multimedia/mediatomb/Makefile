# $OpenBSD: Makefile,v 1.22 2016/11/04 11:35:19 sthen Exp $

COMMENT =	UPnP media server

VER =		0.12.1
DISTNAME =	mediatomb-${VER}
REVISION =	14

CATEGORIES =	multimedia

HOMEPAGE =	http://mediatomb.cc/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += avformat avutil c crypto curl exif expat ffmpegthumbnailer m
WANTLIB += magic mozjs mp4v2 nghttp2 pthread sqlite3 ssl stdc++ tag z

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=mediatomb/}

MODULES =	devel/gettext

LIB_DEPENDS =	audio/taglib \
		databases/sqlite3 \
		devel/libmagic \
		graphics/ffmpeg>=20121026 \
		graphics/ffmpegthumbnailer \
		graphics/libexif \
		lang/spidermonkey>=1.9v0 \
		net/curl \
		multimedia/libmp4v2

CONFIGURE_STYLE =	autoconf
AUTOCONF_VERSION =	2.63
CONFIGURE_ARGS =	--disable-inotify \
			--disable-lastfmlib \
			--disable-mysql
# Add "-I${WRKSRC}/src" to make mediatomb find its own dictionary.h first.
CONFIGURE_ENV =		CPPFLAGS="-I${WRKSRC}/src -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			ac_cv_header_execinfo_h=no \
			ac_cv_header_lwres_netdb_h=no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mediatomb/
	${SUBST_DATA} ${FILESDIR}/config.xml \
		${PREFIX}/share/examples/mediatomb/config.xml

.include <bsd.port.mk>
