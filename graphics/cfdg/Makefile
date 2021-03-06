# $OpenBSD: Makefile,v 1.11 2015/12/02 18:20:27 jasper Exp $

COMMENT =	Context Free Design Grammar

VERSION =	3.0.9
DISTNAME =	ContextFreeSource${VERSION}
PKGNAME =	cfdg-${VERSION}

CATEGORIES =	graphics

HOMEPAGE =	http://www.contextfreeart.org/

MAINTAINER =	jared r r spiegel <jrrs@ice-nine.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	http://www.contextfreeart.org/download/
EXTRACT_SUFX =	.tgz

WANTLIB =	c m png z

BUILD_DEPENDS =	devel/bison

LIB_DEPENDS =	graphics/png

MODULES =	gcc4
MODGCC4_LANGS =	c c++
MODGCC4_ARCHS =	*

USE_GMAKE =	Yes

WRKDIST =	${WRKDIR}/context-free-${VERSION}

MAKE_ENV +=	CPPFLAGS="${CFLAGS}"

EXAMPLEDIR =	${PREFIX}/share/examples/cfdg

# FlexLexer.h is installed into /usr/include/g++, but we cannot set that
# include path since we use g++ from ports.
post-extract:
	cp /usr/include/g++/FlexLexer.h ${WRKSRC}/src-unix/

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/cfdg ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}/input
	${INSTALL_DATA} ${WRKSRC}/README ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/input/*.cfdg ${EXAMPLEDIR}/input

.include <bsd.port.mk>
