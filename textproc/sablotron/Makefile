# $OpenBSD: Makefile,v 1.42 2016/04/09 20:14:49 naddy Exp $

COMMENT =	fast, compact and portable XSL/XSLT processor

V =		1.0.3
DISTNAME =	Sablot-${V}
PKGNAME =	sablotron-${V}
REVISION =	2
SHARED_LIBS =	sablot	103.0	# .100.3
CATEGORIES =	textproc

HOMEPAGE =	http://freshmeat.net/projects/sablotron/

# MPL1.1 / GPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c expat iconv m ncurses readline stdc++

MASTER_SITES =	http://www.arcane-labs.net/download/OpenBSD/

LIB_DEPENDS =	converters/libiconv

# required to build the documentation
BUILD_DEPENDS =	textproc/p5-XML-Parser

USE_GMAKE =			Yes
AUTOCONF_VERSION = 		2.57
MODGNU_CONFIG_GUESS_DIRS =	${WRKSRC}/autocfg

CONFIGURE_STYLE =		gnu
CONFIGURE_ENV =			SABLOT_GPL=1
CONFIGURE_ARGS =	--enable-static \
		--enable-debugger \
		--with-iconv-prefix=${LOCALBASE} --with-readline \
		--with-html-dir=${PREFIX}/share/doc/sablotron

.include <bsd.port.mk>
