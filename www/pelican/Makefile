# $OpenBSD: Makefile,v 1.5 2015/09/29 10:52:54 sthen Exp $

COMMENT =		static site generator written in Python

MODPY_EGG_VERSION =	${GH_TAGNAME}
DISTNAME =		pelican-${MODPY_EGG_VERSION}
REVISION =		1

GH_ACCOUNT =		getpelican
GH_PROJECT =		pelican
GH_TAGNAME =		3.6.3

CATEGORIES =		www

HOMEPAGE =		http://blog.getpelican.com/

MAINTAINER =		Vladimir Seleznev <vseleznv@cs.msu.ru>

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
RUN_DEPENDS =		devel/py-blinker \
			devel/py-dateutil \
			textproc/markdown \
			textproc/py-docutils \
			textproc/py-pygments \
			textproc/py-unidecode \
			www/py-feedgenerator \
			www/py-jinja2

# Else setuptools skips filenames containing UTF8 chars
MAKE_ENV +=		LC_CTYPE=en_US.UTF-8

TEST_DEPENDS =		${RUN_DEPENDS} \
			devel/git \
			devel/py-mock

pre-configure:
	${SUBST_CMD} ${WRKSRC}/pelican/tests/test_pelican.py

.include <bsd.port.mk>
