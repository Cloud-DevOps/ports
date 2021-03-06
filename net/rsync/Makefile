# $OpenBSD: Makefile,v 1.77 2016/04/06 21:17:29 sthen Exp $

COMMENT =	mirroring/synchronization over low bandwidth links

DISTNAME =	rsync-3.1.2
REVISION =	0
CATEGORIES =	net
HOMEPAGE =	https://rsync.samba.org/

MAINTAINER =	Marc Espie <espie@openbsd.org>

FLAVORS =	iconv
FLAVOR ?=

# GPLv3
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c

MASTER_SITES =	https://rsync.samba.org/ftp/rsync/src/ \
		http://ftp.funet.fi/pub/mirrors/samba.org/pub/rsync/src/

CONFIGURE_STYLE =gnu
CONFIGURE_ARGS =--with-included-popt \
		--with-included-zlib \
		--with-rsyncd-conf="${SYSCONFDIR}/rsyncd.conf" \
		--with-rsh=/usr/bin/ssh \
		--with-nobody-group=_rsync

.if ${FLAVOR:Miconv}
CONFIGURE_ENV += CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib'
LIB_DEPENDS +=	converters/libiconv
WANTLIB +=	iconv
.endif

DOCDIR =	${PREFIX}/share/doc/rsync

pre-configure:
	${SUBST_CMD} ${WRKSRC}/rsyncd.conf.5 \
		${WRKSRC}/support/rrsync

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/support/rrsync ${PREFIX}/bin

.include <bsd.port.mk>
