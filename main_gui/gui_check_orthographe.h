#ifndef GUI_CHECK_ORTHOGRAPHE_H
#define GUI_CHECK_ORTHOGRAPHE_H

#include <QDialog>

namespace Ui {
class gui_check_orthographe;
}

class gui_check_orthographe : public QDialog
{
    Q_OBJECT

public:
    explicit gui_check_orthographe(QWidget *parent = nullptr);
    bool insert_text(QString text);
    ~gui_check_orthographe();

private slots:
    void on_BTN_INSERT_clicked();

    void on_BTN_CANCEL_clicked();
signals:
    void new_text(QString text);
private:
    Ui::gui_check_orthographe *ui;
};

#endif // GUI_CHECK_ORTHOGRAPHE_H
