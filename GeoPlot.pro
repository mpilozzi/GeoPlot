#-------------------------------------------------
#
# Project created by QtCreator 2017-02-06T16:06:46
#
#-------------------------------------------------

QT       += core gui designer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeoPlot
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=  src/main.cpp \
            src/mainwindow.cpp \
            src/widget/geoplotwidget.cpp \
            src/widget/targets/target.cpp \
            src/widget/targets/torpedo.cpp \
            src/test/test.cpp \
            src/widget/geoscene.cpp \
            src/widget/geoview.cpp \
            src/widget/drawingtool/drawingtool.cpp \
    src/widget/drawingtool/olygon.cpp \
    src/widget/drawingtool/vertex.cpp \
    src/widget/geoplot.cpp \
    src/widget/geoplotplugin.cpp \
    src/widget/targets/combatantlinecarrier.cpp \
    src/widget/targets/backgrounddrawer.cpp \
    src/widget/dropdown.cpp \
    src/widget/units/units.cpp \
    src/widget/drawingtool/bitmap.cpp \
    src/widget/drawingtool/circle.cpp \
    src/widget/drawingtool/measuringtool.cpp \
    src/widget/drawingtool/text.cpp \
    src/widget/targets/targetpositiondot.cpp

HEADERS  += src/mainwindow.h \
            src/widget/geoplotwidget.h \
            src/widget/targets/target.h \
            src/widget/targets/torpedo.h \
            src/test/test.h \
            src/widget/geoscene.h \
    src/widget/geoview.h \
    src/widget/drawingtool/drawingtool.h \
    src/widget/drawingtool/olygon.h \
    src/widget/drawingtool/vertex.h \
    src/widget/geoplot.h \
    src/widget/geoplotplugin.h \
    src/widget/drawingtool/drawingtoolstateenum.h \
    src/widget/targets/targetenums.h \
    src/widget/targets/combatantlinecarrier.h \
    src/widget/targets/backgrounddrawer.h \
    src/widget/dropdown.h \
    src/widget/units/units.h \
    src/widget/drawingtool/bitmap.h \
    src/widget/drawingtool/circle.h \
    src/widget/drawingtool/measuringtool.h \
    src/widget/drawingtool/text.h \
    src/widget/targets/targetpositiondot.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
