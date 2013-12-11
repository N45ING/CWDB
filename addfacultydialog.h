#ifndef ADDFACULTYDIALOG_H
#define ADDFACULTYDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QtSql>

namespace Ui {
class AddFacultyDialog;
}

class AddFacultyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFacultyDialog(QWidget *parent = 0);
    ~AddFacultyDialog();

private:
    Ui::AddFacultyDialog *ui;
private slots:
    void submit();
    void revert();
    void on_closeButton_clicked();
};

#endif // ADDFACULTYDIALOG_H
