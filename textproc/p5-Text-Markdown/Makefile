# $OpenBSD: Makefile,v 1.12 2016/03/20 19:57:09 naddy Exp $

COMMENT=	convert Markdown syntax to (X)HTML

DISTNAME=	Text-Markdown-1.000031
CATEGORIES=	textproc www
MODULES=	cpan
PKG_ARCH=	*

MAINTAINER=	Okan Demirmen <okan@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

RUN_DEPENDS=	devel/p5-File-Slurp \
		devel/p5-List-MoreUtils \
		devel/p5-Test-Exception

MAKE_ENV=	TEST_POD=Yes

TEST_DEPENDS=	devel/p5-Test-Differences \
			www/p5-HTML-Tidy

.include <bsd.port.mk>
