# $OpenBSD: Makefile,v 1.21 2016/04/09 20:14:49 naddy Exp $

COMMENT =	pager for the Blackbox window manager

DISTNAME =	bbpager-0.4.7
REVISION=	2

CATEGORIES =	x11
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=bbtools/}

HOMEPAGE =	http://bbtools.sourceforge.net/

MAINTAINER =	Josh Rivel <josh@rivels.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =		Yes

BUILD_DEPENDS = x11/blackbox

LIB_DEPENDS =	converters/libiconv

WANTLIB =	ICE SM X11 Xau Xdmcp Xext Xft Xrender c expat fontconfig \
		freetype iconv m stdc++ z pthread-stubs xcb

CONFIGURE_STYLE = gnu

.ifdef DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.mk>
