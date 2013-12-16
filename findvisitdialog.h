#ifndef FINDVISITDIALOG_H
#define FINDVISITDIALOG_H

#include <QDialog>
#include <QTSql>
#include <QTableView>
#include <QMessageBox>
#include <QStringList>

#include "visit.h"

namespace Ui {
class FindVisitDialog;
}

class FindVisitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindVisitDialog(Visit *visit,QWidget *parent = 0);
    ~FindVisitDialog();
    void fillFaculties();

private:
    Visit *visit;
    QStringList *faculties;

    Ui::FindVisitDialog *ui;
private slots:
    void fillGroups(QString facultyName);
    void on_findButton_clicked();
    void on_prevertButton_clicked();
    void on_closeButton_clicked();
};

#endif // FINDVISITDIALOG_H
