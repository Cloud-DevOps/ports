# $OpenBSD: Makefile,v 1.5 2016/09/01 16:50:56 pascal Exp $

V =		0.7.5
COMMENT =	ridiculous shoot-em-up game
DISTNAME =	mars_source_${V}
PKGNAME =	mars-${V}
CATEGORIES =	games x11
REVISION =	3

HOMEPAGE =	http://mars-game.sourceforge.net/

# GPLv3+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL GLU Xrandr c fribidi m pthread sfml-audio sfml-graphics
WANTLIB += sfml-system sfml-window stdc++ tag

# Not using the GH_* variables on purpose. The tarball was generated
# separately. Will update to use GH_* next time M.A.R.S. is updated.
MASTER_SITES =	https://github.com/downloads/thelaui/M.A.R.S./

MODULES =	devel/cmake

LIB_DEPENDS =	audio/taglib \
		devel/fribidi \
		multimedia/sfml

RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gtk+3,-guic

NO_TEST =	Yes
WRKDIST =	${WRKDIR}/mars-game

.include <bsd.port.mk>
