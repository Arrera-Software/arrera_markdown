#include "gui_check_orthographe.h"
#include "ui_gui_check_orthographe.h"

gui_check_orthographe::gui_check_orthographe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_check_orthographe)
{
    ui->setupUi(this);
}

gui_check_orthographe::~gui_check_orthographe()
{
    delete ui;
}

bool gui_check_orthographe::insert_text(QString text){
    if (!text.isEmpty()){
        ui->view_orthographe->setReadOnly(false);
        ui->view_orthographe->clear();
        ui->view_orthographe->setPlainText(text);
        ui->view_orthographe->setReadOnly(true);
        return true;
    }return false;
}

void gui_check_orthographe::on_BTN_INSERT_clicked()
{
    QString contenu = ui->view_orthographe->toPlainText();
    this->close();
    emit new_text(contenu);
}


void gui_check_orthographe::on_BTN_CANCEL_clicked()
{
    this->close();
}

