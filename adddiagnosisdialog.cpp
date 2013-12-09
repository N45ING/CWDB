#include "adddiagnosisdialog.h"
#include "ui_adddiagnosisdialog.h"

AddDiagnosisDialog::AddDiagnosisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDiagnosisDialog)
{
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()),this,SLOT(revert()));
}

AddDiagnosisDialog::~AddDiagnosisDialog()
{
    delete ui;
}

void AddDiagnosisDialog::submit()
{
    QSqlQuery query;
    QString currentDiagnosisName = ui->nameEdit->toPlainText();
    QString currentDescription = ui->descriptionEdit->toPlainText();
    query.exec(QString("INSERT into diagnosis values(NULL, '%1', '%2')").arg(currentDiagnosisName).arg(currentDescription));
    accept();
}

void AddDiagnosisDialog::revert()
{
    ui->nameEdit->clear();
    ui->descriptionEdit->clear();
}


void AddDiagnosisDialog::on_closeButton_clicked()
{
    reject();
}
