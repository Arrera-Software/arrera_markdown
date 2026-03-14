#include "manage_template.h"

manage_template::manage_template(CSetting &s) : setting(s) {
    int os = setting.checkOS();

    if (os == 3 || os == 2) {
        QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
        template_folder = homePath + "/.config/arrera_markdown/template";
    }
    else if (os == 1) {
        QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        template_folder =  appDataPath + "/template";
    }
    else {
        template_folder =  "";
    }

    update_list_template();
}

bool manage_template::update_list_template(){
    templates.clear();

    QDir dir;
    if (!dir.exists(template_folder)) {
        if (!dir.mkpath(template_folder)) {
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
            QString destPath = template_folder + relativePath;

            templates.append(relativePath.replace("/",""));

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

QStringList manage_template::get_list_template(){
    return templates;
}

QString manage_template::get_template_folder(){
    return template_folder;
}

bool manage_template::reset_template(){
    QDir dir(template_folder);

    if (dir.exists()) {
        if (!dir.removeRecursively()) {
            return false;
        }
    }

    if (!dir.mkpath(template_folder)) {
        return false;
    }

    return update_list_template();
}
