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
    void setVisible(bool visible) override;
    void setListTemplate(QStringList liste);

signals:
    void s_create(QString path);

private slots:
    void on_btn_create_clicked();

    void on_btn_cancel_create_clicked();

private:
    Ui::gui_create *ui;
    CSetting setting_conf;
    QStringList liste_template;
};

#endif // GUI_CREATE_H
