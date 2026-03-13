#ifndef GUI_CREATE_H
#define GUI_CREATE_H

#include <QDialog>
#include "librairy/csetting.h"

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

private slots:
    void on_btn_create_clicked();

    void on_btn_cancel_create_clicked();

private:
    Ui::gui_create *ui;
    CSetting setting_conf;
    QStringList liste_template;
};

#endif // GUI_CREATE_H
