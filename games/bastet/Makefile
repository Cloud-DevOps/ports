# $OpenBSD: Makefile,v 1.4 2016/11/14 04:02:25 jca Exp $

# Block.s: Assembler messages:
# Block.s:73: Error: junk `(%rip)' after expression
ONLY_FOR_ARCHS = ${LLVM_ARCHS}
# /usr/local/lib/gcc/sparc64-unknown-openbsd6.0/4.9.4/libgcc.a(unwind-dw2-fde-dip.o): In function `__gthread_mutex_lock':
# ./gthr-default.h:748: undefined reference to `pthread_mutex_lock'
BROKEN-sparc64 = undefined reference to pthread_mutex_lock

COMMENT =	bastard tetris
DISTNAME =	bastet-0.43.1.2015083000
REVISION =	0

GH_ACCOUNT =	fph
GH_PROJECT =	bastet
GH_COMMIT =	5037e410fde6fafe8e6bc4cf17a12ad98e01c17e

CATEGORIES =	games

HOMEPAGE =	http://fph.altervista.org/prog/bastet.html

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	boost_program_options c ncurses m

MODULES =	lang/clang
MODCLANG_ARCHS = *
MODCLANG_LANGS = c++
LIB_DEPENDS =	devel/boost

NO_TEST =	Yes

do-configure:
	${SUBST_CMD} ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bastet/
	cd ${WRKSRC}; ${INSTALL_DATA} AUTHORS LICENSE NEWS README \
	    ${PREFIX}/share/doc/bastet
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bastet/
	${INSTALL_DATA} /dev/null \
	    ${PREFIX}/share/examples/bastet/bastet.scores2

.include <bsd.port.mk>
