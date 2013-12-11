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
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)),this, SLOT(setEnabledDeleteButton(QModelIndex)));
    connect(ui->tablesComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setDisabledDeleteButton(int)));
    displayStudentTable(model);



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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ім'я"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Факультет"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Група"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Адреса"));
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Назва"));
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

    //TODO HERE YOU HAVE TO SET ALL EDIT TRIGGERS DEPENDING ON TABLE SELECTED BUT NO HERE IN YOR PROGRAM
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    model->setRelation(2, QSqlRelation("faculty", "id", "name"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Шифр"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Факультет"));
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ім'я"));
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ім'я"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Опис"));
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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Студент"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Дата"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Діагноз"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Лікар"));
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
    addStudentDialog = new AddStudentDialog(this);
    connect(addStudentDialog,SIGNAL(accepted()),this,SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addStudentDialog->show();
}

void MainWindow::on_actionVisit_triggered()
{
    addVisitDialog = new AddVisitDialog(this);
    connect(addVisitDialog,SIGNAL(accepted()),this,SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addVisitDialog->show();
}
void MainWindow::on_actionDiagnosis_triggered()
{
    addDiagnosisDialog = new AddDiagnosisDialog(this);
    connect(addDiagnosisDialog, SIGNAL(accepted()),this, SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addDiagnosisDialog->show();
}


void MainWindow::on_actionDoctor_triggered()
{
    addDoctorDialog = new AddDoctorDialog(this);
    connect(addDoctorDialog, SIGNAL(accepted()), this, SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addDoctorDialog->show();
}

void MainWindow::on_actionFaculty_triggered()
{
    addFacultyDialog =  new AddFacultyDialog(this);
    connect(addFacultyDialog, SIGNAL(accepted()), this, SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addFacultyDialog->show();
}

void MainWindow::on_actionGroup_triggered()
{
    addGroupDialog = new AddGroupDialog(this);
    connect(addGroupDialog, SIGNAL(accepted()), this, SLOT(on_submitButton_clicked()));
    on_submitButton_clicked();
    addGroupDialog->show();
}

void MainWindow::setDisabledDeleteButton(int i)
{
    if(i>0)
    {
        ui->deleteButton->setDisabled(true);
    }
}

void MainWindow::setEnabledDeleteButton(QModelIndex index)
{
    if(index.isValid())
    {
        ui->deleteButton->setEnabled(true);
    }
    else
    {
        ui->deleteButton->setEnabled(false);
    }
}


void MainWindow::updateTableView()
{
    ui->tableView->resizeColumnsToContents();
}



