# $OpenBSD: Makefile,v 1.23 2016/11/04 21:29:27 jeremy Exp $

COMMENT=	modern, simple and very fast MySQL library for Ruby

DISTNAME=	mysql2-0.4.5
CATEGORIES=	databases

HOMEPAGE=	https://github.com/brianmario/mysql2

MAINTAINER =	Jeremy Evans <jeremy@openbsd.org>

# MIT License
PERMIT_PACKAGE_CDROM=	Yes

MODULES=	lang/ruby

WANTLIB=	crypto mysqlclient ssl z

LIB_DEPENDS=	databases/mariadb

CONFIGURE_STYLE=ruby gem ext

# Regress tests currently don't work, probably because they
# need RSpec2.  They also need a running MySQL server.
TEST_IS_INTERACTIVE = Yes
TEST_DEPENDS=	databases/mariadb,-server \
		${FULLPKGNAME}:${BUILD_PKGPATH}
MODRUBY_TEST=rake rspec

.include <bsd.port.mk>
