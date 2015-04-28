TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    tasks.c \
    queue.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    queue.h \
    tasks.h

