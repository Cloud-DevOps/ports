# $OpenBSD: Makefile,v 1.128 2017/01/15 17:58:00 ajacoutot Exp $

COMMENT=	GNU Transport Layer Security library

V=		3.5.8
DISTNAME=	gnutls-${V}
EXTRACT_SUFX=	.tar.xz

CATEGORIES=	security

SHARED_LIBS +=  gnutls               44.0     # 43.1
SHARED_LIBS +=  gnutlsxx             29.1     # 29.0

HOMEPAGE=	http://www.gnutls.org/

MAINTAINER=	Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2.1+ - GPLv3+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c ffi gmp hogweed iconv idn intl m nettle p11-kit pthread
WANTLIB += tasn1 unistring z

MASTER_SITES=	ftp://ftp.gnutls.org/gcrypt/gnutls/v${V:R}/ \
		http://ftp.heanet.ie/mirrors/ftp.gnupg.org/gcrypt/gnutls/v${V:R}/

# assembly instructions
MODULES +=	lang/clang
MODCLANG_ARCHS=	amd64
MODCLANG_LANGS=	c++
.if ${MACHINE_ARCH} != "amd64"
WANTLIB += stdc++
.endif

LIB_DEPENDS=	converters/libunistring \
		devel/libidn \
		security/libtasn1 \
		security/libnettle \
		security/p11-kit

USE_GMAKE=	Yes

# regression tests need this
PORTHOME=	${WRKDIR}

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--disable-guile \
		--disable-ssl3-support \
		--disable-valgrind-tests \
		--with-default-trust-store-file=/etc/ssl/cert.pem \
		--with-unbound-root-key-file=/var/unbound/db/root.key

# OpenBSD's unbound does not provide libdane
CONFIGURE_ARGS += --disable-libdane

# requires security/trousers: not committed (aja@), needs kernel support
# for tpm(4): http://bsssd.sourceforge.net/
CONFIGURE_ARGS += --without-tpm

# prevents dependency on devel/autogen
CONFIGURE_ARGS+=--enable-local-libopts

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnutls
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnutls
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.c \
		${PREFIX}/share/examples/gnutls

# warning: implicit declaration of function 'kill'
# error: 'SIGTERM' undeclared (first use in this function)
pre-test:
	perl -i -pe 's,#include <stdlib.h>,$$&\n#include <signal.h>,' \
		${WRKSRC}/tests/*.c

.include <bsd.port.mk>
