# $OpenBSD: Makefile,v 1.4 2017/01/03 19:19:48 landry Exp $

COMMENT=	command line library for Python

MODPY_EGG_VERSION=6.6
DISTNAME=	click-${MODPY_EGG_VERSION}
PKGNAME=	py-click-${MODPY_EGG_VERSION}
REVISION=	1

CATEGORIES=	devel

HOMEPAGE=	http://click.pocoo.org/6/

MAINTAINER=	Sebastian Reitenbach <sebastia@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

MODPY_PI =	Yes

MODULES=	lang/python

MODPY_SETUPTOOLS= Yes

FLAVORS=	python3
FLAVOR?=

TEST_DEPENDS=	devel/py-test${MODPY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${MODPY_BIN} -m pytest

.include <bsd.port.mk>
