#include "main_gui/gui_markdown.h"

#include <QApplication>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    #ifdef Q_OS_LINUX
        qunsetenv("QT_QPA_PLATFORMTHEME");

        qputenv("QT_QPA_PLATFORMTHEME", "xdgdesktopportal");
    #endif

    QApplication a(argc, argv);
    gui_markdown w;

    QQuickStyle::setStyle("Material");

    #ifdef Q_OS_LINUX
        w.setWindowIcon(QIcon(":/icone/icon_linux.png"));
    #endif

    #ifdef Q_OS_WIN
        w.setWindowIcon(QIcon(":/icone/icon_linux.png"));

    #endif

    #ifdef Q_OS_MAC
        w.setWindowIcon(QIcon(":/icone/icon_mac.png"));
    #endif

    w.show();
    return a.exec();
}
