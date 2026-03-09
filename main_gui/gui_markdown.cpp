#include "gui_markdown.h"
#include "ui_gui_markdown.h"


gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown)
{
    ui->setupUi(this);

    index_main = ui->arrera_hub->indexOf(ui->main);
    index_about = ui->arrera_hub->indexOf(ui->about);
    index_setting = ui->arrera_hub->indexOf(ui->setting);
    index_editor = ui->arrera_hub->indexOf(ui->editor);

    index_setting_main = ui->markdown_setting->indexOf(ui->setting_main);
    index_setting_state = ui->markdown_setting->indexOf(ui->setting_template);
    index_setting_template = ui->markdown_setting->indexOf(ui->setting_template);

    ui->arrera_hub->setCurrentIndex(index_main);


    ui->main_quick_widget->rootContext()->setContextProperty("mainWindow", this);
    ui->about_qwidget_setting->rootContext()->setContextProperty("main", this);
    ui->setting_qwidget_menu->rootContext()->setContextProperty("main", this);

    #ifdef Q_OS_MAC
    QPixmap icon(":/icone/icon_mac.png");
    ui->tf_btn_icon->setIcon(icon.scaled(50, 50, Qt::KeepAspectRatio,
                                        Qt::SmoothTransformation));
    ui->about_label_icon->setPixmap(icon.scaled(
        QSize(512,512),
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->tf_btn_icone_editor->setIcon(icon.scaled(50, 50, Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation));

    #endif
    #ifdef Q_OS_LINUX
    QPixmap icon(":/icone/icon_linux.png");
    ui->about_label_icon->setPixmap(icon.scaled(
        QSize(512,512),
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
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
    ui->arrera_hub->setCurrentIndex(index_editor);
}

void gui_markdown::back_setting(){
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::back_about(){
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::view_setting(){
    ui->arrera_hub->setCurrentIndex(index_setting);
}

void gui_markdown::on_tf_btn_icon_clicked()
{
    ui->arrera_hub->setCurrentIndex(index_about);
}

void gui_markdown::open_web_page(QString p){
    QUrl url(p);
    QDesktopServices::openUrl(url);
}


void gui_markdown::on_tf_btn_icone_editor_clicked()
{
    ui->arrera_hub->setCurrentIndex(index_main);
}

