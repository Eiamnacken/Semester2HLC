TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../testmi.c

include(deployment.pri)
qtcAddDeployment()

