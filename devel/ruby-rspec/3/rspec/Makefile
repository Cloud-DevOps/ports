#  $OpenBSD: Makefile,v 1.8 2016/07/04 07:34:28 jasper Exp $

COMMENT =		ruby framework for Behaviour Driven Development
V =			3.5.0
DISTNAME =		rspec-$V

BUILD_DEPENDS = 	${RUN_DEPENDS}
RUN_DEPENDS = 		devel/ruby-rspec/3/core,${MODRUBY_FLAVOR}>=$V \
			devel/ruby-rspec/3/expectations,${MODRUBY_FLAVOR}>=$V \
			devel/ruby-rspec/3/mocks,${MODRUBY_FLAVOR}>=$V

SUBST_VARS =		MODRUBY_PREFIX

.include <bsd.port.mk>
