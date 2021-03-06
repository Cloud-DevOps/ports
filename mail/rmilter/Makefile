# $OpenBSD: Makefile,v 1.2 2016/12/02 15:17:40 sthen Exp $

COMMENT=	milter for rspamd (also supports clamav, rate-limiting, etc)

GH_ACCOUNT=	vstakhov
GH_PROJECT=	rmilter
GH_TAGNAME=	1.10.0

CATEGORIES=	mail

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c crypto glib-2.0 intl m milter opendkim pcre pthread ssl

MODULES+=	devel/cmake \
		gcc4
MODGCC4_ARCHS=	*

BUILD_DEPENDS=	devel/bison
LIB_DEPENDS=	devel/glib2 \
		devel/pcre \
		mail/sendmail,-libmilter \
		mail/opendkim

CONFIGURE_ARGS=	-DCMAKE_C_OPT_FLAGS="${CFLAGS}" \
		-DMANDIR="${TRUEPREFIX}/man"

NO_TEST=	Yes

# no trailing crlf
post-extract:
	cd ${WRKSRC}; for i in http-parser lc-btrie xxhash; \
	    do echo >> contrib/$$i/CMakeLists.txt; done

pre-configure:
	sed -i -e 's,/etc/,${SYSCONFDIR}/,g' \
	    -e 's,/var/,${LOCALSTATEDIR}/,g' \
	    ${WRKSRC}/rmilter*conf* ${WRKSRC}/src/main.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rmilter
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample \
	    ${WRKSRC}/rmilter-grey.conf \
	    ${PREFIX}/share/examples/rmilter/

.include <bsd.port.mk>
