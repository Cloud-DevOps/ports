# $OpenBSD: Makefile,v 1.14 2016/09/07 20:29:52 ajacoutot Exp $

# XXX check if still needed at next update
CXXFLAGS +=		-std=c++11

COMMENT =		C++ bindings for gtkglext

DISTNAME =		gtkglextmm-1.2.0
REVISION =		10

SHARED_LIBS +=		gdkglextmm-x11-1.2        0.0 # 0.0
SHARED_LIBS +=		gtkglextmm-x11-1.2        0.0 # 0.0

CATEGORIES =		x11

HOMEPAGE =		http://projects.gnome.org/gtkglext/

# LGPLv2.1+
PERMIT_PACKAGE_CDROM =		Yes

WANTLIB += GL GLU ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xmu Xrandr Xrender Xt Xxf86vm
WANTLIB += atk-1.0 atkmm-1.6 cairo cairomm-1.0 drm expat ffi fontconfig
WANTLIB += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gdkglext-x11-1.0
WANTLIB += gdkmm-2.4 gio-2.0 giomm-2.4 glapi glib-2.0 glibmm-2.4
WANTLIB += gmodule-2.0 gobject-2.0 graphite2 gthread-2.0 gtk-x11-2.0
WANTLIB += gtkglext-x11-1.0 gtkmm-2.4 harfbuzz iconv intl m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pangomm-1.4 pangox-1.0
WANTLIB += pcre pixman-1 png pthread pthread-stubs sigc-2.0 xcb
WANTLIB += xcb-dri2 xcb-glx xcb-render xcb-shm z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=gtkglext/}

# c++11
MODULES +=		gcc4
MODGCC4_ARCHS=		*
MODGCC4_LANGS=		c++

LIB_DEPENDS =		x11/gtk2mm \
			x11/gtkglext

USE_GMAKE =		Yes
CONFIGURE_STYLE =	gnu

.include <bsd.port.mk>
