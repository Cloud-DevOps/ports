# $OpenBSD: Makefile,v 1.4 2017/01/03 19:16:08 landry Exp $

PKG_ARCH=		*

COMMENT=		UNiversal Office CONVerter

DISTNAME=		unoconv-0.7
REVISION=		2

CATEGORIES=		converters textproc

HOMEPAGE=		http://dag.wiee.rs/home-made/unoconv/

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		http://dag.wieers.com/home-made/unoconv/

MODULES=		lang/python

# see FILESDIR/unoconv.in
# should really be the following, but using the module is easier
# RUN_DEPENDS +=	STEM->=4.9,<4.10:lang/gcc/4.9,-libs
MODULES +=		gcc4
MODGCC4_ARCHS=		*
MODGCC4_LANGS=		c++

NO_BUILD=		Yes
NO_TEST=		Yes

MODPY_VERSION=		${MODPY_DEFAULT_VERSION_3}
MODPY_ADJ_FILES=	unoconv

USE_GMAKE=		Yes

RUN_DEPENDS=		editors/libreoffice

FAKE_FLAGS=		prefix=${TRUEPREFIX} \
			mandir=${TRUEPREFIX}/man

do-install:
	cd ${WRKBUILD} && \
		${SETENV} ${MAKE_ENV} ${_FAKE_SETUP} \
		${MAKE_PROGRAM} ${ALL_FAKE_FLAGS} -f ${MAKE_FILE} install
	cd ${WRKBUILD} && \
		${SETENV} ${MAKE_ENV} ${_FAKE_SETUP} \
		${MAKE_PROGRAM} ${ALL_FAKE_FLAGS} -f ${MAKE_FILE} install-links
	mv ${PREFIX}/bin/unoconv ${PREFIX}/bin/unoconv.py
	${SUBST_CMD} -m 0555 -o ${BINOWN} -g ${BINGRP} \
		-c ${FILESDIR}/unoconv.in \
		${PREFIX}/bin/unoconv

.include <bsd.port.mk>
