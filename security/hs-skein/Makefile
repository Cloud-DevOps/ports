# $OpenBSD: Makefile,v 1.9 2016/01/20 16:26:20 kili Exp $

COMMENT =		a family of cryptographic hash functions

DISTNAME =		skein-1.0.9.2
REVISION =		2
CATEGORIES =		security

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	4cmcSdqE4k4IDFpNaHNXzg

RUN_DEPENDS =		devel/hs-cereal>=0.3,<0.5 \
			devel/hs-tagged>=0.2,<0.8 \
			security/hs-crypto-api>=0.6,<0.14

BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
