# $OpenBSD: Makefile,v 1.2 2016/08/21 09:53:59 jasper Exp $

COMMENT =		DHCP packet dumper

DISTNAME =		dhcpdump-1.8
REVISION =		0

CATEGORIES =		net

HOMEPAGE =		http://mavetju.org/unix/general.php

# BSD
PERMIT_PACKAGE_CDROM =	Yes

MASTER_SITES =		http://mavetju.org/download/

WANTLIB =		c pcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
