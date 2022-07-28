QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../build-ex4-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/mylight_adaptor.cpp \
        main.cpp \
        mylight.cpp \
        mylight_adaptor.cpp

RESOURCES += qml.qrc

QT += dbus quick
DBUS_ADAPTORS += mylight.xml

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../build-ex4-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/mylight_adaptor.h \
    mylight.h \
    mylight_adaptor.h

DISTFILES += \
    mylight.xml
