# $OpenBSD: Makefile,v 1.31 2016/12/17 15:00:22 ajacoutot Exp $

COMMENT=		initial-setup firstboot-like tool

GNOME_PROJECT=		gnome-initial-setup
GNOME_VERSION=		3.22.1
REVISION=		0

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += EGL GL ICE SM X11 X11-xcb Xcomposite Xcursor Xdamage
WANTLIB += Xext Xfixes Xi Xinerama Xrandr Xrender Xt Xxf86vm accountsservice
WANTLIB += atk-1.0 atk-bridge-2.0 atspi c cairo cairo-gobject
WANTLIB += crack crypto dbus-1 dbus-glib-1 drm enchant
WANTLIB += epoxy estdc++ expat ffi fontconfig freetype gbm gcrypt
WANTLIB += gdk-3 gdk_pixbuf-2.0 gdm geoclue-2 geocode-glib gio-2.0
WANTLIB += glapi glib-2.0 gmodule-2.0 gmp gnome-desktop-3 gnutls
WANTLIB += goa-1.0 goa-backend-1.0 gobject-2.0 gpg-error graphite2
WANTLIB += gstapp-1.0 gstaudio-1.0 gstbase-1.0 gstfft-1.0 gstpbutils-1.0
WANTLIB += gstreamer-1.0 gsttag-1.0 gstvideo-1.0 gthread-2.0 gtk-3
WANTLIB += gweather-3 harfbuzz harfbuzz-icu hogweed hyphen ibus-1.0
WANTLIB += iconv icudata icui18n icuuc idn intl javascriptcoregtk-4.0
WANTLIB += jpeg json-glib-1.0 lzma m nettle notify orc-0.4 p11-kit
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png polkit-gobject-1 pthread-stubs pwquality
WANTLIB += rest-0.7 secret-1 soup-2.4 soup-gnome-2.4 sqlite3 stdc++
WANTLIB += tasn1 telepathy-glib webkit2gtk-4.0 webp xcb xcb-dri2
WANTLIB += xcb-glx xcb-render xcb-shm xcb-xfixes xml2 xslt z
WANTLIB += heimdal/lib/heimsqlite

MODULES=		devel/dconf \
			security/heimdal \
			x11/gnome

LIB_DEPENDS=		inputmethods/ibus \
			security/libpwquality \
			x11/gnome/desktop \
			x11/gnome/gdm \
			x11/gnome/libgweather \
			x11/gnome/online-accounts

BUILD_DEPENDS=		geo/geoclue2
RUN_DEPENDS=		geo/geoclue2

# gnome-welcome-tour
RUN_DEPENDS +=		x11/gnome/getting-started-docs

# share/polkit-1/rules.d/20-gnome-initial-setup.rules
RUN_DEPENDS +=		sysutils/polkit

# polkit(8) almost always needs to know the "active" session
RUN_DEPENDS +=		sysutils/consolekit

AUTOCONF_VERSION=	2.69
CONFIGURE_STYLE=	autoconf

FAKE_FLAGS=		sysconfdir=${PREFIX}/share/examples/gnome-initial-setup

.include <bsd.port.mk>
