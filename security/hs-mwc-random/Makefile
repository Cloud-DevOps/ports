# $OpenBSD: Makefile,v 1.9 2016/01/20 16:26:19 kili Exp $

COMMENT=		fast, high quality pseudo random number generation

DISTNAME=		mwc-random-0.13.3.2
REVISION=		1
CATEGORIES=		math security

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES=		lang/ghc

MODGHC_BUILD =          cabal hackage haddock register

MODGHC_PACKAGE_KEY =	0SEz8XRK7wOF4DF0uaF48y

RUN_DEPENDS =		devel/hs-primitive \
			devel/hs-vector>=0.7
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
