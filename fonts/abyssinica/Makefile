# $OpenBSD: Makefile,v 1.4 2016/11/04 15:53:59 rpe Exp $

COMMENT =		Ethiopic Unicode script

TYPEFACE =		abyssinica
V =			1.500
DISTNAME =		AbyssinicaSIL-$V
CATEGORIES =		fonts

HOMEPAGE =		http://software.sil.org/abyssinica/

MAINTAINER =		George Rosamond <george@nycbug.org>

# SIL OFL 1.1
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		font

MASTER_SITES =		http://software.sil.org/downloads/abyssinica/

NO_BUILD =		Yes
NO_TEST =		Yes

DOCDIR =		${PREFIX}/share/doc/abyssinica

do-install:
	${MODFONT_do-install}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIST}/*.txt ${DOCDIR}

.include <bsd.port.mk>
