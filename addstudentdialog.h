#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QStringList>
#include <QString>
#include <QtSql>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentDialog(QWidget *parent = 0);
    ~AddStudentDialog();

private:
    Ui::AddStudentDialog *ui;
    QStringList *faculties;
    QStringList *groups;
    void fillGroups();
    void fillFaculties();
private slots:
    void submit();
    void revert();
};

#endif // ADDSTUDENTDIALOG_H
