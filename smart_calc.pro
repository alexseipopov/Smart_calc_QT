QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    s21_action.c \
    s21_action_function.c \
    s21_helper.c \
    s21_parse_string.c \
    s21_push_manager.c \
    s21_resolve_structure.c \
    s21_stack.c

HEADERS += \
    graph.h \
    mainwindow.h \
    qcustomplot.h \
    s21_polish.h

FORMS += \
    graph.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
