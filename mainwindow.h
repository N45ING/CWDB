#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connection.h"
#include "addstudentdialog.h"

#include <QMainWindow>
#include <QTableView>
#include <QtSql>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeModel(QSqlRelationalTableModel *model);
    QSqlRelationalTableModel *model;
    QSqlRelationalDelegate *delegate;

    void displayStudentTable(QSqlRelationalTableModel *model);
    void displayFacultiesTable(QSqlRelationalTableModel *model);
    void displayGroupsTable(QSqlRelationalTableModel *model);
    void displayDoctorsTable(QSqlRelationalTableModel *model);
    void displayDiagnosisTable(QSqlRelationalTableModel *model);
    void displayVisitTable(QSqlRelationalTableModel *model);

private:
    Ui::MainWindow *ui;
    AddStudentDialog *addStudentDialog;
private slots:
    void changeDisplayedTable(int number);
    void on_submitButton_clicked();
    void on_actionStudent_triggered();
    void updateTableView();
};

#endif // MAINWINDOW_H
