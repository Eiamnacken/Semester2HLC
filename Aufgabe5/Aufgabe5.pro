TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    savewords.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    savewords.h

