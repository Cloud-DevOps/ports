# $OpenBSD: Makefile,v 1.5 2016/12/28 07:55:43 zhuk Exp $

CATEGORIES =	graphics print
COMMENT =	Qt-based barcode abstraction library
VERSION =	1.0
DISTNAME =	prison-${VERSION}
HOMEPAGE =	https://api.kde.org/frameworks/prison/html/
REVISION =	3

SHARED_LIBS =	prison			0.0

MASTER_SITES =	${MASTER_SITE_KDE:=stable/prison/${VERSION}/src/}
EXTRACT_SUFX =	.tar.gz

# BSDL
PERMIT_PACKAGE_CDROM =	Yes

MODULES =	x11/kde4
MODKDE4_USE =

LIB_DEPENDS =	graphics/libdmtx \
		graphics/libqrencode

WANTLIB =	dmtx lib/qt4/QtGui m qrencode

post-patch:
	${SUBST_CMD} ${WRKSRC}/lib/prison/PrisonConfig.cmake.in

.include <bsd.port.mk>
