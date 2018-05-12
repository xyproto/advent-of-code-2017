TEMPLATE = app
CONFIG += console
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    main.cpp \
    tree.cpp

DISTFILES += \
    README.md \
    input.txt \
    input2.txt

HEADERS += \
    tree.h

INCLUDEPATH += ../include
