# $OpenBSD: Makefile,v 1.12 2017/01/01 20:58:23 uaa Exp $

COMMENT =	Open On-Chip Debugging

DISTNAME =	openocd-0.9.0
CATEGORIES =	devel

HOMEPAGE =	http://openocd.sourceforge.net/

MAINTAINER =	Sylvestre Gallon <ccna.syl@gmail.com>

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c ftdi jim m pthread usb usb-1.0

MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=openocd/}
EXTRACT_SUFX =	.tar.bz2

CONFIGURE_STYLE = gnu
CONFIGURE_ARGS = --disable-werror \
		--disable-wextra \
		--enable-armjtagew \
		--enable-at91rm9200 \
		--enable-ep93xx \
		--enable-ftdi \
		--enable-jlink \
		--enable-presto_libftdi \
		--enable-rlink \
		--enable-usbprog \
		--enable-vsllink \
		--enable-ulink \
		--enable-stlink \
		--enable-ti-icdi \
		--enable-usb-blaster-2 \
		--enable-osbdm \
		--enable-opendous \
		--enable-aice \
		--enable-buspirate \
		--disable-internal-jimtcl

CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/jim" \
		LDFLAGS="-L${LOCALBASE}/lib -pthread"

LIB_DEPENDS =	devel/libftdi>=0.20 \
		lang/jimtcl>=0.75

USE_GMAKE =	Yes
# Fails to link main.o and libopenocd.a properly resulting in undefined reference in the gdb_server.o
USE_LIBTOOL =	gnu
NO_TEST =	Yes

.include <bsd.port.mk>
