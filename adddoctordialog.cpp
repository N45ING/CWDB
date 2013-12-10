#include "adddoctordialog.h"
#include "ui_adddoctordialog.h"

AddDoctorDialog::AddDoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoctorDialog)
{
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()),this,SLOT(revert()));
}

AddDoctorDialog::~AddDoctorDialog()
{
    delete ui;
}

void AddDoctorDialog::submit()
{
    QSqlQuery query;
    QString currentDoctorName = ui->nameEdit->toPlainText();
    query.exec(QString("INSERT into doctor values(NULL, '%1')").arg(currentDoctorName));
    accept();
}

void AddDoctorDialog::revert()
{
    ui->nameEdit->clear();
}


void AddDoctorDialog::on_closeButton_clicked()
{
    reject();
}
