# $OpenBSD: Makefile,v 1.23 2016/04/07 16:05:48 naddy Exp $

COMMENT=	command-line MPEG audio decoder and player

DISTNAME=	madplay-0.15.2b
REVISION=	4
CATEGORIES=	audio
HOMEPAGE=	http://mad.sourceforge.net/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	ftp://ftp.mars.org/pub/mpeg/ \
		${MASTER_SITE_SOURCEFORGE:=mad/}

LIB_DEPENDS=	audio/libid3tag \
		audio/libmad \
		devel/gettext
WANTLIB=	c iconv id3tag intl m mad sndio z

SEPARATE_BUILD=	Yes
AUTOCONF_VERSION=2.59
CONFIGURE_STYLE= autoconf
CONFIGURE_ARGS=	--without-esd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-extract:
	@cp -f ${FILESDIR}/audio_sndio.c ${WRKSRC}/

.include <bsd.port.mk>
