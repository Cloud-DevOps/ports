# $OpenBSD: Makefile,v 1.26 2016/03/16 16:46:32 naddy Exp $

COMMENT=	C-style arbitrary precision calculator

DISTNAME=	calc-2.12.5.4
EXTRACT_SUFX=	.tar.bz2

SHARED_LIBS=	calc 0.0 \
		custcalc 0.0

CATEGORIES=	math

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c curses readline

MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		${MASTER_SITE_SOURCEFORGE:=calc/}

MAKE_FLAGS=\
	BINDIR='$${DESTDIR}${PREFIX}/bin' \
	LIBDIR='$${DESTDIR}${PREFIX}/lib' \
	INCDIR='$${DESTDIR}${PREFIX}/include' \
	MANDIR='$${DESTDIR}${PREFIX}/man/man1' \
	CALC_SHAREDIR='$${DESTDIR}${PREFIX}/share/calc' \
	LIB_EXT_VERSION=".so.${LIBcalc_VERSION}" \
	USE_READLINE='-DUSE_READLINE' \
	READLINE_LIB='-lreadline -lcurses' \
	LCC="${CC}" \
	CCOPT="${CFLAGS}"

USE_GMAKE=	Yes
TEST_TARGET=	check

post-install:
	rm ${PREFIX}/lib/lib{cust,}calc.so

.include <bsd.port.mk>
