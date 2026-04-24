#include "gui_create.h"
#include "ui_gui_create.h"

gui_create::gui_create(CSetting &s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gui_create),
    setting_conf(s)
{
    ui->setupUi(this);

#ifdef Q_OS_MAC
    QPixmap icon(":/icone/icon_mac.png");
    ui->label_icon_create->setPixmap(icon.scaled(50, 50, Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation));
#endif
}

gui_create::~gui_create()
{
    delete ui;
}

void gui_create::view_normal(bool visible){
    if (visible){
        with_template = false;
        ui->create->setCurrentWidget(ui->normal);

        ui->entry_name->clear();
        QStringList space,ftemplate;

        for (const QString &s : ftemplate) {
            std::cout << s.toStdString() << std::endl;
        }

        space.append("Autre");
        space.append(setting_conf.getSectionKeys("workspace"));

        ftemplate.append("Aucun template");
        ftemplate.append(liste_template);

        ui->list_space_create->clear();
        ui->list_template->clear();

        for (const QString &s : ftemplate) {
            std::cout << s.toStdString() << std::endl;
        }

        ui->list_space_create->addItems(space);
        ui->list_template->addItems(ftemplate);
    }

    QDialog::setVisible(visible);
}
void gui_create::view_with_template(bool visible,QString t_file){
    if (visible){
        with_template = true;
        template_file = t_file;
        ui->create->setCurrentWidget(ui->with_template);

        ui->entry_name_template->clear();

        QStringList space,ftemplate;

        space.append("Autre");
        space.append(setting_conf.getSectionKeys("workspace"));

        ui->list_space_template->clear();

        ui->list_space_template->addItems(space);
    }

    QDialog::setVisible(visible);
}

void gui_create::setListTemplate(QStringList liste){
    liste_template.clear();
    liste_template.append(liste);
}

void gui_create::on_btn_create_clicked()
{
    QString filename,name,templates,space;

    if (!with_template){
        name = ui->entry_name->text();
        templates = ui->list_template->currentText();
        space = setting_conf.getValeur("workspace",
                                       ui->list_space_create->currentText());
    }else{
        name = ui->entry_name_template->text();
        templates = template_file+".amd";
        space = setting_conf.getValeur("workspace",
                                       ui->list_space_template->currentText());
    }

    if (name.isEmpty()){
        QMessageBox::information(this,"Arrera Markdown",
                                 "Impossible de crée un document vide");
        this->close();
        return;
    }

    if (space == "error"){
        space = QFileDialog::getExistingDirectory(
            this,
            tr("Sélectionner un dossier"),
            QDir::homePath(),
            QFileDialog::ShowDirsOnly
            );
        if (space.isEmpty()){
            QMessageBox::information(this,"Arrera Markdown","Creation du document annuler");
            this->close();
            return;
        }
    }

    filename = space+"/"+name+".amd";

    this->close();

    if (templates == "Aucun template") emit s_create(filename);
    else emit s_create(filename,templates);
}


void gui_create::on_btn_cancel_create_clicked()
{
    setVisible(false);
}

