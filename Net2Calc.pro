TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../eigen-git-mirror

SOURCES +=  source/main.cpp \
    source/circuitdesign.cpp \
    source/cktcapacitor.cpp \
    source/cktelemactive.cpp \
    source/cktelement.cpp \
    source/cktelempassive.cpp \
    source/cktinductor.cpp \
    source/cktresistor.cpp \
    source/cktvoltsource.cpp

HEADERS += \
    source/circuitdesign.h \
    source/cktcapacitor.h \
    source/cktelemactive.h \
    source/cktelement.h \
    source/cktelempassive.h \
    source/cktinductor.h \
    source/cktresistor.h \
    source/cktvoltsource.h \
    source/netdefs.h
