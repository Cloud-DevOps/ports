# $OpenBSD: Makefile,v 1.16 2017/02/07 14:42:24 sthen Exp $

COMMENT=	audio player and tagger for GTK+ with regex support

MODPY_EGG_VERSION= 3.8.1
DISTNAME=	quodlibet-${MODPY_EGG_VERSION}

CATEGORIES=	audio

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

HOMEPAGE=	https://quodlibet.readthedocs.org/

# GPLv2 only
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	https://bitbucket.org/lazka/quodlibet-files/raw/default/releases/

MODULES=	devel/gettext \
		lang/python
RUN_DEPENDS=	audio/py-mutagen>=1.32 \
		devel/desktop-file-utils \
		devel/py-gobject3 \
		graphics/py-cairo \
		multimedia/gstreamer1/plugins-good \
		multimedia/gstreamer1/plugins-libav \
		multimedia/xine-lib \
		textproc/py-feedparser \
		x11/dbus-python \
		x11/gtksourceview3 \
		x11/gtk+3,-guic

BUILD_DEPENDS=	${RUN_DEPENDS} \
		textproc/intltool
MODPY_ADJ_FILES= *py

MODPY_DISTUTILS_INSTALLARGS= --mandir=${PREFIX}/man

do-test:
	cd ${WRKSRC}; ${MODPY_BIN} ./setup.py test

.include <bsd.port.mk>
