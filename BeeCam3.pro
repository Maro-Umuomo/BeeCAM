QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DuLibVlcWrapper.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    DuLibVlcWrapper.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += $$PWD/3rdParty/include

LIBS += -L$$PWD/3rdParty
LIBS += -laxvlc -llibvlc -llibvlccore -lnpvlc

RESOURCES += \
    sdp.qrc

DISTFILES += \
    metapreview.mp4
