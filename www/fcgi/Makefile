# $OpenBSD: Makefile,v 1.25 2017/02/06 20:28:32 sthen Exp $

COMMENT=		FastCGI Development Kit

DISTNAME=		fcgi-2.4.0
REVISION=		12
CATEGORIES=		www
SHARED_LIBS +=	fcgi                 0.0      # .0.0
SHARED_LIBS +=	fcgi++               1.0      # .1.0

HOMEPAGE=		http://www.fastcgi.com/

MAINTAINER=		Adam Montague <amontague@siriushosting.com>

# See LICENSE.TERMS. Some source files (from the same authors) have other
# licenses but LICENSE.TERMS says "The following terms apply to all files
# associated with the Software and Documentation unless explicitly
# disclaimed in individual files". Also see analysis at
# http://www.fastcgi.com/archives/fastcgi-developers/2010-June/000559.html
PERMIT_PACKAGE_CDROM=   Yes

WANTLIB=		c m stdc++
WANTLIB += perl # uses perl ABI

MASTER_SITES=		${HOMEPAGE}/dist/


CONFIGURE_STYLE=	gnu

CAT3_FILES=		FCGI_Accept FCGI_Finish FCGI_SetExitStatus \
			FCGI_StartFilterData

post-configure:
	@cd ${WRKSRC}/perl && perl Makefile.PL

post-build:
	@cd ${WRKSRC}/perl && ${MAKE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cgi-fcgi.1 ${PREFIX}/man/cat1/cgi-fcgi.0
.for file in ${CAT3_FILES}
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.3 ${PREFIX}/man/cat3/${file}.0
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fcgi
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm* ${WRKSRC}/doc/*.gif \
	${PREFIX}/share/doc/fcgi
	@cd ${WRKSRC}/perl && ${MAKE} install

.include <bsd.port.mk>
