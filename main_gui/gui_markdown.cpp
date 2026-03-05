#include "gui_markdown.h"
#include "ui_gui_markdown.h"


gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown)
{
    ui->setupUi(this);

    ui->main_quick_widget->rootContext()->setContextProperty("mainWindow", this);
    #ifdef Q_OS_MAC
    ui->tf_btn_icon->setIcon(QPixmap(":/icone/icon_mac.png").
                                 scaled(50, 50, Qt::KeepAspectRatio,
                                        Qt::SmoothTransformation));
    #endif
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

void gui_markdown::on_tf_btn_icon_clicked()
{
    cout << "A Propos" << endl;
}

