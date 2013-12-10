#include "adddoctordialog.h"
#include "ui_adddoctordialog.h"

AddDoctorDialog::AddDoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoctorDialog)
{
    ui->setupUi(this);
}

AddDoctorDialog::~AddDoctorDialog()
{
    delete ui;
}
