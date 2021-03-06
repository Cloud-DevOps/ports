# $OpenBSD: Makefile,v 1.65 2016/11/04 11:35:21 sthen Exp $

COMMENT =		the enlightened window manager

VERSION =		0.17.6
DISTNAME =		enlightenment-${VERSION}
EPOCH =			1
REVISION =		6

# BSD
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${MODLUA_WANTLIB}
WANTLIB += X11 Xau Xcomposite Xcursor Xdamage Xdmcp Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender Xss Xtst c cares crypto curl dbus-1
WANTLIB += ecore ecore_con ecore_evas ecore_file ecore_imf
WANTLIB += ecore_imf_evas ecore_input ecore_input_evas ecore_ipc ecore_x
WANTLIB += edbus edje eet efreet efreet_mime efreet_trash ehal eina eio
WANTLIB += elementary embryo emotion enotify ethumb ethumb_client eukit
WANTLIB += evas execinfo exif expat fontconfig freetype fribidi glib-2.0
WANTLIB += graphite2 harfbuzz jpeg m nghttp2 pcre pthread pthread-stubs
WANTLIB += ssl xcb xcb-keysyms xcb-shape z

MODULES +=		devel/gettext \
			lang/lua \
			x11/e17

MODE17_DESKTOP_FILE =	Yes
MODE17_PURGE_LA =	lib/enlightenment/modules

LIB_DEPENDS =		x11/e17/elementary>=1.7.10 \
			devel/libexecinfo

CONFIGURE_ARGS +=	--disable-doc \
			--disable-nls \
			--disable-pam

CONFIGURE_ENV +=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

# Stupid crap in /src/modules/illume/dicts chokes in regular make.
# Some issue with the "(US)" bit
USE_GMAKE =		Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/enlightenment
	mv ${WRKINST}/${SYSCONFDIR}/* ${PREFIX}/share/examples/

.include <bsd.port.mk>
