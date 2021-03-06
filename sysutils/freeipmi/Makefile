# $OpenBSD: Makefile,v 1.31 2016/12/30 17:39:22 jca Exp $

COMMENT=	IPMI library and tools (in- and out-of-band)

V=		1.5.5
REVISION=	0
DISTNAME=	freeipmi-${V}

SHARED_LIBS +=	freeipmi             6.3      # 18.3
SHARED_LIBS +=	ipmiconsole          3.0      # 5.4
SHARED_LIBS +=	ipmimonitoring       1.0      # 5.6
SHARED_LIBS +=	ipmidetect           1.0      # 0.0

CATEGORIES=	sysutils

HOMEPAGE=	https://www.gnu.org/software/freeipmi/

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c gcrypt gpg-error iconv intl m pthread

MASTER_SITES=	${MASTER_SITE_GNU:=freeipmi/}

BUILD_DEPENDS=	devel/argp-standalone
LIB_DEPENDS=	security/libgcrypt \
		devel/gettext

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes

CONFIGURE_STYLE= gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
FAKE_FLAGS=	localstatedir=${PREFIX}/share/examples/freeipmi \
		sysconfdir=${PREFIX}/share/examples/freeipmi \
		FREEIPMI_SYSCONFDIR=${PREFIX}/share/examples/freeipmi

post-install:
	cd ${PREFIX}/share/examples/freeipmi && \
	    mv lib/freeipmi/ipckey . && \
	    rm -r init.d sysconfig lib

.include <bsd.port.mk>
