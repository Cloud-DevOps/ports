# $OpenBSD: Makefile,v 1.31 2016/12/25 14:34:39 zhuk Exp $

ONLY_FOR_ARCHS=	amd64 i386

COMMENT=	3D realtime strategy on a future earth

DISTNAME=	warzone2100-3.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=warzone2100/}
EXTRACT_SUFX=	.tar.xz
REVISION=	0

HOMEPAGE=	http://wz2100.net/

# GPLv2+
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += GL GLEW GLU Qt5Core Qt5Gui Qt5Script Qt5Widgets SDL2 X11
WANTLIB += Xrandr c crypto fontconfig freetype fribidi harfbuzz iconv
WANTLIB += intl m ogg openal physfs png pthread theora vorbis
WANTLIB += vorbisfile z

MODULES=	x11/qt5 gcc4
MODGCC4_ARCHS =	*
MODGCC4_LANGS +=c++

LIB_DEPENDS=	audio/libogg \
		audio/libvorbis \
		audio/openal>=20110627 \
		devel/fribidi \
		devel/physfs \
		devel/sdl2 \
		graphics/glew \
		graphics/png \
		multimedia/libtheora \
		x11/qt5/qtscript

BUILD_DEPENDS=	archivers/unzip \
		archivers/zip \
		textproc/asciidoc
RUN_DEPENDS=	devel/desktop-file-utils

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
CONFIGURE_STYLE= autoconf
AUTOCONF_VERSION= 2.69
CONFIGURE_ARGS+= --with-distributor="OpenBSD"
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib" \
		ac_cv_path_MOC4="${LOCALBASE}/bin/moc4" \
		ac_cv_path_UIC4="${LOCALBASE}/bin/uic4"

pre-configure:
.for _prog in git svn svnversion
	@cd ${WRKDIR}/bin && ln -sf /usr/bin/true ${_prog}
.endfor
	@cd ${WRKDIR}/bin && ln -sf ${LOCALBASE}/bin/gflex flex

.include <bsd.port.mk>
