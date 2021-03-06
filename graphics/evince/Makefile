# $OpenBSD: Makefile,v 1.142 2016/12/17 16:54:25 zhuk Exp $

COMMENT=		GNOME document viewer

GNOME_PROJECT=		evince
GNOME_VERSION=		3.22.1
REVISION=		0

MAJ_V=			3.0
SUBST_VARS=		MAJ_V

SHARED_LIBS +=  evdocument3               0.2 # 4.0
SHARED_LIBS +=  evview3                   0.0 # 3.0

CATEGORIES=		graphics print

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE SM X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender atk-1.0 atk-bridge-2.0 atspi
WANTLIB += avahi-common c cairo cairo-gobject dbus-1 expat ffi
WANTLIB += fontconfig freetype gcrypt gdk-3 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gmodule-2.0 gobject-2.0 gpg-error graphite2
WANTLIB += gs gthread-2.0 gtk-3 harfbuzz jpeg lcms2 lzma lzo2 m openjp2
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre pixman-1
WANTLIB += png poppler poppler-glib pthread pthread-stubs secret-1
WANTLIB += spectre stdc++ tiff xcb xcb-render xcb-shm xml2 z
WANTLIB += gmp hogweed nettle p11-kit tasn1 epoxy iconv intl lz4
WANTLIB += gstbase-1.0 gstreamer-1.0 gstvideo-1.0 orc-0.4 idn crypto

MODULES=		devel/dconf \
			x11/gnome

MODGNOME_TOOLS +=	desktop-file-utils gobject-introspection
MODGNOME_TOOLS +=	gtk-update-icon-cache shared-mime-info

BUILD_DEPENDS=		devel/gsettings-desktop-schemas

LIB_DEPENDS=		multimedia/gstreamer1/plugins-base \
			print/libspectre \
			print/poppler \
			x11/gnome/libsecret \
			x11/gtk+3

RUN_DEPENDS=		archivers/unrar \
			archivers/unzip \
			devel/gsettings-desktop-schemas \
			print/ghostscript/gnu

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

# modern browsers can already display PDF
CONFIGURE_ARGS +=	--disable-browser-plugin

# Not much point in installing systemd service files
FAKE_FLAGS +=		systemd_user_in_files=""

FLAVORS=		light
FLAVOR?=

.if ${FLAVOR:Mlight}
BUILD_DEPENDS +=	textproc/itstool
CONFIGURE_ARGS +=	--disable-dbus \
			--disable-libgnome-desktop \
			--disable-nautilus \
			--disable-thumbnailer \
			--disable-djvu \
			--disable-dvi \
			--disable-comics \
			--disable-xps
.else
MODGNOME_TOOLS +=	yelp
LIB_DEPENDS +=		graphics/djvulibre \
			graphics/libgxps \
			print/texlive/base \
			x11/gnome/nautilus
WANTLIB += archive bz2 djvulibre gnome-desktop-3 gxps kpathsea
WANTLIB += nautilus-extension gnome-autoar-0
.endif

post-install:
.if ! ${FLAVOR:Mlight}
	rm ${PREFIX}/lib/nautilus/extensions-${MAJ_V}/*.{a,la}
.endif
	rm ${PREFIX}/lib/evince/4/backends/*.{a,la}

.include <bsd.port.mk>
