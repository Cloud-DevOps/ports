# $OpenBSD: Makefile,v 1.161 2016/12/22 21:26:20 sthen Exp $

COMMENT=		image processing tools

VER=			6.9.7
DASHVER=		0
DISTNAME=		ImageMagick-${VER}-${DASHVER}
PKGNAME=		ImageMagick-${VER}.${DASHVER}
PORTROACH=		site:https://www.imagemagick.org/download/ limit:6.*
EXTRACT_SUFX=		.tar.xz

SHARED_LIBS +=	MagickCore-6.Q16     3.0      # 3.0
SHARED_LIBS +=	MagickWand-6.Q16     3.0      # 3.0
SHARED_LIBS +=	Magick++-6.Q16       5.0      # 7.0

CATEGORIES=		graphics

HOMEPAGE=		https://www.imagemagick.org/

MAINTAINER=		Stuart Henderson <sthen@openbsd.org>

MASTER_SITES=		https://www.imagemagick.org/download/releases/ \
			ftp://sunsite.icm.edu.pl/packages/ImageMagick/

# http://www.imagemagick.org/script/license.php
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += ICE SM X11 Xau Xdmcp Xext Xt bz2 c djvulibre expat
WANTLIB += fftw3 fontconfig freetype iconv jbig jpeg lcms2 lzma m
WANTLIB += openjp2 perl png pthread pthread-stubs stdc++ tiff
WANTLIB += webp xcb xml2 z

LIB_DEPENDS =		archivers/bzip2 \
			archivers/xz \
			converters/libiconv \
			graphics/djvulibre \
			graphics/jbigkit \
			graphics/png \
			graphics/tiff \
			graphics/lcms2 \
			graphics/libwebp \
			graphics/openjp2 \
			math/fftw3 \
			textproc/libxml
BUILD_DEPENDS =		print/ghostscript/gnu

ALL_TARGET=		all perl-build

CONFIGURE_STYLE=	autoconf
LIBTOOL_FLAGS=		--tag=disable-static
AUTOCONF_VERSION=	2.69
USE_GMAKE=		Yes
CONFIGURE_ARGS+=	--without-gcc-arch \
			--with-gs-font-dir=${LOCALBASE}/share/fonts/ghostscript \
			--with-perl \
			--with-perl-options='MAKE=${MAKE_PROGRAM}' \
			--with-quantum-depth=16 \
			--without-dps \
			--without-fpx \
			--without-gvc \
			--without-lqr \
			--without-openexr \
			--without-pango \
			--without-rsvg \
			--without-wmf \
			--disable-openmp

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include/libxml2 -I${LOCALBASE}/include" \
			LDFLAGS="-L${WRKBUILD}/magick/.libs -L${WRKBUILD}/wand/.libs -L${LOCALBASE}/lib" \
			ac_cv_path_LaunchDelegate=no

pre-configure:
	cd ${WRKSRC}; ${SUBST_CMD} $$(find . -name '*.pc.in')

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ImageMagick
.for i in coder.xml colors.xml delegates.xml log.xml magic.xml \
	mime.xml policy.xml quantization-table.xml \
	thresholds.xml type-dejavu.xml type-ghostscript.xml \
	type-windows.xml type.xml
	${INSTALL_DATA} ${WRKSRC}/config/$i ${PREFIX}/share/examples/ImageMagick
.endfor

.include <bsd.port.mk>
