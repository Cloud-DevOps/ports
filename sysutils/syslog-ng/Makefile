# $OpenBSD: Makefile,v 1.55 2016/05/01 11:19:09 steven Exp $

COMMENT=	syslogd replacement

V =		3.7.2
REL =		3.7
DISTNAME =	syslog-ng-$V
CATEGORIES =	sysutils

MAINTAINER =	Steven Mestdagh <steven@openbsd.org>

HOMEPAGE =	http://www.balabit.com/network-security/syslog-ng/

# GPL v2
PERMIT_PACKAGE_CDROM =		Yes

MASTER_SITES =	http://github.com/balabit/syslog-ng/releases/download/${DISTNAME}/

SHARED_LIBS =	syslog-ng		3.0 \
		syslog-ng-${REL}	3.0

MODULES =	devel/gettext

WANTLIB =	c m pcre crypto ssl evtlog dbi ivykis pthread \
		glib-2.0 gmodule-2.0 gthread-2.0 json-c

LIB_DEPENDS =	devel/glib2 \
		devel/json-c \
		devel/libivykis \
		sysutils/eventlog \
		databases/libdbi

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--disable-tcp-wrapper \
			--with-pidfile-dir=/var/run \
			--enable-json \
			--with-libmongo-client=no \
			--with-librabbitmq-client=no \
			--disable-python \
			--disable-mongodb \
			--disable-amqp \
			--disable-stomp \
			--disable-geoip \
			--without-libnet \
			--with-ivykis=system \
			--enable-sql \
			--enable-manpages
CONFIGURE_ENV +=	OPENSSL_CFLAGS="-I/usr/include/openssl" \
			OPENSSL_LIBS="-lssl -lcrypto" \
			LIBDBI_CFLAGS="-I/usr/include/openssl" \
			LIBDBI_LIBS="-ldbi"
# json-c only installs libjson-c.pc; syslog-ng checks for libjson.pc
CONFIGURE_ENV +=	JSON_C_CFLAGS="`pkg-config json-c --cflags`" \
			JSON_C_LIBS="`pkg-config json-c --libs`"
USE_GMAKE =	Yes
USE_GROFF =	Yes

SYSCONFDIR =	${BASESYSCONFDIR}/syslog-ng
CFLAGS +=	-I${LOCALBASE}/include

SUBST_VARS +=	V

DOC =		${PREFIX}/share/doc/syslog-ng/
EXAMPLES =	${PREFIX}/share/examples/syslog-ng/

pre-install:
	cd ${WRKSRC}/doc/man && perl -pi -e 's@/opt/syslog\\-ng/etc/syslog\\-ng/@${SYSCONFDIR:S/-/\\-/g}/@g' *.[158]

post-install:
	mv ${WRKINST}/etc/syslog-ng ${EXAMPLES}
	${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf \
		${EXAMPLES}/syslog-ng.conf.openbsd
	rm -rf ${PREFIX}/share/{include,tools,xsd}
	rm -f ${PREFIX}/lib/syslog-ng/*.{a,la}

.include <bsd.port.mk>
