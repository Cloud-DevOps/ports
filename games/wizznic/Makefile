# $OpenBSD: Makefile,v 1.2 2016/01/23 05:01:38 bentley Exp $

COMMENT =		brick-matching puzzle game

V =			0.9.9
DISTNAME =		wizznic-${V}-src
PKGNAME =		wizznic-${V}
REVISION =		0

CATEGORIES =		games

HOMEPAGE =		http://wizznic.org/

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL SDL SDL_image SDL_mixer c m png pthread z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=wizznic/}
EXTRACT_SUFX =		.tar.bz2

LIB_DEPENDS =		devel/sdl-image \
			devel/sdl-mixer
RUN_DEPENDS =		net/wget

MAKE_FLAGS =		DATADIR=${PREFIX}/share/wizznic/ \
			BINDIR=${PREFIX}/bin \
			CC="${CC}" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			STRIP=true

USE_GMAKE =		Yes

NO_TEST =		Yes

ALL_TARGET =		wizznic

.include <bsd.port.mk>
