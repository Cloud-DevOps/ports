# $OpenBSD: Makefile,v 1.10 2016/12/31 12:40:39 sthen Exp $

V =			2.13
COMMENT =		download videos from YLE Areena
DISTNAME =		aajanki-yle-$V
PKGNAME =		yle-dl-$V
CATEGORIES =		multimedia

HOMEPAGE =		http://aajanki.github.io/yle-dl/
MAINTAINER =		Timo Myyra <timo.myyra@wickedbsd.net>

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		https://github.com/aajanki/yle-dl/tarball/${V}/

MODULES =		lang/python \
			lang/php

RUN_DEPENDS =		net/rtmpdump \
			security/py-crypto \
			lang/php/${MODPHP_VERSION},-curl \
			lang/php/${MODPHP_VERSION},-mcrypt
			
NO_TEST =		Yes

WRKDIST =		${WRKDIR}/aajanki-yle-dl-da3cc03

MODPY_SETUPTOOLS =	Yes
MODPY_ADJ_FILES =	yle-dl

SUBST_VARS +=		MODPHP_BIN

do-install:
	${SUBST_PROGRAM} ${WRKSRC}/yle-dl ${PREFIX}/bin/yle-dl
	${INSTALL_DATA_DIR} ${PREFIX}/share/yle-dl
	${INSTALL_DATA} ${WRKSRC}/AdobeHDS.php ${PREFIX}/share/yle-dl
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/yle-dl
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README.fi \
		${WRKSRC}/README.md ${PREFIX}/share/doc/yle-dl

.include <bsd.port.mk>
