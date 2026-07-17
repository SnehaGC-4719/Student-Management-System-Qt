QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudent.cpp \
    dashboard.cpp \
    deletestudent.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    searchstudent.cpp \
    updatestudent.cpp \
    viewstudents.cpp

HEADERS += \
    addstudent.h \
    dashboard.h \
    deletestudent.h \
    login.h \
    mainwindow.h \
    searchstudent.h \
    updatestudent.h \
    viewstudents.h

FORMS += \
    addstudent.ui \
    dashboard.ui \
    deletestudent.ui \
    login.ui \
    mainwindow.ui \
    searchstudent.ui \
    updatestudent.ui \
    viewstudents.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    style.qss
