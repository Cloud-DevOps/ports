# $OpenBSD: Makefile,v 1.26 2016/03/28 22:42:13 kili Exp $

COMMENT =	Haskell 98 interpreter

DISTNAME =	hugs98-plus-Sep2006
PKGNAME =	hugs98-2006.09
REVISION =	3
CATEGORIES =	lang
MAINTAINER =	Matthias Kilian <kili@openbsd.org>
HOMEPAGE =	http://www.haskell.org/hugs/

MASTER_SITES =	http://cvs.haskell.org/Hugs/downloads/2006-09/
MASTER_SITES0 =	http://openbsd.dead-parrot.de/distfiles/

DISTFILES +=	${DISTNAME}.tar.gz ${DISTNAME}-tests.tar.gz:0

CFLAGS +=	-fPIC

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV +=	CFLAGS="${CFLAGS}" CC="${CC}"
CONFIGURE_ARGS +=	--with-pthreads --libdir=${PREFIX}/lib

# BSDish
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		GL GLU X11 c m ncurses pthread readline

.include <bsd.port.mk>
