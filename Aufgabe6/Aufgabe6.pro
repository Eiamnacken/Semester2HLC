TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    playlist.c \
    list.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    list.h

