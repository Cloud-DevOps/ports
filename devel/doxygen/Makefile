# $OpenBSD: Makefile,v 1.39 2016/12/23 15:23:11 jca Exp $

# Memory hog, stuck for days on the same file (configoptions.cpp) during build.
# XXX check with different optimizer level? see doc/install.doc
NOT_FOR_ARCHS=	m88k sh
BROKEN-alpha=	.got subsegment exceeds 64K

COMMENT=	source code documentation generator tool

VERSION=	1.8.12
DISTNAME=	doxygen-${VERSION}.src
PKGNAME=	doxygen-${VERSION}
REVISION=	1

CATEGORIES=	devel textproc

HOMEPAGE=	http://www.doxygen.org/

MAINTAINER=	Rafael Sadowski <rafael@sizeofvoid.org>

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c iconv m pthread stdc++ xapian z

MASTER_SITES=	http://ftp.stack.nl/pub/users/dimitri/ \
		ftp://ftp.stack.nl/pub/users/dimitri/

LIB_DEPENDS=	converters/libiconv \
		databases/xapian-core

MODULES=	devel/cmake \
		lang/python

MODPY_RUNDEP=	No

.if ${MACHINE_ARCH} == "mips64" || ${MACHINE_ARCH} == "mips64el"
# ld(1) fails
CONFIGURE_ARGS+=-Denglish_only:Bool=ON
.endif

BUILD_DEPENDS+=	devel/bison

RUN_DEPENDS+=	print/ghostscript/gnu \
		math/graphviz

CONFIGURE_ARGS+=-Dbuild_doc:Bool=ON
CONFIGURE_ARGS+=-Dbuild_app:Bool=ON
CONFIGURE_ARGS+=-Dbuild_search:Bool=ON

WRKDIST=	${WRKDIR}/doxygen-${VERSION}

NO_TEST=	Yes

.include <bsd.port.mk>
