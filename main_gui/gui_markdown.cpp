#include "gui_markdown.h"
#include "ui_gui_markdown.h"


gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown),setting_conf("arrera_markdown"),create_ui(setting_conf)
{
    ui->setupUi(this);

    file_conf_just_created = setting_conf.getFileCreated();

    if (file_conf_just_created){
        ui->arrera_hub->setCurrentIndex(index_setting);
        ui->save_space->setCurrentIndex(index_setting_space_welcome);
        ui->welcome_arrera_hub->setCurrentIndex(index_welcome_add);
        copy_template();
    }

    index_main = ui->arrera_hub->indexOf(ui->main);
    index_about = ui->arrera_hub->indexOf(ui->about);
    index_setting = ui->arrera_hub->indexOf(ui->setting);
    index_editor = ui->arrera_hub->indexOf(ui->editor);

    index_setting_space_welcome = ui->save_space->indexOf(ui->welcome_space);
    index_setting_add_space = ui->save_space->indexOf(ui->add_space);
    index_setting_del_space = ui->save_space->indexOf(ui->suppr_space);

    index_welcome_add = ui->welcome_arrera_hub->indexOf(ui->add_welcome);
    index_welcome_space = ui->welcome_arrera_hub->indexOf(ui->space_welcome);
    index_welcome_template = ui->welcome_arrera_hub->indexOf(ui->template_welcome);

    ui->arrera_hub->setCurrentIndex(index_main);


    ui->main_quick_widget->rootContext()->setContextProperty("main", this);
    ui->about_qwidget_setting->rootContext()->setContextProperty("main", this);

    ui->qwidget_space_welcome->rootContext()->setContextProperty("main", this);
    ui->qwidget_space_add->rootContext()->setContextProperty("main", this);
    ui->qwidget_space_del->rootContext()->setContextProperty("main", this);
    ui->qwidget_setting->rootContext()->setContextProperty("main", this);
    ui->qwidget_add_welcome->rootContext()->setContextProperty("main", this);

    ui->qwidget_menu_editor->rootContext()->setContextProperty("main", this);

    ui->qwidget_view_template->rootContext()->setContextProperty("osTemplatePath",
                                                                 QUrl::fromLocalFile(get_template_folder()));

    ui->qwidget_view_template->setSource(QUrl(QStringLiteral("qrc:/qml/widget/welcome_view_template.qml")));
    ui->qwidget_view_template->setResizeMode(QQuickWidget::SizeRootObjectToView);

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

    update_list_workspace_welcome();
    ui->welcome_arrera_hub->setCurrentIndex(index_welcome_add);

    model = new QFileSystemModel(this);

    update_tree_welcome();

    connect(ui->list_view_workspace_welcome,&QComboBox::currentIndexChanged,this,[this]{
        update_tree_welcome();
    });
}

gui_markdown::~gui_markdown()
{
    delete ui;
}

void gui_markdown::view_espace(){
    QStringList w =  setting_conf.getSectionKeys("workspace");

    update_list_workspace_welcome();

    if (w.isEmpty()){
        ui->welcome_arrera_hub->setCurrentIndex(index_welcome_add);
    }else{
        ui->welcome_arrera_hub->setCurrentIndex(index_welcome_space);
    }
}

void gui_markdown::view_template(){
    ui->welcome_arrera_hub->setCurrentIndex(index_welcome_template);
}

void gui_markdown::create_document(){
    create_ui.setVisible(true);
    change_page_editor(1);
}

void gui_markdown::back_setting(){
    update_list_workspace_welcome();
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::back_about(){
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::view_setting(){
    ui->arrera_hub->setCurrentIndex(index_setting);
    ui->save_space->setCurrentIndex(index_setting_space_welcome);
    ui->entry_name_space->clear();
    update_label_view_space();
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
    case 3:{

        QStringList list_workspace = setting_conf.getSectionKeys("workspace");

        if (list_workspace.isEmpty()){
            QMessageBox::information(this, "Arrera Markdown",
                                     "Il n'y a pas d'espace de travail enregistrer");
            ui->save_space->setCurrentIndex(index_setting_space_welcome);
            break;
        }

        ui->list_del_spac->clear();
        ui->list_del_spac->addItems(list_workspace);
        ui->save_space->setCurrentIndex(index_setting_del_space);
        break;
    }
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
    update_list_workspace_welcome();
    ui->arrera_hub->setCurrentIndex(index_main);
}

void gui_markdown::add_workspace(){
    QString name = ui->entry_name_space->text();
    ui->entry_name_space->clear();

    if (name.isEmpty()){
        QMessageBox::critical(this,"Arrera Markdown",
                              "Imposible d'ajouter un espace de travail sans nom");
        change_page_editor(1);
        return;
    }

    QString dir = QFileDialog::getExistingDirectory(
        this,
        tr("Espace de travail"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly
        );

    if (dir.isEmpty()){
        QMessageBox::critical(this,"Arrera Markdown",
                              "Aucun dossier selectionner");
        change_page_setting_space(1);
        return;
    }

    if (setting_conf.setValeur("workspace",name,dir)){
        QMessageBox::information(this, "Arrera Markdown",
                                 "L'espace "+name+" a bien ete ajouter");
        change_page_setting_space(1);
        update_label_view_space();
        return;
    }else{
        QMessageBox::critical(this,"Arrera Markdown",
                              "L'espace n'a pas pu etre rajouter");
        change_page_setting_space(1);
        return;
    }
}

void gui_markdown::update_label_view_space(){
    QStringList space = setting_conf.getSectionKeys("workspace");

    if (space.isEmpty()){
        ui->label_setting_liste_space->setText("Pas d'espace de travail enregister");
        return;
    }

    QString name_space,directory_space,text_space;

    for (int i = 0; i < space.size(); ++i){
        name_space = space[i];
        directory_space = setting_conf.getValeur("workspace",name_space);
        text_space = text_space+"- "+name_space+" : "+directory_space+"\n";
    }
    ui->label_setting_liste_space->setText(text_space);
}

void gui_markdown::update_list_workspace_welcome(){
    QStringList list_workspace = setting_conf.getSectionKeys("workspace");

    if (list_workspace.isEmpty()){
        return;
    }

    ui->list_view_workspace_welcome->clear();
    ui->list_view_workspace_welcome->addItems(list_workspace);

}

void gui_markdown::update_tree_welcome(){
    QString directory = setting_conf.getValeur("workspace",
                                               ui->list_view_workspace_welcome->currentText());

    if (directory.isEmpty()){
        QMessageBox::critical(this,"Arrera Markdown","Erreur");
    }else {
        model->setRootPath(directory);
        model->setNameFilters(QStringList() << "*.amd");
        model->setNameFilterDisables(false);
        model->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);

        ui->tree_view_file_space->setModel(model);
        ui->tree_view_file_space->setRootIndex(model->index(directory));
        ui->tree_view_file_space->hideColumn(1);
        ui->tree_view_file_space->hideColumn(2);
        ui->tree_view_file_space->hideColumn(3);
    }
}

QString gui_markdown::get_template_folder(){
    int os = setting_conf.checkOS();

    if (os == 3 || os == 2) {
        QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        return homePath + "/.config/arrera_markdown/template";
    }
    else if (os == 1) {
        QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        return appDataPath + "/template";
    }
    else {
        return "";
    }
}

bool gui_markdown::copy_template(){
    QString targetFolder = get_template_folder();

    QDir dir;
    if (!dir.exists(targetFolder)) {
        if (!dir.mkpath(targetFolder)) {
            return false;
        }
    }

    QString resourcePrefix = ":/template";
    QDirIterator it(resourcePrefix, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        it.next();
        QFileInfo fileInfo = it.fileInfo();
        if (fileInfo.isFile()) {
            QString relativePath = fileInfo.absoluteFilePath().mid(resourcePrefix.length()).replace("template/","");
            QString destPath = targetFolder + relativePath;

            QDir().mkpath(QFileInfo(destPath).absolutePath());

            if (!QFile::exists(destPath)) {
                if (QFile::copy(fileInfo.absoluteFilePath(), destPath)) {
                    QFile::setPermissions(destPath,
                                          QFileDevice::ReadOwner | QFileDevice::WriteOwner |
                                              QFileDevice::ReadUser  | QFileDevice::WriteUser
                                          );
                }
            }
        }
    }

    return true;
}

void gui_markdown::del_workspace(){
    QString valeur = ui->list_del_spac->currentText();

    if (valeur.isEmpty()){
        QMessageBox::critical(this,"Arrera Markdown",
                              "Une erreur c'est produite");
    }

    if (setting_conf.supprValeur("workspace",valeur)){
        QMessageBox::information(this, "Arrera Markdown",
                                 "L'espace "+valeur+" a bien ete supprimer");
    }else{
        QMessageBox::critical(this,"Arrera Markdown",
                              "Imposible de supprimer l'espace");
    }

    ui->save_space->setCurrentIndex(index_setting_space_welcome);

    update_label_view_space();
}
