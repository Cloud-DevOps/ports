# $OpenBSD: Makefile,v 1.6 2016/09/13 15:29:01 naddy Exp $

COMMENT =		interpreter for some LucasArts 3D games

V =			0.2.1
DISTNAME =		residualvm-${V}-sources
PKGNAME =		residualvm-${V}
REVISION =		1

CATEGORIES =		games

HOMEPAGE =		http://residualvm.org/

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL SDL c freetype iconv jpeg m mad mpeg2 ogg png pthread stdc++
WANTLIB += theoradec vorbis vorbisfile z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=residualvm/}

LIB_DEPENDS =		audio/libmad \
			audio/libvorbis \
			converters/libiconv \
			devel/sdl \
			graphics/jpeg \
			graphics/libmpeg2 \
			graphics/png \
			multimedia/libtheora
RUN_DEPENDS =		devel/desktop-file-utils \
			x11/gtk+3,-guic

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
CONFIGURE_STYLE =	simple
CONFIGURE_ARGS +=	--enable-verbose-build \
			--mandir=${PREFIX}/man
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

NO_TEST =		Yes

WRKDIST =		${WRKDIR}/residualvm-${V}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/dists/residualvm.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
