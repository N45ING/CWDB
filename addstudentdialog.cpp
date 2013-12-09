#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
    faculties = new QStringList();
    fillFaculties();
    ui->closeButton->setDefault(true);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()), this, SLOT(revert()));
    connect(ui->facultyEdit, SIGNAL(currentIndexChanged(QString)), this, SLOT(fillGroups(QString)));
    connect(this, SIGNAL(accepted()), this, SLOT(revert()));
    connect(this, SIGNAL(rejected()), this, SLOT(revert()));
}

AddStudentDialog::~AddStudentDialog()
{
    delete faculties;
    delete ui;
}

void AddStudentDialog::fillFaculties()
{
    QSqlQuery query("SELECT name FROM faculty");
    while (query.next())
    {
        QString facultyName = query.value(0).toString();
        faculties->push_back(facultyName);
    }
    ui->facultyEdit->addItems(*faculties);
    fillGroups(ui->facultyEdit->itemText(0));
}

/*void AddStudentDialog::fillGroups()
{
    QSqlQuery query("SELECT name FROM groups WHERE");
    while (query.next())
    {
        QString groupName = query.value(0).toString();
        groups->push_back(groupName);
    }
    ui->groupEdit->addItems(*groups);
}*/

void AddStudentDialog::fillGroups(QString facultyName)
{
    QSqlQuery query;
    query.exec(QString("SELECT id from faculty WHERE name = '%1'").arg(facultyName));
    query.next();
    int facultyId = query.value(0).toInt();

    query.exec(QString("SELECT name from groups WHERE fac_id = '%1'").arg(facultyId));

    ui->groupEdit->clear();
    while (query.next())
    {
        QString groupName = query.value(0).toString();
        ui->groupEdit->addItem(groupName);
    }
}

void AddStudentDialog::submit()
{
    QString currentFacultySelected = ui->facultyEdit->currentText();
    QString currentGroupSelected = ui->groupEdit->currentText();
    int facultyIdOfStudentToAdd;
    int groupIdOfStudentToAdd;
    QString nameOfStudentToAdd = ui->nameEdit->toPlainText();
    QString adressOfStudentToAdd = ui->adressEdit->toPlainText();

    QSqlQuery query;
    query.exec(QString("SELECT id from faculty WHERE name = '%1'").arg(currentFacultySelected));
    query.next();
    facultyIdOfStudentToAdd = query.value(0).toInt();
    query.exec(QString("SELECT id from groups WHERE name = '%1'").arg(currentGroupSelected));
    query.next();
    groupIdOfStudentToAdd = query.value(0).toInt();

    query.exec(QString("INSERT into student values(NULL, '%1', '%2', '%3', '%4')").arg(nameOfStudentToAdd).arg(facultyIdOfStudentToAdd).arg(groupIdOfStudentToAdd).arg(adressOfStudentToAdd));
    accept();
}

void AddStudentDialog::revert()
{
    ui->nameEdit->clear();
    ui->adressEdit->clear();
    ui->facultyEdit->setCurrentIndex(0);
    ui->groupEdit->setCurrentIndex(0);
}


void AddStudentDialog::on_closeButton_clicked()
{
    reject();
}
