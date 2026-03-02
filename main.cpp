#include "main_gui/gui_markdown.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gui_markdown w;
    w.show();
    return a.exec();
}
