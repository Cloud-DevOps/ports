# $OpenBSD: Makefile,v 1.79 2017/01/19 19:32:06 ajacoutot Exp $

# XXX
# sndio: what to do with (channel) map
# sndio: check sample format
# sndio: support for recording

COMMENT=		cross-platform networked sound server

VERSION=		10.0
DISTNAME=		pulseaudio-${VERSION}
EXTRACT_SUFX=		.tar.xz

SHARED_LIBS +=  pulse                6.1      # .20.1
SHARED_LIBS +=  pulse-simple         1.0      # .1.0
SHARED_LIBS +=  pulse-mainloop-glib  1.0      # .0.5

CATEGORIES=		audio

SUBST_VARS+=		VERSION

MAINTAINER=		Robert Nagy <robert@openbsd.org>
HOMEPAGE=		http://www.pulseaudio.org/

# LGPLv2.1
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += FLAC ICE SM X11 X11-xcb Xext Xi Xtst c crypto dbus-1
WANTLIB += execinfo gdbm glib-2.0 iconv intl ltdl m ogg pcre pthread
WANTLIB += sndfile sndio speexdsp ssl vorbis vorbisenc xcb

MASTER_SITES=		http://freedesktop.org/software/pulseaudio/releases/

MODULES=		textproc/intltool

# C++11
MODULES +=		gcc4
MODGCC4_ARCHS=		*
MODGCC4_LANGS=		c++

USE_GMAKE=		Yes

# XXX undefined reference to `lt__PROGRAM__LTX_preloaded_symbols';
# XXX remove -rpath from LDFLAGS when switching back to our libtool(1)
# and remove the following patches:
# patch-libpulse-mainloop-glib_pc_in patch-libpulse-simple_pc_in patch-libpulse_pc_in
USE_LIBTOOL=		gnu

# needed for tests
BUILD_DEPENDS +=	devel/check
TEST_FLAGS=		HOME=${WRKDIST}

LIB_DEPENDS=		audio/libsndfile \
			audio/speex \
			databases/gdbm \
			devel/glib2 \
			devel/libexecinfo \
			devel/libtool,-ltdl \
			x11/dbus

# module-console-kit.so
RUN_DEPENDS +=		sysutils/consolekit

CONFIGURE_STYLE=	gnu

# We only enable the strict minimum for basic volume control support.
# sndiod(1) is the default sound server on OpenBSD and pulseaudio is only
# needed for a couple of use cases (volume control, media-keys)
CONFIGURE_ARGS=		--disable-atomic-arm-linux-helpers \
			--disable-default-build-tests \
			--with-system-user=_pulse \
			--with-system-group=_pulse \
			--with-access-group=_pulse-access \
			--with-database=gdbm \
			--with-bash-completion-dir=${PREFIX}/share/bash-completion/completions \
			--without-soxr \
			--without-fftw \
			--disable-oss-output \
			--disable-oss-wrapper \
			--disable-adrian-aec \
			--disable-alsa \
			--disable-asyncns \
			--disable-bluez4 \
			--disable-bluez5 \
			--disable-esound \
			--disable-gtk3 \
			--disable-jack \
			--disable-hal-compat \
			--disable-systemd \
			--disable-systemd-journal \
			--disable-udev \
			--disable-lirc \
			--disable-solaris \
			--disable-tcpwrap \
			--disable-coreaudio-output \
			--disable-waveout \
			--disable-gconf \
			--disable-avahi \
			--disable-orc

CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib \
				-Wl,-rpath,${TRUEPREFIX}/lib/pulseaudio:${TRUEPREFIX}/lib/pulse-${VERSION}/modules" \
			ac_cv_prog_M4=m4

FAKE_FLAGS=		pulseconfdir="${PREFIX}/share/examples/pulseaudio/pulse" \
			sysconfdir="${PREFIX}/share/examples/pulseaudio"

### SNDIO ###
AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15
BUILD_DEPENDS +=	${MODGNU_AUTOMAKE_DEPENDS} \
			${MODGNU_AUTOCONF_DEPENDS}
BUILD_DEPENDS +=	devel/libtool # needs needs libtoolize

post-extract:
	cp ${FILESDIR}/module-sndio*.{c,h} ${WRKSRC}/src/modules/

pre-configure:
	cd ${WRKSRC} && \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		autoreconf -i --force && \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		aclocal && \
		intltoolize --force
### END SNDIO ###
	${SUBST_CMD} ${WRKSRC}/src/daemon/default.pa.in
	sed -i 's,/bin/bash,/usr/bin/env bash,' \
		${WRKSRC}/shell-completion/bash/pulseaudio

post-install:
	rm ${PREFIX}/lib/pulse-${VERSION}/modules/*.a
# we don't install padsp
	cd ${PREFIX} && rm man/man1/padsp.1

.include <bsd.port.mk>
