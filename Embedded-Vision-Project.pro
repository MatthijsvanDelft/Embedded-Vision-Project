#-------------------------------------------------
#
# Project created by QtCreator 2015-09-23T11:57:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hellovision
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    dip.cpp \
    grabber.cpp \
    handler.cpp \
    car.cpp \
    classifier.cpp

HEADERS  += mainwindow.h \
    dip.h \
    grabber.h \
    handler.h \
    logger.h \
    car.h \
    classifier.h


FORMS    += mainwindow.ui

INCLUDEPATH += "C:\Opencv3.0\Cmake_build\install\include"

LIBS += "C:\Opencv3.0\Cmake_build\install\x86\mingw\bin\libopencv*.dll"\

DISTFILES += \
    logging.conf




