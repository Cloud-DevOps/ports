# $OpenBSD: Makefile,v 1.13 2016/12/30 23:15:46 jca Exp $

COMMENT=	S10sh - a Canon PowerShot digital camera driver

DISTNAME=	s10sh-0.2.0
REVISION =	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.kyuzz.org/antirez/s10sh-src/

HOMEPAGE=	http://www.kyuzz.org/antirez/s10sh.html

MAINTAINER=	Markus Friedl <markus@openbsd.org>

# GPL
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	readline c termcap usb pthread

DOCDIR=		${PREFIX}/share/doc/s10sh

LIB_DEPENDS=	devel/libusb-compat

CONFIGURE_STYLE= simple

NO_TEST=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/s10sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/{README,Protocol} ${DOCDIR}

.include <bsd.port.mk>
