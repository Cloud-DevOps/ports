# $OpenBSD: Makefile,v 1.32 2016/08/20 12:39:57 ajacoutot Exp $

PKG_ARCH=		*

COMMENT=		weather application for GNOME

GNOME_PROJECT=		gnome-weather
GNOME_VERSION=		3.20.2

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes

MODULES=		devel/dconf \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		geo/geoclue2 \
			x11/gnome/gjs \
			x11/gnome/libgweather \
			x11/gtk+3

RUN_DEPENDS=		geo/geoclue2 \
			x11/gnome/gjs \
			x11/gnome/libgweather \
			x11/gtk+3

MODPY_BUILDDEP=		No
MODPY_RUNDEP=		No
MODPY_ADJ_FILES=	tests/world_view.py

MODGNOME_TOOLS=		desktop-file-utils gobject-introspection \
			gtk-update-icon-cache

TEST_DEPENDS=		${MODPY_RUN_DEPENDS}

.include <bsd.port.mk>
