# $OpenBSD: Makefile,v 1.8 2017/01/30 16:59:07 ajacoutot Exp $

COMMENT=		service discovery and configuration tool

GH_TAGNAME=		v0.7.3
GH_ACCOUNT=		hashicorp
GH_PROJECT=		consul
REVISION=		0

CATEGORIES=		sysutils net

HOMEPAGE=		https://www.consul.io/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# MPLv2.0
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c pthread

MODULES=		lang/go

# go/src/github.com/hashicorp/consul/scripts/build.sh
# go/src/github.com/hashicorp/consul/version/version.go
MODGO_LDFLAGS +=	-X github.com/hashicorp/consul/version.GitDescribe=${GH_TAGNAME}
MODGO_LDFLAGS +=	-X github.com/hashicorp/consul/version.VersionPrerelease="" # empty

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/consul
	${SUBST_CMD} -c -m 0640 ${FILESDIR}/config.json.in \
		${PREFIX}/share/examples/consul/config.json

.include <bsd.port.mk>
