# $OpenBSD: Makefile,v 1.17 2016/03/11 20:28:30 naddy Exp $

COMMENT =		sensible unix password cracker

DISTNAME =		cracklib-2.9.5
SHARED_LIBS =		crack	0.4	# 11.0
CATEGORIES =		security

HOMEPAGE =		http://sourceforge.net/projects/cracklib/

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=cracklib/}

MODULES =		lang/python \
			devel/gettext

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--without-x \
			--with-default-dict=${PREFIX}/share/cracklib/cracklib-small
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
  
post-install:
			/bin/sh ${WRKSRC}/util/cracklib-format ${WRKSRC}/dicts/cracklib-small | ${WRKSRC}/util/cracklib-packer  \
			${WRKSRC}/dicts/cracklib-small
			${INSTALL_DATA} ${WRKSRC}/dicts/cracklib-small.* ${PREFIX}/share/cracklib

NO_TEST =		Yes
	
.include <bsd.port.mk>
