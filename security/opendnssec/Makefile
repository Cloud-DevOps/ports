# $OpenBSD: Makefile,v 1.8 2016/11/19 12:25:27 sthen Exp $

COMMENT=	open-source turn-key solution for DNSSEC

DISTNAME=	opendnssec-1.4.12

CATEGORIES=	security

HOMEPAGE=	http://www.opendnssec.org/

MAINTAINER=	Patrik Lundin <patrik@sigterm.se>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c crypto iconv ldns lzma m pthread xml2 z

MASTER_SITES=	http://dist.opendnssec.org/source/

LIB_DEPENDS=	converters/libiconv \
		net/ldns/libldns \
		textproc/libxml

TEST_DEPENDS=	security/softhsm

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/opendnssec

CONFIGURE_STYLE= gnu
CONFIGURE_ARGS+= --disable-pedantic

FLAVORS=	sqlite3 mysql
FLAVOR?=	sqlite3

.if ${FLAVOR:Msqlite3}
WANTLIB+=	sqlite3
LIB_DEPENDS+=	databases/sqlite3
.endif

.if ${FLAVOR:Mmysql}
CONFIGURE_ARGS+= --with-database-backend=mysql
WANTLIB+=	mysqlclient_r ssl stdc++
LIB_DEPENDS+=	databases/mariadb
.endif

.if ${FLAVOR:Msqlite3} && ${FLAVOR:Mmysql}
ERRORS+= "Fatal: mutually exclusive flavors: ${FLAVORS}"
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/opendnssec
	cd ${WRKSRC}; \
	${INSTALL_DATA} LICENSE ${PREFIX}/share/doc/opendnssec; \
	${INSTALL_DATA} plugins/simple-dnskey-mailer/simple-dnskey-mailer.sh \
			${PREFIX}/share/opendnssec

.include <bsd.port.mk>
