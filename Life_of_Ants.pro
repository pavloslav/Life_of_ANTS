TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = Life

LIBS += libopengl32
LIBS += libfreeglut
LIBS += libglu32
LIBS += -static-libgcc -static-libstdc++

SOURCES += main.cpp \
    ant.cpp \
    base.cpp \
    block.cpp \
    food.cpp \
    scene.cpp \
    colony.cpp \
    colonyblock.cpp

HEADERS += \
    ant.h \
    base.h \
    block.h \
    food.h \
    scene.h \
    colony.h \
    colonyblock.h
