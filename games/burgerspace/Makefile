# $OpenBSD: Makefile,v 1.29 2016/09/13 15:29:01 naddy Exp $

COMMENT=	burgertime clone for X

DISTNAME =	burgerspace-1.9.2

CATEGORIES=	games

HOMEPAGE=	http://sarrazip.com/dev/burgerspace.html

# GPLv2+
PERMIT_PACKAGE_CDROM=   Yes

WANTLIB += FLAC SDL SDL_image SDL_mixer c flatzebra-0.1
WANTLIB += iconv jpeg m mikmod ogg png pthread smpeg sndio stdc++ tiff
WANTLIB += usbhid vorbis vorbisfile z webp

MASTER_SITES=	http://sarrazip.com/dev/

LIB_DEPENDS=	converters/libiconv \
		devel/flatzebra>=0.1.6
RUN_DEPENDS=	devel/desktop-file-utils

CONFIGURE_STYLE= gnu

.include <bsd.port.mk>
