# $OpenBSD: Makefile,v 1.15 2016/03/11 19:59:15 naddy Exp $

COMMENT =	elliptic curve method (ECM) factorization library

DISTNAME =	ecm-6.4.4
SHARED_LIBS =	ecm	0.1
CATEGORIES =	math

HOMEPAGE =	http://gforge.inria.fr/projects/ecm/

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv3 / LGLPv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c m gmp

MASTER_SITES =		http://gforge.inria.fr/frs/download.php/32159/

LIB_DEPENDS =		devel/gmp

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-install:
		${INSTALL_MAN} ${WRKSRC}/ecm.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
