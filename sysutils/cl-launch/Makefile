# $OpenBSD: Makefile,v 1.2 2015/11/24 09:11:06 jasper Exp $

COMMENT=		uniform frontend to running Common Lisp code from the shell

DISTNAME=		cl-launch-4.1.3
CATEGORIES=		sysutils

HOMEPAGE=		http://cliki.net/cl-launch

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>

# LLGPL (http://www.cliki.net/LLGPL)
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		https://distfiles.nl/

WRKDIST=		${WRKDIR}/cl-launch.git/

WANTLIB=		c

USE_GMAKE=		Yes

ALL_TARGET=		cl-shim

RUN_DEPENDS=		abcl-*|clisp-*|sbcl-*:lang/sbcl

.include <bsd.port.mk>
