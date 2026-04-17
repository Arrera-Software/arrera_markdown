#include "gui_export.h"
#include "ui_gui_export.h"

gui_export::gui_export(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_export)
{
    ui->setupUi(this);
}

gui_export::~gui_export()
{
    delete ui;
}

void gui_export::on_IDC_MARKDOWN_clicked()
{
    emit export_document("md");
    this->close();
}


void gui_export::on_IDC_PDF_clicked()
{
    emit export_document("pdf");
    this->close();
}


void gui_export::on_IDC_CANCEL_clicked()
{
    this->close();
}

