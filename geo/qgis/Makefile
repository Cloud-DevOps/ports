# $OpenBSD: Makefile,v 1.62 2017/02/07 08:20:51 landry Exp $

COMMENT =	desktop geographical information system

DISTNAME =	qgis-2.18.3
EXTRACT_SUFX =	.tar.bz2
CATEGORIES =	geo x11

SHARED_LIBS =	qgis_core	15.0 \
		qgis_app	4.0 \
		qgis_gui	14.0 \
		qgis_analysis	7.0 \
		qgis_server	5.0 \
		qgispython	5.0 \
		qgis_networkanalysis 2.0

HOMEPAGE =	http://www.qgis.org/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

MAINTAINER =	Landry Breuil <landry@openbsd.org>

MASTER_SITES =	${HOMEPAGE}/downloads/

MODULES =	gcc4 \
		devel/cmake \
		devel/gettext \
		lang/python
MODGCC4_ARCHS =	*
MODGCC4_LANGS =	c++

BUILD_DEPENDS =	x11/py-qt4>=4.8.4 \
		security/qca-ossl \
		editors/py-qscintilla \
		devel/bison>=2.4 \
		geo/gdal,-python


RUN_DEPENDS =	x11/py-qt4>=4.8.4 \
		www/py-requests \
		security/qca-ossl \
		geo/gdal,-python \
		databases/py-psycopg2 \
		editors/py-qscintilla \
		devel/desktop-file-utils

LIB_DEPENDS =	${MODPY_LIB_DEPENDS} \
		databases/sqlite3 \
		devel/proj \
		x11/qt4>=4.7.2 \
		x11/qwt \
		www/fcgi \
		editors/qscintilla \
		geo/gdal \
		geo/geos \
		geo/spatialite/libspatialite \
		geo/spatialindex \
		devel/gsl \
		devel/qjson \
		security/qca2 \
		databases/postgresql

WANTLIB += 	ICE SM X11 Xext Xi Xinerama Xrender c expat \
		fontconfig freetype glib-2.0 gobject-2.0 gthread-2.0 lcms m \
		mng png pthread util z proj \
		QtGui QtNetwork QtXml QtSql QtCore QtScript QtSvg \
		QtWebKit gdal geos_c gsl gslcblas pq qwt fcgi qca2 \
		QtTest spatialindex spatialite sqlite3 qscintilla2 qjson
WANTLIB += ${MODPY_WANTLIB} jpeg tiff

CONFIGURE_ENV+=	VERBOSE=1
CONFIGURE_ARGS =	-DWITH_SERVER=TRUE -DWITH_SERVER_PLUGINS=TRUE -DWITH_PYSPATIALITE=TRUE

pre-configure:
		# otherwise takes precedence over systemwide file
		rm -f ${WRKSRC}/cmake/FindIconv.cmake
		${SUBST_CMD} ${WRKSRC}/cmake/Find{GDAL,GEOS,Postgres}.cmake

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/{pixmaps,applications}
		ln -f ${PREFIX}/share/{qgis/images/icons,pixmaps}/qgis-icon.png
		${SUBST_CMD} -o ${SHAREOWN} -g ${SHAREGRP} \
			-c ${WRKSRC}/debian/qgis.desktop \
			${PREFIX}/share/applications/qgis.desktop

.include <bsd.port.mk>
