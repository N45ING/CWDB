#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connection.h"
#include "addstudentdialog.h"
#include "addvisitdialog.h"
#include "adddiagnosisdialog.h"
#include "adddoctordialog.h"
#include "addfacultydialog.h"
#include "addgroupdialog.h"

#include "findstudentdialog.h"

#include "student.h"

#include <QMainWindow>
#include <QTableView>
#include <QtSql>
#include <QDebug>
#include <QFlags>
#include <QStringList>
#include <QString>

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
    void displayVisitOfStudent(QSqlRelationalTableModel *model, int studentId);


private:
    Ui::MainWindow *ui;
    AddStudentDialog *addStudentDialog;
    AddVisitDialog *addVisitDialog;
    AddDiagnosisDialog *addDiagnosisDialog;
    AddDoctorDialog *addDoctorDialog;
    AddFacultyDialog *addFacultyDialog;
    AddGroupDialog *addGroupDialog;

    findStudentDialog *fStudentDialog;

    QStringList *faculties;
    void fillFaculties();
    void clearFaculties();
    void changeSize(bool isExpanded);
    Student *student;


    const int WIDTH = 518;
    const int HEIGHT = 518;
    const int EXPANDED_WIDTH = 860;

private slots:
    void changeDisplayedTable(int number);
    void on_submitButton_clicked();
    void on_actionStudent_triggered();
    void updateTableView();
    void on_actionVisit_triggered();
    void on_actionDiagnosis_triggered();
    void deleteRowFromTable();
    void on_actionDoctor_triggered();
    void setEnabledDeleteButton(QModelIndex index);
    void setDisabledDeleteButton(int i);
    void on_actionFaculty_triggered();
    void on_actionGroup_triggered();
    void fillGroups(QString facultyName);
    void on_useFilterButton_clicked();
    void on_cancelFilterButton_clicked();
    void on_showVisitButton_clicked();
    void on_actionExit_triggered();
    void on_actionFindStudent_triggered();
    void findStudent();
    void on_addStudentVisit_clicked();
};

#endif // MAINWINDOW_H
