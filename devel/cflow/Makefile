# $OpenBSD: Makefile,v 1.9 2016/05/25 07:51:51 benoit Exp $

COMMENT =	analyze C source files and print a call graph

DISTNAME =	cflow-1.5
CATEGORIES =	devel

HOMEPAGE =	https://www.gnu.org/software/cflow/

MAINTAINER =	Benoit Lecocq <benoit@openbsd.org>

# GPLv3
PERMIT_PACKAGE_CDROM =		Yes

WANTLIB =		c iconv intl

MASTER_SITES =		${MASTER_SITE_GNU:=cflow/}

LIB_DEPENDS =		devel/gettext

MAKE_FLAGS =		LIBINTL="-L${LOCALBASE}/lib -liconv -lintl"

USE_GMAKE =		Yes
SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	gnu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/elisp/cflow-mode.el \
		${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
