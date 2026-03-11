#ifndef GUI_MARKDOWN_H
#define GUI_MARKDOWN_H

#include <QMainWindow>
#include <QPixmap>
#include <QQmlContext>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include "librairy/csetting.h"

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
    Q_INVOKABLE void view_setting();
    Q_INVOKABLE void back_setting();
    Q_INVOKABLE void change_page_editor(int n);
    Q_INVOKABLE void change_page_setting_space(int n);

private slots:
    void on_tf_btn_icon_clicked();

    void on_tf_btn_icone_editor_clicked();

private:
    Ui::gui_markdown *ui;
    CSetting setting_conf;
    bool file_conf_just_created;
    int index_main,index_about,index_setting,index_editor;
    int index_setting_space_welcome,index_setting_add_space,index_setting_del_space;
};
#endif // GUI_MARKDOWN_H
