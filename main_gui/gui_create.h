#ifndef GUI_CREATE_H
#define GUI_CREATE_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "librairy/csetting.h"

#include <iostream>
using namespace std;

namespace Ui {
class gui_create;
}

class gui_create : public QDialog
{
    Q_OBJECT

public:
    explicit gui_create(CSetting &s,QWidget *parent = nullptr);
    ~gui_create();
    void view_normal(bool visible);
    void view_with_template(bool visible,QString t_file);
    void setListTemplate(QStringList liste);

signals:
    void s_create(QString path,QString templates=nullptr);

private slots:
    void on_btn_create_clicked();

    void on_btn_cancel_create_clicked();

private:
    Ui::gui_create *ui;
    QString template_file;
    CSetting setting_conf;
    QStringList liste_template;
    bool with_template;
};

#endif // GUI_CREATE_H
