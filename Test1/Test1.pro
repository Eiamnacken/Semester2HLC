TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ../../../Downloads/testmi.c

include(deployment.pri)
qtcAddDeployment()

