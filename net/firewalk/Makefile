# $OpenBSD: Makefile,v 1.37 2015/12/03 21:24:31 sthen Exp $

COMMENT=	gateway acl scanner (via static-source port traceroute)

DISTNAME=	firewalk-0.8
REVISION=	2
CATEGORIES=     net

#MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
MASTER_SITES=	https://spacehopper.org/mirrors/

#HOMEPAGE=	http://www.packetfactory.net/projects/firewalk/

LIB_DEPENDS=	net/libnet/1.0
WANTLIB=	c pcap lib/libnet-1.0/net=0

# BSD
PERMIT_PACKAGE_CDROM=	Yes


CONFIGURE_STYLE= gnu dest

ALL_TARGET=	firewalk

WRKDIST=	${WRKDIR}/Firewalk

NO_TEST=	Yes

.include <bsd.port.mk>
