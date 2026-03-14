#ifndef MANAGE_TEMPLATE_H
#define MANAGE_TEMPLATE_H
#include <QStringList>
#include <QDirIterator>
#include "librairy/csetting.h"

class manage_template
{
private :
    QStringList templates;
    QString template_folder;
    CSetting setting;

    bool update_list_template();
public:
    manage_template(CSetting &s);
    QStringList get_list_template();
    QString get_template_folder();
    bool reset_template();
};

#endif // MANAGE_TEMPLATE_H
