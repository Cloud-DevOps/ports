# $OpenBSD: Makefile,v 1.17 2017/02/06 20:28:32 sthen Exp $

COMMENT=	apache HTTP server request library

DISTNAME=	libapreq2-2.08
# no perl module; p5- is needed
PKGNAME=	p5-${DISTNAME}
REVISION=	6
CATEGORIES=	www

MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/J/JO/JOESUF/}
SHARED_LIBS=	apreq2	9.0

# Artistic + GPL
PERMIT_PACKAGE_CDROM=  Yes

WANTLIB += apr-1 aprutil-1 db expat iconv perl pthread # uses perl ABI

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS=	--enable-perl-glue \
		--with-apache2-apxs=${LOCALBASE}/sbin/apxs2

BUILD_DEPENDS=	devel/p5-ExtUtils-XSBuilder \
		www/ap2-mod_perl
LIB_DEPENDS=	converters/libiconv \
		devel/apr \
		devel/apr-util

RUN_DEPENDS =	www/ap2-mod_perl

post-test:
	cd ${WRKSRC}/glue/perl && \
	    LD_LIBRARY_PATH="${WRKSRC}/library/.libs:${LOCALBASE}" ${MAKE} test

.include <bsd.port.mk>
