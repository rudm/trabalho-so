#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T18:23:09
#
#-------------------------------------------------

QT       += core gui widgets

CONFIG += C++11

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

TARGET = trabalho-so
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    processo.cpp \
    util.cpp \
    nucleo.cpp \
    filaaptos.cpp \
    processador.cpp \
    wdgnucleo.cpp \
    wdgprocesso.cpp \
    updategui.cpp

HEADERS  += mainwindow.h \
    processo.h \
    util.h \
    nucleo.h \
    filaaptos.h \
    processador.h \
    wdgnucleo.h \
    wdgprocesso.h \
    updategui.h

FORMS    += mainwindow.ui \
    wdgnucleo.ui \
    wdgprocesso.ui
