# $OpenBSD: Makefile,v 1.5 2017/01/03 19:28:49 landry Exp $

COMMENT=	enhanced HTTPS support for httplib and urllib2

MODPY_EGG_VERSION=	0.4.2
MODPY_PI_DIR=	n/ndg-httpsclient
DISTNAME=	ndg_httpsclient-${MODPY_EGG_VERSION}
PKGNAME=	${MODPY_PY_PREFIX}ndg-httpsclient-${MODPY_EGG_VERSION}
REVISION=	0

CATEGORIES=	www

# BSD
PERMIT_PACKAGE_CDROM=	Yes

MODULES=	lang/python
MODPY_SETUPTOOLS= Yes
MODPY_PI=	Yes

FLAVORS=	python3
FLAVOR?=

RUN_DEPENDS=	security/py-openssl${MODPY_FLAVOR} \
		devel/py-asn1${MODPY_FLAVOR}

post-install:
	mv ${PREFIX}/bin/ndg_httpclient \
	    ${PREFIX}/bin/ndg_httpclient${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
