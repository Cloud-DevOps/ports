# $OpenBSD: Makefile,v 1.46 2017/01/31 03:34:02 ajacoutot Exp $

# XXX ossaudio(3) is only enabled to be used as a mixing device by
# x11/xfce4/xfce4-mixer

COMMENT-main=		good elements for GStreamer
COMMENT-pulse=		pulseaudio(1) element for GStreamer

DISTNAME=		gst-plugins-good-${V}
PKGNAME=		${GST_PKGNAME_PREFIX}-plugins-good-${V}

PKGNAME-main=		${PKGNAME}
PKGNAME-pulse=		${GST_PKGNAME_PREFIX}-plugins-pulse-${V}

MASTER_SITES=		${MASTER_SITE_GST:=gst-plugins-good/}

WANTLIB += ffi glib-2.0 gmodule-2.0 gobject-2.0 gstaudio-1.0 gstbase-1.0
WANTLIB += gstpbutils-1.0 gstreamer-1.0 gsttag-1.0 gstvideo-1.0
WANTLIB += m orc-0.4 pcre pthread z X11 Xext xcb iconv intl

WANTLIB-main +=	${WANTLIB}
WANTLIB-main += FLAC Xdamage Xfixes bz2 xml2 pthread-stubs
WANTLIB-main += gdk_pixbuf-2.0 gio-2.0 gstcontroller-1.0 lzma
WANTLIB-main += gstfft-1.0 gstnet-1.0 gstriff-1.0 gstrtp-1.0 gstrtsp-1.0 xcb-render
WANTLIB-main += gstallocators-1.0 gstsdp-1.0 jpeg ogg ossaudio png shout soup-2.4
WANTLIB-main += speex sqlite3 stdc++ tag theora vorbis vpx>=5 wavpack xcb-shm
WANTLIB-main += Xrender cairo cairo-gobject expat fontconfig freetype pixman-1
WANTLIB-main += v4l2 v4lconvert

# comes from multimedia/libvpx using lang/clang MODULE on i386|amd64 only
# which includes gcc4 MODULE with adds gcc-libs in dependency scope
.if ${MACHINE_ARCH:Mi386} || ${MACHINE_ARCH:Mamd64}
WANTLIB-main += estdc++
.endif

WANTLIB-pulse += ${WANTLIB}
WANTLIB-pulse += execinfo gdbm pulse sndfile X11-xcb Xi Xtst ICE
WANTLIB-pulse += FLAC ogg vorbis vorbisenc dbus-1 SM

MULTI_PACKAGES=		-main -pulse

LIB_DEPENDS=		${P}/plugins-base=${V}

LIB_DEPENDS-main=	${LIB_DEPENDS} \
			archivers/bzip2 \
			audio/flac \
			audio/speex \
			audio/taglib \
			audio/wavpack \
			devel/libsoup \
			graphics/gdk-pixbuf2 \
			multimedia/libv4l \
			multimedia/libvpx \
			net/libshout

LIB_DEPENDS-pulse=	${LIB_DEPENDS} \
			audio/pulseaudio
RUN_DEPENDS-pulse=	${BASE_PKGPATH},-main=${V}

CONFIGURE_ARGS=		--disable-aalib \
			--disable-jack \
			--disable-libcaca \
			--disable-libdv \
			--disable-oss4 \
			--disable-sunaudio \
			--disable-waveform \
			--disable-dv1394

pre-configure:
	sed -i 's,/dev/dsp,/dev/audio,g' \
		${WRKSRC}/docs/plugins/gst-plugins-good-plugins.args \
		${WRKSRC}/docs/plugins/html/gst-plugins-good-plugins-osssink.html \
		${WRKSRC}/docs/plugins/html/gst-plugins-good-plugins-osssrc.html \
		${WRKSRC}/sys/oss/gstosssink.c \
		${WRKSRC}/sys/oss/gstosssrc.c

.include <bsd.port.mk>
