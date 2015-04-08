TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ceasar.c \
    main.c \
    anacae.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ceasar.h \
    anacae.h

