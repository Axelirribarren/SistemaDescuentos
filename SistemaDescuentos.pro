TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cliente.cpp \
        descuentoa.cpp \
        descuentob.cpp \
        descuentoc.cpp \
        estrategiadescuento.cpp \
        gestor.cpp \
        main.cpp

HEADERS += \
    cliente.h \
    descuentoa.h \
    descuentob.h \
    descuentoc.h \
    estrategiadescuento.h \
    gestor.h
