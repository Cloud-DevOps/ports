# $OpenBSD: Makefile,v 1.58 2015/07/19 08:22:14 jca Exp $

COMMENT=		IRC proxy to connect to AIM, ICQ, Jabber and Yahoo

DISTNAME=		bitlbee-3.4
REVISION=		0
CATEGORIES=		net

HOMEPAGE=		http://bitlbee.org/

MAINTAINER=		Tom Doherty <tom@singlesecond.com>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB +=		c m pthread glib-2.0 gmodule-2.0 ssl crypto

MASTER_SITES=		http://get.bitlbee.org/src/

MODULES=		devel/gettext

DB_DIR?=		/var/bitlbee
ETCDIR=			${SYSCONFDIR}/bitlbee
EXAMPLEDIR=		${PREFIX}/share/examples/bitlbee
DOCS=			${WRKSRC}/doc/user-guide/user-guide.html
DOCDIR=			${PREFIX}/share/doc/bitlbee/

BUILD_DEPENDS=		textproc/xmlto
LIB_DEPENDS=		devel/glib2

CONFIGURE_STYLE=	simple
CONFIGURE_ARGS+=	--bindir=${PREFIX}/libexec \
			--mandir=${PREFIX}/man \
			--config=${DB_DIR} \
			--etcdir=${ETCDIR} \
			--ssl=openssl \
			--pie=0

USE_GMAKE=		Yes
MAKE_ENV=		"CC=${CC}" "CFLAGS=${CFLAGS}"
FAKE_FLAGS=		ETCDIR=${EXAMPLEDIR}
FAKE_TARGET=		install install-etc
SUBST_VARS=		DB_DIR

FLAVORS =		libpurple otr
FLAVOR ?=

.if ${FLAVOR:Mlibpurple}
CONFIGURE_ARGS +=	--purple=1
LIB_DEPENDS +=		net/pidgin,-libpurple
WANTLIB +=		purple
.endif
.if ${FLAVOR:Motr}
CONFIGURE_ARGS +=	--otr=1
LIB_DEPENDS +=		security/libotr>=4.0.0 security/libgcrypt
WANTLIB +=		gcrypt otr
.endif

NO_TEST=		Yes

# don't hide compile command lines
pre-configure:
	find ${WRKSRC} -name Makefile | \
	    xargs perl -pi -e 's,@\$$\(CC\),\$$(CC),g'

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${DOCS} ${DOCDIR}

.include <bsd.port.mk>
