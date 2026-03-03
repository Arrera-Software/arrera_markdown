#include "main_gui/gui_markdown.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    #ifdef Q_OS_LINUX
        qunsetenv("QT_QPA_PLATFORMTHEME");

        qputenv("QT_QPA_PLATFORMTHEME", "xdgdesktopportal");
    #endif

    QApplication a(argc, argv);
    gui_markdown w;

    #ifdef Q_OS_LINUX
        w.setWindowIcon(QIcon(":/icone/icon_linux.png"));
    #endif

    #ifdef Q_OS_WIN
        w.setWindowIcon(QIcon(":/icone/icon_linux.png"));
    #endif

    w.show();
    return a.exec();
}
