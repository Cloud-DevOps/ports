# $OpenBSD: Makefile,v 1.18 2017/01/31 09:58:35 sthen Exp $

COMMENT=	library to adjust for photographic lens characteristics
DISTNAME=	lensfun-0.3.2

SHARED_LIBS=	lensfun	2.0

CATEGORIES=	graphics
HOMEPAGE=	http://lensfun.sourceforge.net/

# library LGPLv3, lens db CC-BY-SA, build infrastructure/applications GPLv3
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c glib-2.0 m png stdc++ z

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lensfun/}

MODULES=		devel/cmake

LIB_DEPENDS=		devel/glib2 \
			graphics/png

CONFIGURE_ARGS=		-DBUILD_DOC=No \
			-DBUILD_LENSTOOL=Yes \
			-DBUILD_TESTS=Yes

DOC_DIR=		${PREFIX}/share/doc/lensfun

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*-3.0.txt ${DOC_DIR}

.include <bsd.port.mk>
