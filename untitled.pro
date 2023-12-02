QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    emptyelement.cpp \
    field.cpp \
    fieldelement.cpp \
    hundredandthirtylimit.cpp \
    lightelement.cpp \
    main.cpp \
    mainwindow.cpp \
    railelement.cpp \
    sixtylimitelement.cpp \
    switchelement.cpp \
    thirtylimitelement.cpp \
    trainelement.cpp \
    ui_button.cpp \
    ui_engine.cpp \
    ui_field.cpp \
    ui_fieldBoard.cpp

HEADERS += \
    direction.h \
    emptyelement.h \
    field.h \
    fieldelement.h \
    hundredandthirtylimit.h \
    lightelement.h \
    mainwindow.h \
    railelement.h \
    sixtylimitelement.h \
    switchelement.h \
    thirtylimitelement.h \
    trainelement.h \
    ui_button.h \
    ui_engine.h \
    ui_field.h \
    ui_fieldBoard.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
