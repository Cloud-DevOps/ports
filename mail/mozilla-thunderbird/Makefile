# $OpenBSD: Makefile,v 1.235 2017/02/05 19:50:51 landry Exp $

COMMENT-main =		Mozilla e-mail, rss and usenet client
COMMENT-lightning =	Mozilla Thunderbird calendar extension

# Don't forget to bump mail/thunderbird-i18n after updates.

MOZILLA_VERSION =	45.7.0
MOZILLA_BRANCH =	release
MOZILLA_PROJECT =	thunderbird
MOZILLA_CODENAME =	mail
EXTRACT_SUFX =		.tar.xz
REVISION-main=	0

MULTI_PACKAGES =	-main -lightning
PKGNAME-main =		${PKGNAME}
PKGNAME-lightning =	lightning-4.7.7.0
EPOCH-lightning =	0

HOMEPAGE =	http://www.mozilla.org/thunderbird/

SO_VERSION =	31.0
# NOTE: Must bump minor version if any shlib's are removed from the
# components dir to avoid pkg_add -r issues.

MOZILLA_LIBS = ldap60 ldif60 lgpllibs prldap60 xul calbasecomps

CATEGORIES=	mail news

# MPL
PERMIT_PACKAGE_CDROM=	Yes

MODULES =	www/mozilla devel/gettext lang/python
MODPY_RUNDEP =	No

# necessary glue to build with the correct compiler after fx 17
MODULES +=		gcc4 lang/clang
MODGCC4_ARCHS =		powerpc sparc64 alpha
MODGCC4_LANGS =		c c++
MODCLANG_ARCHS =	amd64 i386
MODCLANG_LANGS =	c c++

MOZILLA_USE_BUNDLED_LIBEVENT =	Yes

NO_TEST =	Yes

CONFIGURE_STYLE =	gnu

# SQLITE_CFLAGS is set from pkgconfig, but it's not used for all files that need it, e.g.
# mailnews/build/nsMailModule.cpp pulls in mailnews/extensions/fts3/src/nsFts3Tokenizer.h
# and .../fts3/src/fts3_tokenizer.h which fails to find sqlite3.h.
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include"

LIB_DEPENDS-lightning = STEM->=${MOZILLA_VERSION:S/b/beta/}:${BUILD_PKGPATH},-main
WANTLIB-lightning =	lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/xul \
			c m stdc++ nspr4 plc4 plds4 pthread

# build lightning xpi
CONFIGURE_ARGS +=	--enable-calendar
# relies on pulseaudio for sound and broken at runtime
CONFIGURE_ARGS +=	--disable-webrtc

CONFIGURE_ARGS +=	--disable-gstreamer

# to be able to link when building with clang on i386
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ARGS +=       --disable-debug-symbols
.endif

# bug #1064665
LIB_DEPENDS +=	textproc/icu4c
CONFIGURE_ARGS += --with-system-icu
WANTLIB += icudata icui18n icuuc

# bug 857628
CONFIGURE_ARGS +=	--enable-pie

ALL_TARGET =	default

GNU_ARCH =	${MACHINE_ARCH:S/amd64/x86_64/}
# guid for gdata-provider comes from em:id in install.rdf
GUIDS =	gdata-provider {a62ef8ec-5fdc-40c2-873c-223b8a6925cc} #\
#	lightning {e2fda1a4-762b-4020-b5ad-a41df1933103}

EXTDIR =	${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/extensions/

CONFIGURE_ENV+=MOZCONFIG=${WRKSRC}/mozilla/.mozconfig
# MOZCONFIG is mandatory now even if empty ?
post-patch:
	touch ${WRKSRC}/mozilla/.mozconfig

post-install:
.for xpi guid in ${GUIDS}
	cp ${WRKBUILD}/dist/xpi-stage/${xpi}*.xpi ${EXTDIR}/${guid}.xpi
.endfor
	# lightning cant be used packed as a zip because it contains a binary component
	# (libcalbasecomps.so) that the system wouldnt be able to load...
	mv ${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/distribution/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103} \
		${EXTDIR}
	rmdir ${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/distribution/extensions/
	# install prefs
	${SUBST_DATA} ${FILESDIR}/all-openbsd.js \
		${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/defaults/pref/all-openbsd.js
	# install desktop file
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/ ; \
	${SUBST_DATA} ${FILESDIR}/${MOZILLA_PROJECT}.desktop \
		${PREFIX}/share/applications/${MOZILLA_PROJECT}.desktop ; \
	# install icon for desktop file
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/chrome/icons/default/default256.png \
		${PREFIX}/share/pixmaps/${MOZILLA_PROJECT}.png

	# remove useless empty dirs ?
	rm -Rf ${PREFIX}/lib/${MOZILLA_PROJECT}-${MOZILLA_VER}/modules/

.include <bsd.port.mk>
