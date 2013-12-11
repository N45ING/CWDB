#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);
    faculties = new QStringList();
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()),this,SLOT(revert()));
    fillFaculties();
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

void AddGroupDialog::fillFaculties()
{
    QSqlQuery query("SELECT name FROM faculty");
    while (query.next())
    {
        QString facultyName = query.value(0).toString();
        faculties->push_back(facultyName);
    }
    ui->facultyEdit->addItems(*faculties);
}

void AddGroupDialog::submit()
{
    QString currentNameSelected = ui->nameEdit->toPlainText();
    QString currentFacultySelected = ui->facultyEdit->currentText();

    int facultyId;

    QSqlQuery query;

    query.exec(QString("SELECT id from faculty WHERE name = '%1'").arg(currentFacultySelected));
    query.next();
    facultyId=query.value(0).toInt();

    query.exec(QString("INSERT into groups values(NULL, '%1', '%2')").arg(currentNameSelected).arg(facultyId));
    accept();
}

void AddGroupDialog::revert()
{
    ui->nameEdit->clear();
    ui->facultyEdit->setCurrentIndex(0);
}
