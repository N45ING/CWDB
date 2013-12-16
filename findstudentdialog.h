#ifndef FINDSTUDENTDIALOG_H
#define FINDSTUDENTDIALOG_H

#include <QDialog>
#include <QTSql>
#include <QTableView>
#include <QMessageBox>
#include <QStringList>

#include "student.h"

namespace Ui {
class findStudentDialog;
}

class findStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit findStudentDialog(Student *student, QWidget *parent = 0);
    ~findStudentDialog();
    void fillFaculties();
private slots:
    void on_findButton_clicked();
    void fillGroups(QString facultyName);

    void on_prevertButton_clicked();

    void on_cancelButton_clicked();

private:
    Student *student;
    QStringList *faculties;
    Ui::findStudentDialog *ui;
};

#endif // FINDSTUDENTDIALOG_H
