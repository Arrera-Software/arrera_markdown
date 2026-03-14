#ifndef GUI_MARKDOWN_H
#define GUI_MARKDOWN_H

#include <QMainWindow>
#include <QPixmap>
#include <QQmlContext>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QFileDialog>
#include "main_gui/gui_create.h"
#include "librairy/manage_template.h"

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
    Q_INVOKABLE void view_template();
    Q_INVOKABLE void create_document();
    Q_INVOKABLE void back_about();
    Q_INVOKABLE void open_web_page(QString p);
    Q_INVOKABLE void view_setting();
    Q_INVOKABLE void back_setting();
    Q_INVOKABLE void change_page_editor(int n);
    Q_INVOKABLE void change_page_setting_space(int n);

    // Fontion des parametre
    Q_INVOKABLE void add_workspace();
    Q_INVOKABLE void del_workspace();

    // Methode pour la gestion de fichier
    void set_filename(QString f);
    bool create_markdown_document(QString templates=nullptr);

private slots:
    void on_tf_btn_icon_clicked();

    void on_tf_btn_icone_editor_clicked();

private:
    Ui::gui_markdown *ui;
    // Objet de gestion
    CSetting setting_conf;
    QFileSystemModel *model;
    manage_template template_manager;

    // Interface
    gui_create create_ui;
    // Attribut
    bool file_conf_just_created;
    int index_main,index_about,index_setting,index_editor;
    int index_setting_space_welcome,index_setting_add_space,index_setting_del_space;
    int index_welcome_add,index_welcome_space,index_welcome_template;
    QString filename;
    // Methode
    void update_label_view_space();
    void update_list_workspace_welcome();
    void update_tree_welcome();
    bool copy_template();
    QString get_template_folder();
    // Gestion de fichier
    bool save_document();
    void close_document();
};
#endif // GUI_MARKDOWN_H
