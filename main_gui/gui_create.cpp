#include "gui_create.h"
#include "ui_gui_create.h"

gui_create::gui_create(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_create)
{
    ui->setupUi(this);
}

gui_create::~gui_create()
{
    delete ui;
}
