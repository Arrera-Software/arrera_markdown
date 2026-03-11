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

    index_setting_space_welcome = ui->save_space->indexOf(ui->welcome_space);
    index_setting_add_space = ui->save_space->indexOf(ui->add_space);
    index_setting_del_space = ui->save_space->indexOf(ui->suppr_space);

    ui->arrera_hub->setCurrentIndex(index_main);


    ui->main_quick_widget->rootContext()->setContextProperty("mainWindow", this);
    ui->about_qwidget_setting->rootContext()->setContextProperty("main", this);

    ui->qwidget_space_welcome->rootContext()->setContextProperty("main", this);
    ui->qwidget_space_add->rootContext()->setContextProperty("main", this);
    ui->qwidget_space_del->rootContext()->setContextProperty("main", this);
    ui->qwidget_setting->rootContext()->setContextProperty("main", this);

    ui->qwidget_menu_editor->rootContext()->setContextProperty("main", this);

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
    change_page_editor(1);
}

void gui_markdown::back_setting(){
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::back_about(){
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::view_setting(){
    ui->arrera_hub->setCurrentIndex(index_setting);
    ui->save_space->setCurrentIndex(index_setting_space_welcome);
}

void gui_markdown::change_page_editor(int n){
    QString file;

    switch (n){
    case 1:
        file = "qrc:/qml/widget/editor_menu_one.qml";
        break;
    case 2:
        file = "qrc:/qml/widget/editor_menu_two.qml";
        break;
    default:
        file = "qrc:/qml/widget/editor_menu_one.qml";
        break;
    }

    QMetaObject::invokeMethod(ui->qwidget_menu_editor, [=](){
        ui->qwidget_menu_editor->setSource(QUrl(file));
    }, Qt::QueuedConnection);
}

void gui_markdown::change_page_setting_space(int n){
    switch (n){
    case 1:
        ui->save_space->setCurrentIndex(index_setting_space_welcome);
        break;
    case 2:
        ui->save_space->setCurrentIndex(index_setting_add_space);
        break;
    case 3:
        ui->save_space->setCurrentIndex(index_setting_del_space);
        break;
    default:
        ui->save_space->setCurrentIndex(index_setting_space_welcome);
        break;
    }
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

