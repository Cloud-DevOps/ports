# $OpenBSD: Makefile,v 1.19 2016/11/03 16:20:41 landry Exp $

COMMENT=	Xfce4 task manager and system monitor

XFCE_VERSION=	1.1.0
XFCE_GOODIE=	xfce4-taskmanager
REVISION =	0

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MODULES=	x11/xfce4
MODXFCE_DESKTOP_FILE=	Yes

LIB_DEPENDS=	x11/gtk+2 \
		devel/libwnck
#CONFIGURE_ARGS+=--enable-gtk3

WANTLIB += X11 X11-xcb XRes Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender
WANTLIB += atk-1.0 c cairo expat ffi fontconfig freetype gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gthread-2.0 gtk-x11-2.0 m pango-1.0 pangocairo-1.0
WANTLIB += pangoft2-1.0 pcre pixman-1 png pthread pthread-stubs
WANTLIB += startup-notification-1 wnck-1 xcb xcb-util xcb-render
WANTLIB += xcb-shm z harfbuzz graphite2 iconv intl

.include <bsd.port.mk>
