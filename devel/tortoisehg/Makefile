# $OpenBSD: Makefile,v 1.22 2016/06/14 09:49:41 czarkoff Exp $

COMMENT =		series of applications for Mercurial

MODPY_EGG_VERSION =	3.8.3
DISTNAME =		tortoisehg-${MODPY_EGG_VERSION}

CATEGORIES =		devel

HOMEPAGE =		http://tortoisehg.bitbucket.org/

MAINTAINER =		Remi Pointel <rpointel@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		https://bitbucket.org/tortoisehg/targz/downloads/

MODULES =		lang/python
BUILD_DEPENDS =		x11/py-qt4 \
			editors/qscintilla \
			devel/py-sip

RUN_DEPENDS =		x11/py-qt4 \
			editors/qscintilla \
			devel/py-sip \
			editors/py-qscintilla \
			devel/mercurial>=3.8,<3.9 \
			devel/py-iniparse

NO_TEST =		Yes

SHAREDIR =		${PREFIX}/share/tortoisehg

post-extract:
	@${SUBST_DATA} -c ${FILESDIR}/config.py \
		${WRKSRC}/tortoisehg/util/config.py

post-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${SHAREDIR}

.include <bsd.port.mk>
