# $OpenBSD: Makefile,v 1.36 2016/11/21 09:27:17 ajacoutot Exp $

COMMENT=		digital camera command-line interface

VERSION=		2.5.11
DISTNAME=		gphoto2-${VERSION}
PKGNAME=		gphoto-${VERSION}

CATEGORIES=		graphics

HOMEPAGE=		http://gphoto.sourceforge.net/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 aa c cdk exif gphoto2 gphoto2_port iconv intl jpeg
WANTLIB += ltdl m ncurses popt pthread readline xcb

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gphoto/}

LIB_DEPENDS=		devel/cdk \
			devel/popt \
			graphics/aalib \
			graphics/libgphoto2

CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			POPT_CFLAGS="-I${LOCALBASE}/include" \
			POPT_LIBS="-I${LOCALBASE}/lib -lpopt"

# checking how to link with libintl... /usr/local/lib/libintl.a ...
# (we want -lintl)
MAKE_FLAGS=		INTLLIBS='$$(LTLIBINTL)'

.include <bsd.port.mk>
