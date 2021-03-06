# $OpenBSD: Makefile,v 1.144 2016/11/12 10:32:28 ajacoutot Exp $

COMMENT-main=		GNOME desktop meta-package (base installation)
COMMENT-extras=		GNOME desktop meta-package (full installation)

V=			3.22.2
PKGNAME=		gnome-${V}

PKGNAME-main=		gnome-${V}
PKGNAME-extras=		gnome-extras-${V}

REVISION-main=		0

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

MULTI_PACKAGES=		-main -extras

# XXX should be a RUN_DEPENDS of x11/gnome/{libgnome-keyring,libsecret} but that
# would create dependency loops:
# libsecret -> gnome-keyring -> pinentry -> libsecret
# libsecret -> gnome-keyring -> gcr -> gnupg2 -> pinentry -> gcr
# org.freedesktop.secrets
# (XXX add "gnome-keyring-*|ksecretsservice-*" when implemented)
RUN_DEPENDS-main +=	x11/gnome/keyring

# remove when we don't use gtk+2 apps in GNOME
# Gtk-Message: Failed to load module "canberra-gtk-module"
RUN_DEPENDS-main +=	audio/libcanberra,-gtk

# sync with gnome-desktop version
RUN_DEPENDS-main +=	x11/gnome/desktop=${V}

# minimal dependencies for a working desktop
RUN_DEPENDS-main +=	x11/gnome/control-center \
			x11/gnome/nautilus \
			x11/gnome/session \
			x11/gnome/terminal

# gnome-classic.session
RUN_DEPENDS-main +=	x11/gnome/shell-extensions

# GNOME spooler is CUPS (gnome-printers-panel in gnome-control-center)
# add gtk+{2,3}-cups so that gtkprint() can see native CUPS printers;
# add gtk+3-cloudprint, gnome-online-accounts is already a dependency
RUN_DEPENDS-main +=	x11/gtk+2,-cups
RUN_DEPENDS-main +=	x11/gtk+3,-cups
RUN_DEPENDS-main +=	x11/gtk+3,-cloudprint

# add commonly used utilities
RUN_DEPENDS-main +=	x11/gnome/calculator \
			x11/gnome/eog \
			x11/gnome/file-roller \
			x11/gnome/gedit \
			x11/xdg-user-dirs-gtk

# former gnome-utils
RUN_DEPENDS-main +=	x11/gnome/baobab \
			x11/gnome/dictionary \
			x11/gnome/font-viewer \
			x11/gnome/screenshot

# gnome-initial-setup (welcome-tour), gnome-getting-started-docs
RUN_DEPENDS-main +=	x11/gnome/initial-setup

# we already depend on samba, libgdata and gnome-online-accounts
RUN_DEPENDS-main +=	x11/gnome/gvfs,-goa, \
			x11/gnome/gvfs,-google, \
			x11/gnome/gvfs,-smb,

# "Make it fancy!"
RUN_DEPENDS-main +=	x11/gnome/bijiben \
			x11/gnome/calendar \
			x11/gnome/contacts \
			x11/gnome/documents \
			x11/gnome/eog-plugins \
			x11/gnome/gedit-plugins \
			x11/gnome/grilo-plugins \
			x11/gnome/maps \
			x11/gnome/music \
			x11/gnome/nautilus-sendto \
			x11/gnome/photos \
			x11/gnome/seahorse \
			x11/gnome/seahorse-nautilus \
			x11/gnome/seahorse-sharing \
			x11/gnome/sushi \
			x11/gnome/system-monitor \
			x11/gnome/todo \
			x11/gnome/tweak-tool \
			x11/gnome/weather

RUN_DEPENDS-extras +=	STEM-=${V}:${BASE_PKGPATH},-main \
			audio/rhythmbox \
			graphics/simple-scan \
			mail/evolution \
			mail/evolution-rss \
			sysutils/deja-dup \
			www/epiphany \
			x11/gnome/empathy \
			x11/gnome/totem \
			x11/gnome/vinagre

.include <bsd.port.mk>
