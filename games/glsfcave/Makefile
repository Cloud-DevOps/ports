# $OpenBSD: Makefile,v 1.9 2015/11/05 19:08:58 jca Exp $

COMMENT=	control a ribbon to avoid hitting walls

V=		1.0
DISTNAME= 	glsfcave-$V-mitl
PKGNAME=	glsfcave-$V
REVISION =	4
CATEGORIES=	games
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://user.ecc.u-tokyo.ac.jp/~s081016/glsfcave/
MASTER_SITES=	${HOMEPAGE}

# MIT
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += GL GLU X11 Xext Xi Xmu c glut>=4 m pthread pthread-stubs xcb

LIB_DEPENDS=	graphics/freeglut

WRKDIST=	${WRKDIR}/glsfcave

ALL_TARGET=	glsfcave

CFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include
MAKE_ENV+=	LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

NO_TEST=	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glsfcave ${PREFIX}/bin

.include <bsd.port.mk>
