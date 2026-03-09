QT += core gui widgets quick qml quickwidgets quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custom_widget/markdowneditor.cpp \
    custom_widget/markdownhighlighter.cpp \
    main.cpp \
    main_gui/gui_markdown.cpp

HEADERS += \
    custom_widget/markdowneditor.h \
    custom_widget/markdownhighlighter.h \
    main_gui/gui_markdown.h

FORMS += \
    main_gui/gui_markdown.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    asset/resource.qrc
