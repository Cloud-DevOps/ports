# $OpenBSD: Makefile,v 1.16 2017/01/25 20:31:52 sthen Exp $

# if building tools, N.B. https://github.com/nghttp2/nghttp2/pull/789 /
# https://patch-diff.githubusercontent.com/raw/nghttp2/nghttp2/pull/789.diff
COMMENT=	library for HTTP/2

V=		1.19.0
DISTNAME=	nghttp2-$V

SHARED_LIBS +=	nghttp2              0.9     # 26.0

CATEGORIES=	www

HOMEPAGE=	https://nghttp2.org/

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	https://github.com/tatsuhiro-t/nghttp2/releases/download/v$V/

SEPARATE_BUILD=		Yes

CONFIGURE_STYLE=	gnu
# - examples have conflicts (libevent, libevent2, libev)
# - hpack-tools require a C++11 compiler (array)
# Both of these pull in additional libraries; deliberately trying to keep
# dependencies light for this port, to avoid pulling in the world, and
# to avoid restricting arch.
CONFIGURE_ARGS+=	--disable-examples \
			--disable-hpack-tools \
			--disable-python-bindings \
			--without-libxml2

# Tests don't do much unless cunit is present at configure time.
# As above, don't pull this in, to avoid restricting arch.
pre-test:
	@if ! [ -f ${LOCALBASE}/lib/libcunit.a ]; then echo; \
	    echo "====================================================="; \
	    echo "To run tests, install the cunit package and re-build."; \
	    echo "Dependency is not forced to avoid restricting arches."; \
	    echo "====================================================="; \
	    echo; exit 1; \
	fi

.include <bsd.port.mk>
