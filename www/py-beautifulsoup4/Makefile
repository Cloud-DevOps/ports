# $OpenBSD: Makefile,v 1.6 2017/01/03 19:28:48 landry Exp $

COMMENT =	HTML/XML parser that supports invalid markup

MODPY_EGG_VERSION =	4.5.1
DISTNAME =	beautifulsoup4-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}
REVISION =	0

CATEGORIES =	www

HOMEPAGE =	http://www.crummy.com/software/BeautifulSoup/
MAINTAINER =	frantisek holop <minusf@obiit.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =	${HOMEPAGE}bs4/download/4.5/

MODULES =	lang/python

TEST_DEPENDS =	devel/py-html5lib${MODPY_FLAVOR} \
		textproc/py-lxml${MODPY_FLAVOR}

FLAVORS =	python3
FLAVOR ?=

MODPY_SETUPTOOLS =	Yes

do-test: fake
	cd ${WRKINST}${MODPY_SITEPKG} && ${MODPY_BIN} -m unittest discover -s bs4

.include <bsd.port.mk>
