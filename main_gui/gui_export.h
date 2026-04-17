#ifndef GUI_EXPORT_H
#define GUI_EXPORT_H

#include <QDialog>

namespace Ui {
class gui_export;
}

class gui_export : public QDialog
{
    Q_OBJECT

public:
    explicit gui_export(QWidget *parent = nullptr);
    ~gui_export();

private slots:
    void on_IDC_MARKDOWN_clicked();

    void on_IDC_PDF_clicked();

    void on_IDC_CANCEL_clicked();

private:
    Ui::gui_export *ui;
signals:
    void export_document(QString type); // Type : pdf | md
};

#endif // GUI_EXPORT_H
