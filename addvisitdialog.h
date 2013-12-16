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
    explicit AddVisitDialog(int studentId,QWidget *parent = 0);
    ~AddVisitDialog();

private slots:
    void on_closeButton_clicked();

private:
    Ui::AddVisitDialog *ui;
    QStringList *diagnosis;
    QStringList *doctors;
    QStringList *students;
    QStringList *id;
    QVector<int> *ids;

    void fillDiagnosis();
    void fillDoctors();
    void fillStudents();


private slots:
    void changeStudentId(QString studentName);
    void changeStudentName(QString studentTextId);
    void submit();
    void revert();
};

#endif // ADDVISITDIALOG_H
