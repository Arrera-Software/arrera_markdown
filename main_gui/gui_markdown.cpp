#include "gui_markdown.h"
#include "ui_gui_markdown.h"

gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown)
{
    ui->setupUi(this);
}

gui_markdown::~gui_markdown()
{
    delete ui;
}
