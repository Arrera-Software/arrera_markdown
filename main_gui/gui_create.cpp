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

void gui_create::setVisible(bool visible){
    QWidget::setVisible(visible);

    if (visible){
        ui->entry_name->clear();
        QStringList space,ftemplate;

        space.append("Autre");
        space.append(setting_conf.getSectionKeys("workspace"));

        ftemplate.append("Aucun template");
        ftemplate.append(liste_template);

        ui->list_space_create->clear();
        ui->list_template->clear();

        ui->list_space_create->addItems(space);
        ui->list_template->addItems(ftemplate);
    }
}

void gui_create::setListTemplate(QStringList liste){
    liste_template.append(liste);
}

void gui_create::on_btn_create_clicked()
{
    QString filename;
    QString name = ui->entry_name->text();
    QString templates = ui->list_template->currentText();

    if (name.isEmpty()){
        QMessageBox::information(this,"Arrera Markdown",
                                 "Impossible de crée un document vide");
        this->close();
        return;
    }

    QString space = setting_conf.getValeur("workspace",
                                           ui->list_space_create->currentText()
                                           );
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

