#include "gui_add_table.h"
#include "ui_gui_add_table.h"

gui_add_table::gui_add_table(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_add_table)
{
    ui->setupUi(this);
}

gui_add_table::~gui_add_table()
{
    delete ui;
}

void gui_add_table::on_IDC_VALIDATE_clicked()
{
    int ligne = ui->NB_LIGNE->value();
    int colone = ui->NB_COLONE->value();

    emit create_table(ligne,colone);

    this->close();
}


void gui_add_table::on_IDC_CANCEL_clicked()
{
    this->close();
}
