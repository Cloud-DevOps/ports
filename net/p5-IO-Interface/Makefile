# $OpenBSD: Makefile,v 1.22 2016/03/20 19:56:51 naddy Exp $

COMMENT =	module for access to network card configuration information

MODULES =	cpan
DISTNAME =	IO-Interface-1.09
CATEGORIES =	net
REVISION =	0

HOMEPAGE =	https://github.com/lstein/LibIO-Interface-Perl

MAINTAINER =	Mikolaj Kucharski <mikolaj@kucharski.name>

# Artistic/GPL
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	perl

CONFIGURE_STYLE =	modbuild

# upstream switched to modbuild, commit c4de691
CFLAGS =	-D__USE_BSD -DSIOCGIFCONF -DHAVE_SOCKADDR_DL_STRUCT -DUSE_GETIFADDRS

.include <bsd.port.mk>
