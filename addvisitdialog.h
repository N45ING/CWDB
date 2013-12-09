#ifndef ADDVISITDIALOG_H
#define ADDVISITDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QtSql>
#include <QVector>

namespace Ui {
class AddVisitDialog;
}

class AddVisitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddVisitDialog(QWidget *parent = 0);
    ~AddVisitDialog();

private slots:
    void on_closeButton_clicked();

private:
    Ui::AddVisitDialog *ui;
    QStringList *diagnosis;
    QStringList *doctors;
    QStringList *students;
    QVector<int> *ids;

    void fillDiagnosis();
    void fillDoctors();
    void fillStudents();


private slots:
    void changeStudentId(QString studentName);
    void changeStudentName(int studentId);
    void submit();
    void prevert();
};

#endif // ADDVISITDIALOG_H
