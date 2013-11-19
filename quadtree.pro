
TEMPLATE = app
TARGET = 
DESTDIR = ../quadtree
DEPENDPATH += . 
INCLUDEPATH += . 
LIBS += -lIL
OBJECTS_DIR += .tmp/objs
MOC_DIR += .tmp/moc
FORMS +=   Source/quadtree.ui
UI_HEADERS_DIR += .tmp/UISrc
UI_SOURCES_DIR += .tmp/UISrc

HEADERS += Source/CMath.h Source/CBaseQGL.h Source/COrthoQGL.h Source/CDebug.h Source/quadtreeTest.h Source/mainWindow.h Source/CImage.h Source/CBalls.h Source/CQuadtree.h
SOURCES += Source/CMath.cpp \
		   Source/mainWindow.cpp \
		   Source/quadtreeTest.cpp \
		   Source/mainApp.cpp \
		   Source/CImage.cpp \
		   Source/CBalls.cpp \
		   Source/CQuadtree.cpp
	   
QT += opengl
CONFIG += opengl
