#-------------------------------------------------
#
# Project created by QtCreator 2014-10-22T11:29:09
#
#-------------------------------------------------

QT       += core

QT       += gui

QT      += opengl

TARGET = Life
CONFIG   += console
CONFIG   -= app_bundle

LIBS += libglut
LIBS += libopengl32
LIBS += libfreeglut
LIBS += libglu32

TEMPLATE = app
SOURCES += main.cpp \
    ant.cpp \
    b_ant.cpp \
    r_ant.cpp \
    b_base.cpp \
    base.cpp \
    block.cpp \
    food.cpp \
    r_base.cpp \
    scene.cpp

HEADERS += \
    ant.h \
    b_ant.h \
    r_ant.h \
    b_base.h \
    base.h \
    block.h \
    food.h \
    r_base.h \
    scene.h
