# $OpenBSD: Makefile,v 1.8 2017/01/03 19:38:35 landry Exp $

COMMENT =	Python library for OAuth

MODPY_EGG_VERSION = 2.0.0
REVISION =	1

GH_ACCOUNT =	idan
GH_PROJECT =	oauthlib
GH_TAGNAME =	v${MODPY_EGG_VERSION}

PKGNAME =	py-oauthlib-${MODPY_EGG_VERSION}

CATEGORIES =	security
MAINTAINER =	Johan Huldtgren <jhuldtgren@gmail.com>

# BSD
PERMIT_PACKAGE_CDROM =  Yes

MODULES =	lang/python
MODPY_SETUPTOOLS = Yes

RUN_DEPENDS =	devel/py-blinker${MODPY_FLAVOR} \
		security/py-cryptography${MODPY_FLAVOR} \
		www/py-jwt${MODPY_FLAVOR}

TEST_DEPENDS =	devel/py-nose${MODPY_FLAVOR} \
		devel/py-coverage${MODPY_FLAVOR} \
		devel/py-mock${MODPY_FLAVOR} \
		${RUN_DEPENDS}

FLAVORS =	python3
FLAVOR ?=

post-extract:
	chmod -R o+rX ${WRKSRC}

# tests/oauth2/rfc5849/endpoints/test_error_responses.py
# will through a warning when make test is run under
# the python3 flavor, fixing this breaks python2 though.
do-test:
	cd ${WRKSRC} && ${MODPY_BIN} -m unittest discover

.include <bsd.port.mk>
