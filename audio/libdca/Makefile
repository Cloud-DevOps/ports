# $OpenBSD: Makefile,v 1.11 2016/03/11 19:59:11 naddy Exp $

COMMENT=	free DTS Coherent Acoustics decoder

V=		0.0.5
DISTNAME=	libdca-${V}
REVISION=	4
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	audio
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdca/${V}/

SHARED_LIBS=	dca	0.0

HOMEPAGE=	http://www.videolan.org/developers/libdca.html

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c m sndio

CONFIGURE_STYLE = autoconf
AUTOCONF_VERSION = 2.61
CONFIGURE_ARGS += --disable-oss
MODGNU_CONFIG_GUESS_DIRS =	${WRKSRC}/autotools

post-extract:
	@cp ${FILESDIR}/audio_out_sndio.c ${WRKSRC}/libao

.include <bsd.port.mk>
