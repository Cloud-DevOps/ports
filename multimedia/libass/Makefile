# $OpenBSD: Makefile,v 1.19 2017/01/22 02:51:32 ajacoutot Exp $

COMMENT=	portable ASS/SSA subtitle renderer

VER=		0.13.6
DISTNAME=	libass-${VER}
CATEGORIES=	multimedia devel
MASTER_SITES=	https://github.com/libass/libass/releases/download/${VER}/
EXTRACT_SUFX=	.tar.xz

SHARED_LIBS=	ass	3.0

HOMEPAGE=	https://github.com/libass/libass

MAINTAINER=	Brad Smith <brad@comstyle.com>

# ISC
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	expat fontconfig freetype fribidi iconv m pthread-stubs z

LIB_DEPENDS=	converters/libiconv \
		devel/fribidi

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS=	--disable-asm \
		--disable-harfbuzz
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
