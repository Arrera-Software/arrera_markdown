#include "gui_markdown.h"
#include "ui_gui_markdown.h"

gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown)
{
    ui->setupUi(this);

    ui->quickWidget->rootContext()->setContextProperty("app", this);
}

gui_markdown::~gui_markdown()
{
    delete ui;
}

void gui_markdown::view_espace(){
    cout << "Espace" << endl;
}

void gui_markdown::create_document(){
    cout << "Creation document" << endl;
}
