#ifndef GUI_ADD_TABLE_H
#define GUI_ADD_TABLE_H

#include <QDialog>

namespace Ui {
class gui_add_table;
}

class gui_add_table : public QDialog
{
    Q_OBJECT

public:
    explicit gui_add_table(QWidget *parent = nullptr);
    ~gui_add_table();

private:
    Ui::gui_add_table *ui;
};

#endif // GUI_ADD_TABLE_H
