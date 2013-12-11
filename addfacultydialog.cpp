#include "addfacultydialog.h"
#include "ui_addfacultydialog.h"

AddFacultyDialog::AddFacultyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFacultyDialog)
{
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()),this,SLOT(revert()));
}

AddFacultyDialog::~AddFacultyDialog()
{
    delete ui;
}

void AddFacultyDialog::submit()
{
    QSqlQuery query;
    QString currentFacultyName = ui->nameEdit->toPlainText();
    query.exec(QString("INSERT into faculty values(NULL, '%1')").arg(currentFacultyName));
    accept();
}

void AddFacultyDialog::revert()
{
    ui->nameEdit->clear();
}

void AddFacultyDialog::on_closeButton_clicked()
{
    reject();
}
