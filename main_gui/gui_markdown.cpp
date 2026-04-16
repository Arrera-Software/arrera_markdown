#include "gui_markdown.h"
#include "ui_gui_markdown.h"


gui_markdown::gui_markdown(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui_markdown),setting_conf("arrera_markdown"),create_ui(setting_conf,this),
    template_manager(setting_conf),table_ui(this)
{
    ui->setupUi(this);

    file_conf_just_created = setting_conf.getFileCreated();

    if (file_conf_just_created){
        ui->arrera_hub->setCurrentIndex(index_setting);
        ui->save_space->setCurrentIndex(index_setting_space_welcome);
        ui->welcome_arrera_hub->setCurrentIndex(index_welcome_add);
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
                                                                 QUrl::fromLocalFile(
                                                                     template_manager.get_template_folder()));

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

    connect(&create_ui,&gui_create::s_create,this, [this](QString path,QString templates){
        set_filename(path);
        create_markdown_document(templates);
    });

    // Partie gestion du tree view

    ui->tree_view_file_space->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->tree_view_file_space, &QTreeView::doubleClicked,
            this, &gui_markdown::open_file_with_tree_view);
    connect(ui->tree_view_file_space, &QTreeView::customContextMenuRequested,
            this, &gui_markdown::tree_view_context_menu);

    // Partie insert table

    connect(&table_ui, &gui_add_table::create_table,
            this, &gui_markdown::on_insert_table);
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
    create_ui.setListTemplate(template_manager.get_list_template());
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
    case 3:
        file = "qrc:/qml/widget/editor_menu_three.qml";
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

void gui_markdown::open_document_btn_welcome(){
    QString file = QFileDialog::getOpenFileName(
        this,
        tr("Sélectionner un fichier Arrera Markdown"),
        QDir::homePath(),
        tr("Fichiers AMD (*.amd)")
        );

    if (file.isEmpty()){
        QMessageBox::information(this,"Arrera Markdown",
                                 "Aucun fichier selectionner");
    }

    open_document_with_path(file);
}

void gui_markdown::insert_one_text(QString chars){
    if (!chars.isEmpty()&&chars!=""){
        QPlainTextEdit *edit = ui->view_document;

        QTextCursor cursor = edit->textCursor();

        cursor.insertText(chars);
        edit->setTextCursor(cursor);
    }
}

void gui_markdown::insert_table(){
    table_ui.show();
}

void gui_markdown::print_document(){
    QString content = ui->view_document->getHtmlContent();

    QTextBrowser *browser = new QTextBrowser();
    browser->setHtml(content);
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer);

    if (printDialog.exec() == QDialog::Rejected) {
        return;
    }

    browser->print(&printer);
    delete browser;
}

void gui_markdown::reset_templates(){
    if (template_manager.
        reset_template())QMessageBox::information(this,
                                 "Arrera Markdown",
                                 "Les templates ont bien été remis à zéro");
    else QMessageBox::critical(this,
                              "Arrera Markdown",
                              "Une erreur s'est produite lors du reset des templates");
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
    save_document();
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


bool gui_markdown::save_document(){
    QString view_content;

    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);

        view_content = ui->view_document->toPlainText();

        out << view_content ;

        file.close();
        return true;
    }else return false;
}

void gui_markdown::set_filename(QString f){
    filename = f;
}

void gui_markdown::close_document(){
    save_document();
    filename = "";
}

void gui_markdown::open_document_with_path(QString file){
    QFile file_open(file);

    if (!file_open.exists()){
        QMessageBox::information(this,"Arrera Markdown",
                                 "Le fichier existe pas");
        return;
    }

    set_filename(file);

    if (file_open.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file_open);

        QString content = in.readAll();

        ui->view_document->clear();

        ui->view_document->setPlainText(content);

        save_document();

        ui->arrera_hub->setCurrentIndex(index_editor);

        file_open.close();

        return;
    }else {
        QMessageBox::information(this,"Arrera Markdown",
                                 "Une erreur c'est produite");
        file_open.close();
        return;
    }
}


bool gui_markdown::create_markdown_document(QString templates){
    QFile file(filename);

    if (file.exists()) {
        QMessageBox::information(this,"Arrera Markdown","Le fichier existe deja");
        return false;
    }else{
        if (templates.isEmpty()){
            if (file.open(QIODevice::WriteOnly)) {
                file.close();
                ui->arrera_hub->setCurrentIndex(index_editor);
                return true;
            }else{
                return false;
            }
        }else{
            QString template_path = template_manager.get_template_folder()+"/"+templates;

            QFile template_file(template_path);

            if (!template_file.exists()){
                QMessageBox::information(this,"Arrera Markdown","Le template n'existe pas");
                return false;
            }

            if (template_file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream in(&template_file);

                QString content = in.readAll();

                ui->view_document->clear();

                ui->view_document->setPlainText(content);

                save_document();

                ui->arrera_hub->setCurrentIndex(index_editor);

                template_file.close();

                return true;

            }else{
                QMessageBox::information(this,"Arrera Markdown",
                                         "Une erreur c'est produite a l'ouverture du fichier de template");
                return false;
            }
        }
    }
}

void gui_markdown::open_file_with_tree_view(const QModelIndex &index)
{
    QFileSystemModel *model = qobject_cast<QFileSystemModel*>(ui->tree_view_file_space->model());

    QString path = model->filePath(index);
    QFileInfo info(path);

    if(info.isFile())
    {
        open_document_with_path(path);
    }
}

void gui_markdown::tree_view_context_menu(const QPoint &pos)
{
    QModelIndex index = ui->tree_view_file_space->indexAt(pos);

    if(!index.isValid())
        return;

    QMenu menu;

    //QAction *renameAction = menu.addAction("Renommer");
    QAction *deleteAction = menu.addAction("Supprimer");
    QAction *add_action = menu.addAction("Ajouter");

    QAction *selectedAction =
        menu.exec(ui->tree_view_file_space->viewport()->mapToGlobal(pos));

    model->setReadOnly(false);

    if(selectedAction == deleteAction)
    {
        QFileSystemModel *model =
            qobject_cast<QFileSystemModel*>(ui->tree_view_file_space->model());

        model->remove(index);
    }else if (selectedAction == add_action){
        create_document();
    }

    model->setReadOnly(true);
}

void gui_markdown::on_insert_table(int l, int c){
    if (l != 0 && c != 0){
        QString tableMarkdown = "\n";

        tableMarkdown += "|";
        for (int col = 1; col <= c; ++col) {
            tableMarkdown += QString(" Titre %1 |").arg(col);
        }
        tableMarkdown += "\n";

        tableMarkdown += "|";
        for (int col = 0; col < c; ++col) {
            tableMarkdown += "---|";
        }
        tableMarkdown += "\n";

        for (int row = 0; row < l; ++row) {
            tableMarkdown += "|";
            for (int col = 0; col < c; ++col) {
                tableMarkdown += "       |";
            }
            tableMarkdown += "\n";
        }
        tableMarkdown += "\n";

        insert_one_text(tableMarkdown);

    } else {
        QMessageBox::critical(this, "Arrera Markdown", "Impossible de faire le tableau demandé.");
    }
}
