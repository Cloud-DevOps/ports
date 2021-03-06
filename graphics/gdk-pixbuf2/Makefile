# $OpenBSD: Makefile,v 1.62 2017/01/16 19:20:02 ajacoutot Exp $

COMMENT=		graphic library for gtk+2

GNOME_PROJECT=		gdk-pixbuf
GNOME_VERSION=		2.36.4

CATEGORIES=		graphics

SHARED_LIBS +=  gdk_pixbuf-2.0       3200.1   # 3600.4
SHARED_LIBS +=  gdk_pixbuf_xlib-2.0  3200.0   # 3600.4

HOMEPAGE=		http://www.gtk.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 c ffi gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0
WANTLIB += iconv intl jasper jpeg m pcre png pthread tiff xcb
WANTLIB += z

MODULES=		x11/gnome

LIB_DEPENDS=		devel/glib2 \
			graphics/jasper \
			graphics/png \
			graphics/tiff

# configure: detect and set GDK_PIXBUF_USE_GIO_MIME
# (g_content_type_from_mime_type requires shared-mime-info)
BUILD_DEPENDS +=	misc/shared-mime-info

MODGNOME_TOOLS += gobject-introspection shared-mime-info

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-libjasper \
			--with-x11

TEST_DEPENDS=		${BASE_PKGPATH}=${GNOME_VERSION}

post-install:
	rm ${PREFIX}/lib/gdk-pixbuf-2.0/2.10.0/loaders/*.{a,la}

.include <bsd.port.mk>
