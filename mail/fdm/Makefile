# $OpenBSD: Makefile,v 1.21 2016/03/08 17:30:43 edd Exp $

COMMENT=	fetch, filter and deliver mail

V=		1.9
REVISION =	0
DISTNAME=	fdm-$V
CATEGORIES=	mail

MAINTAINER=	Nicholas Marriott <nicm@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB= c crypto ssl z tdb>=3.0

MASTER_SITES=	https://github.com/nicm/fdm/releases/download/$V/

LIB_DEPENDS +=	databases/tdb>=1.2.7

CONFIGURE_STYLE =	gnu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fdm
	${INSTALL_SCRIPT} ${WRKSRC}/fdm-sanitize ${PREFIX}/share/fdm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fdm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fdm
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${PREFIX}/share/doc/fdm
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fdm
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/fdm

.include <bsd.port.mk>
