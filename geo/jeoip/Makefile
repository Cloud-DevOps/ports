# $OpenBSD: Makefile,v 1.26 2016/03/06 18:50:43 ajacoutot Exp $

COMMENT=		Java interface to GeoIP database
DISTNAME=		jeoip-0.5
REVISION=		14
CATEGORIES=		geo net
PKG_ARCH=		*

HOMEPAGE=		http://www.darwinsys.com/freeware/jeoip.jsp

MAINTAINER=		Ian Darwin <ian@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		http://www.darwinsys.com/freeware/

MODULES=		java
MODJAVA_VER=		1.6+
MODJAVA_JRERUN=		Yes
MODJAVA_BUILD=		ant
MODJAVA_BUILD_TARGET_NAME =	jar docs

BUILD_DEPENDS=		java/junit
TEST_DEPENDS=		net/GeoIP,-db \
			java/junit
RUN_DEPENDS=		net/GeoIP,-db \
 			java/javaPathHelper
MAKE_ENV=		CLASSPATH=${LOCALBASE}/share/java/classes/junit/junit.jar

WRKDIST=		${WRKDIR}/jeoip

do-install:
	${INSTALL_DATA_DIR} ${MODJAVA_JAR_DIR}
	${INSTALL_DATA} ${WRKDIST}/jeoip.jar ${MODJAVA_JAR_DIR}
	${INSTALL_SCRIPT} ${WRKDIST}/unix/jeoip ${PREFIX}/bin

do-test:
	@cd ${WRKBUILD} && ${SETENV} ${MAKE_ENV} ant regress

.include <bsd.port.mk>
