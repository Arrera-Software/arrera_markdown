#ifndef GUI_CREATE_H
#define GUI_CREATE_H

#include <QDialog>

namespace Ui {
class gui_create;
}

class gui_create : public QDialog
{
    Q_OBJECT

public:
    explicit gui_create(QWidget *parent = nullptr);
    ~gui_create();

private:
    Ui::gui_create *ui;
};

#endif // GUI_CREATE_H
