# $OpenBSD: Makefile,v 1.9 2016/05/31 11:39:20 nigel Exp $

COMMENT =		an extensible platform for analysis of C software
#Error: Error while linking /usr/local/lib/ocaml/vmthreads/stdlib.cma(String):
#Reference to undefined global `Bytes'
BROKEN-powerpc =	Error while linking /usr/local/lib/ocaml/vmthreads/stdlib.cma
BROKEN-alpha =		Error while linking /usr/local/lib/ocaml/vmthreads/stdlib.cma

DISTNAME =		frama-c-Sodium-20150201
PKGNAME =		frama-c-1.11
CATEGORIES =		devel
REVISION =		0
HOMEPAGE =		http://www.frama-c.com/

# LGPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender art_lgpl_2 atk-1.0 c cairo curses fontconfig
WANTLIB += freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB += gnomecanvas-2 gobject-2.0 gtk-x11-2.0 gtksourceview-2.0
WANTLIB += m pango-1.0 pangocairo-1.0 pangoft2-1.0 pthread z

MASTER_SITES =		http://www.frama-c.com/download/

MODULES =		devel/gettext \
			lang/ocaml

BUILD_DEPENDS =		x11/lablgtk2 devel/ocaml-graph math/graphviz
RUN_DEPENDS =		x11/lablgtk2 math/graphviz

LIB_DEPENDS =		x11/gnome/libgnomecanvas \
			x11/gtksourceview

USE_GMAKE =		Yes
TEST_TARGET =		oracles tests

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	MAKE=${MAKE_PROGRAM} \
			--docdir=${PREFIX}/share/doc/frama-c/

.include <bsd.port.mk>
