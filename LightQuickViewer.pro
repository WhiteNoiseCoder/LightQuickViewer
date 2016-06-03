#-------------------------------------------------
#
# Project created by QtCreator 2016-05-31T12:45:54
#
#-------------------------------------------------

QT       += core gui quick
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LightQuickViewer
TEMPLATE = app


SOURCES += main.cpp\
    shower.cpp \
    follower.cpp \
    viewer.cpp \
    parameters.cpp

HEADERS  += \
    shower.h \
    follower.h \
    viewer.h \
    parameters.h
