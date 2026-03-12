#include "gui_create.h"
#include "ui_gui_create.h"

gui_create::gui_create(CSetting &s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_create),
    setting_conf(s)
{
    ui->setupUi(this);

#ifdef Q_OS_MAC
    QPixmap icon(":/icone/icon_mac.png");
    ui->label_icon_create->setPixmap(icon.scaled(50, 50, Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation));
#endif
}

gui_create::~gui_create()
{
    delete ui;
}

void gui_create::setVisible(bool visible){
    QWidget::setVisible(visible);
    if (visible){
        ui->entry_name->clear();
    }
}

void gui_create::on_btn_create_clicked()
{

}


void gui_create::on_btn_cancel_create_clicked()
{
    setVisible(false);
}

