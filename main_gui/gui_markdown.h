#ifndef GUI_MARKDOWN_H
#define GUI_MARKDOWN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class gui_markdown;
}
QT_END_NAMESPACE

class gui_markdown : public QMainWindow
{
    Q_OBJECT

public:
    gui_markdown(QWidget *parent = nullptr);
    ~gui_markdown();

private:
    Ui::gui_markdown *ui;
};
#endif // GUI_MARKDOWN_H
