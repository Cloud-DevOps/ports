# $OpenBSD: Makefile,v 1.12 2016/04/27 12:42:55 jca Exp $

COMMENT =		data recovery tool

DISTNAME =		ddrescue-1.21

CATEGORIES =		sysutils

HOMEPAGE =		https://www.gnu.org/software/ddrescue/ddrescue.html

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c m stdc++

MASTER_SITES =		${MASTER_SITE_GNU:=ddrescue/}

EXTRACT_SUFX =		.tar.lz

BUILD_DEPENDS = 	devel/help2man

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
			CXXFLAGS="${CXXFLAGS}"

ALL_TARGET =		all doc

.include <bsd.port.mk>
