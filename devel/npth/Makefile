# $OpenBSD: Makefile,v 1.6 2016/10/01 13:56:26 naddy Exp $

COMMENT=	new GNU Portable Threads Library

DISTNAME=	npth-1.2

SHARED_LIBS=	npth 0.0	# 0.5

CATEGORIES=	devel

HOMEPAGE=	http://www.gnupg.org

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

EXTRACT_SUFX=		.tar.bz2

WANTLIB=		pthread

MASTER_SITES=		${MASTER_SITE_GNUPG:=npth/}

CONFIGURE_STYLE=	gnu

LIBnpth_MAJOR=${LIBnpth_VERSION:R} 
LIBnpth_MINOR=${LIBnpth_VERSION:E} 

SUBST_VARS=		LIBnpth_MAJOR LIBnpth_MINOR

pre-configure:
	${SUBST_CMD} ${WRKSRC}/configure

.include <bsd.port.mk>
