# $OpenBSD: Makefile,v 1.48 2016/10/12 10:07:45 ajacoutot Exp $

COMMENT=		GTK+ subtitles editor

V=			0.53.0
DISTNAME=		subtitleeditor-${V}
REVISION=		0

CATEGORIES=		graphics editors

SHARED_LIBS +=  subtitleeditor 0.0     # .0.0

HOMEPAGE=		http://home.gna.org/subtitleeditor/

# GPLv3
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE SM X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender atk-1.0 atk-bridge-2.0 atkmm-1.6
WANTLIB += atspi c cairo cairo-gobject cairomm-1.0 dbus-1 enchant
WANTLIB += epoxy expat ffi fontconfig freetype gdk-3 gdk_pixbuf-2.0
WANTLIB += gdkmm-3.0 gio-2.0 giomm-2.4 glib-2.0 glibmm-2.4 gmodule-2.0
WANTLIB += gobject-2.0 graphite2 gstallocators-1.0 gstapp-1.0
WANTLIB += gstaudio-1.0 gstbase-1.0 gstcheck-1.0 gstcontroller-1.0
WANTLIB += gstfft-1.0 gstnet-1.0 gstpbutils-1.0 gstreamer-1.0
WANTLIB += gstreamermm-1.0 gstriff-1.0 gstrtp-1.0 gstrtsp-1.0
WANTLIB += gstsdp-1.0 gsttag-1.0 gstvideo-1.0 gthread-2.0 gtk-3
WANTLIB += gtkmm-3.0 harfbuzz iconv intl lzma m orc-0.4 pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pangomm-1.4 pcre pixman-1
WANTLIB += png pthread pthread-stubs sigc-2.0 stdc++ xcb xcb-render
WANTLIB += xcb-shm xml++-2.6 xml2 z

MASTER_SITES=		http://download.gna.org/subtitleeditor/${V:R}/

BUILD_DEPENDS=		devel/iso-codes

LIB_DEPENDS=		multimedia/gstreamer1/mm \
			multimedia/gstreamer1/plugins-base \
			textproc/enchant \
			textproc/libxml++ \
			x11/gtk3mm

RUN_DEPENDS=		devel/desktop-file-utils \
			devel/iso-codes \
			multimedia/gstreamer1/plugins-good \
			multimedia/gstreamer1/plugins-libav \
			x11/gtk+3,-guic

MODULES=		textproc/intltool

# c++11
MODULES +=		gcc4
MODGCC4_ARCHS=		*
MODGCC4_LANGS=		c++

USE_GMAKE=		Yes

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			CXXFLAGS="-std=c++11" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=		--with-default-video-sink=autovideosink \
			--with-default-audio-sink=autoaudiosink \
			--enable-ccache=no

post-install:
	rm ${PREFIX}/lib/subtitleeditor/plugins/*/*.{a,la}

.include <bsd.port.mk>
