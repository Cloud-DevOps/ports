# $OpenBSD: Makefile,v 1.34 2016/04/28 08:16:28 ajacoutot Exp $

COMMENT=		music management and playback application for GNOME

GNOME_VERSION=		2.6.2
GNOME_PROJECT=		banshee
REVISION=		8

CATEGORIES=		audio multimedia

HOMEPAGE=		http://banshee.fm/

# MIT/X11
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += EGL GL ICE SM X11 Xcomposite Xcursor Xdamage Xext Xfixes
WANTLIB += X11-xcb drm glapi xcb-dri2 xcb-glx xcb-shape xcb-xfixes
WANTLIB += Xi Xinerama Xrandr Xrender Xt Xxf86vm atk-1.0 cairo
WANTLIB += enchant expat ffi fontconfig freetype gbm gcrypt gdk-x11-2.0
WANTLIB += gdk_pixbuf-2.0 gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += gpg-error graphite2 gstapp-1.0 gstaudio-1.0 gstbase-0.10
WANTLIB += gstbase-1.0 gstcdda-0.10 gstcontroller-0.10 gstdataprotocol-0.10
WANTLIB += gstfft-0.10 gstfft-1.0 gstinterfaces-0.10 gstpbutils-0.10
WANTLIB += gstpbutils-1.0 gstreamer-0.10 gstreamer-1.0 gsttag-0.10
WANTLIB += gsttag-1.0 gstvideo-0.10 gstvideo-1.0 gthread-2.0 gtk-x11-2.0
WANTLIB += harfbuzz harfbuzz-icu icudata icui18n icuuc javascriptcoregtk-1.0
WANTLIB += jpeg lzma m orc-0.4 pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += pcre pixman-1 png pthread pthread-stubs secret-1 soup-2.4
WANTLIB += soup-gnome-2.4 sqlite3 stdc++ webkitgtk-1.0 webp xcb
WANTLIB += xcb-render xcb-shm xml2 xslt z iconv intl

MODULES=		lang/mono \
			x11/gnome

MODMONO_GMCS_COMPAT=	Yes

COMMON_DEPENDS=		audio/mono-taglib \
			devel/dbus-sharp-glib \
			devel/mono-addins \
			devel/mono-gdata \
			devel/mono-notify \
			net/mono-zeroconf \
			shells/bash

BUILD_DEPENDS=		${COMMON_DEPENDS} \
			devel/libmtp

RUN_DEPENDS=		${COMMON_DEPENDS}

RUN_DEPENDS +=		multimedia/gstreamer-0.10/plugins-good #libgstgconfelements
RUN_DEPENDS +=		multimedia/gstreamer-0.10/plugins-bad #bpmdetect (soundtouch)
RUN_DEPENDS +=		multimedia/gstreamer-0.10/plugins-ffmpeg #mp3 support

LIB_DEPENDS=		multimedia/gstreamer-0.10/plugins-base \
			www/webkit

MODGNOME_TOOLS=		desktop-file-utils gtk-update-icon-cache shared-mime-info yelp

CONFIGURE_ARGS=		--with-vendor-build-id="OpenBSD Ports" \
			--disable-shave

# requires gtk-sharp-beans (not ported)
CONFIGURE_ARGS +=	--disable-gio-hardware

# requires libgpod-sharp (not ported)
CONFIGURE_ARGS +=	--disable-appledevice

# requires karma-sharp (not ported)
CONFIGURE_ARGS +=	--disable-karma

# requires gio-sharp (not ported)
CONFIGURE_ARGS +=	--disable-gio

# requires boo (not ported)
CONFIGURE_ARGS +=	--disable-boo

DLLMAP_FILES=		src/Hyena/Hyena/Hyena.dll.config \
			src/Hyena/Hyena.Gui/Hyena.Gui.dll.config \
			src/Libraries/Mtp/Mtp.dll.config.in \
			src/Libraries/Mtp/Mtp.dll.config \
			src/Core/Banshee.Core/Banshee.Core.dll.config \
			src/Core/Banshee.Services/Banshee.Services.dll.config \
			src/Core/Banshee.ThickClient/Banshee.ThickClient.dll.config \
			src/Core/Banshee.Widgets/Banshee.Widgets.dll.config \
			src/Extensions/Banshee.NotificationArea/Banshee.NotificationArea.dll.config \
			src/Extensions/Banshee.MeeGo/Banshee.MeeGo.dll.config \
			src/Backends/Banshee.GStreamer/Banshee.GStreamer.dll.config \
			src/Backends/Banshee.Unix/Banshee.Unix.dll.config

# XXX the theme-icons target uses INSTALL_DATA during build which will
# fail when running as a non priviledge user (install -o/-g)
.if !target(do-install)
MAKE_FLAGS +=		INSTALL_DATA='/usr/bin/install -c -m 444'
.endif

post-patch:
	find ${WRKSRC} -name Makefile.in -exec sed -i \
		's|-r:Mono.Cairo|-r:${PREFIX}/lib/mono/gac/Mono.Cairo/4.0.0.0__0738eb9f132ed756/Mono.Cairo.dll|' {} \;

post-install:
	rm ${PREFIX}/lib/banshee/Backends/*.{a,la}
	rm ${PREFIX}/lib/banshee/*.{a,la}

.include <bsd.port.mk>
