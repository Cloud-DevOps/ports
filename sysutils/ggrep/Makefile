# $OpenBSD: Makefile,v 1.29 2016/12/19 20:43:49 naddy Exp $

COMMENT=	GNU versions of grep pattern matching utilities

DISTNAME=	grep-2.27
PKGNAME=	g${DISTNAME}
CATEGORIES=	sysutils
HOMEPAGE=	https://www.gnu.org/software/grep/grep.html

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

EXTRACT_SUFX=	.tar.xz

LIB_DEPENDS=	devel/gettext devel/pcre
WANTLIB=	c iconv intl pcre

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MODGNU_CONFIG_GUESS_DIRS=${WRKSRC}/build-aux

.include <bsd.port.mk>
