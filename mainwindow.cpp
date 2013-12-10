#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel(this);
    delegate = new QSqlRelationalDelegate(ui->tableView);

    //ui->tableView->setItemDelegateForColumn(QAbstractItemDelegate);


    //initializeModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(delegate);

    connect(ui->tablesComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(changeDisplayedTable(int)));
    connect(ui->tablesComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateTableView()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRowFromTable()));
    displayStudentTable(model);
    addStudentDialog = new AddStudentDialog(this);
    addVisitDialog = new AddVisitDialog(this);
    addDiagnosisDialog = new AddDiagnosisDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeModel(QSqlRelationalTableModel *model)
{

        model->setTable("student");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        model->setRelation(2, QSqlRelation("faculty", "id", "name"));
        model->setRelation(3, QSqlRelation("groups", "id", "name"));

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Faculty"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Group"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adress"));
        model->select();
}

void MainWindow::changeDisplayedTable(int number)
{
    switch(number)
    {
        case 0: displayStudentTable(model);
        break;
        case 1: displayFacultiesTable(model);
        break;
        case 2: displayGroupsTable(model);
        break;
        case 3: displayDoctorsTable(model);
        break;
        case 4: displayDiagnosisTable(model);
        break;
        case 5: displayVisitTable(model);
        break;
    };
}

void MainWindow::displayStudentTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setRelation(2, QSqlRelation("faculty", "id", "name"));
    model->setRelation(3, QSqlRelation("groups", "id", "name"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Faculty"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Group"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adress"));
    model->select();
    for(int i=0; i< model->columnCount(); i++)
    {
        ui->tableView->resizeColumnsToContents();
    }
}

void MainWindow::displayFacultiesTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("faculty");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->select();
}

void MainWindow::displayGroupsTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("groups");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->select();
}

void MainWindow::displayDoctorsTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("doctor");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->select();
}

void MainWindow::displayDiagnosisTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("diagnosis");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->select();
}

void MainWindow::displayVisitTable(QSqlRelationalTableModel *model)
{
    if(model->isDirty())
    {
        model->submitAll();
    }
    model->setTable("visit");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->setRelation(1, QSqlRelation("student", "id", "name"));
    model->setRelation(3, QSqlRelation("diagnosis", "id", "name"));
    model->setRelation(4, QSqlRelation("doctor", "id", "name"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Student"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Diagnosis"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Doctor"));
    model->select();
}

void MainWindow::deleteRowFromTable()
{
    int row = ui->tableView->currentIndex().row();
    model->removeRow(row);
}

void MainWindow::on_submitButton_clicked()
{
    model->submitAll();
    emit updateTableView();
}

void MainWindow::on_actionStudent_triggered()
{
    connect(addStudentDialog,SIGNAL(accepted()),this,SLOT(on_submitButton_clicked()));
    addStudentDialog->show();
}

void MainWindow::on_actionVisit_triggered()
{
    connect(addVisitDialog,SIGNAL(accepted()),this,SLOT(on_submitButton_clicked()));
    addVisitDialog->show();
}


void MainWindow::on_actionDiagnosis_triggered()
{
    connect(addDiagnosisDialog, SIGNAL(accepted()),this, SLOT(on_submitButton_clicked()));
    addDiagnosisDialog->show();
}

void MainWindow::updateTableView()
{
    ui->tableView->resizeColumnsToContents();
}


