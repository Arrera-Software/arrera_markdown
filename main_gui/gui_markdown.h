#ifndef GUI_MARKDOWN_H
#define GUI_MARKDOWN_H

#include <QMainWindow>
#include <QPixmap>
#include <QQmlContext>
#include <QDesktopServices>
#include <QUrl>

#include <iostream>
using namespace std;

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

    Q_INVOKABLE void view_espace();
    Q_INVOKABLE void create_document();
    Q_INVOKABLE void back_about();
    Q_INVOKABLE void open_web_page(QString p);

private slots:
    void on_tf_btn_icon_clicked();

private:
    Ui::gui_markdown *ui;
    int index_main,index_about;
};
#endif // GUI_MARKDOWN_H
