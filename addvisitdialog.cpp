#include "addvisitdialog.h"
#include "ui_addvisitdialog.h"

AddVisitDialog::AddVisitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVisitDialog)
{
    ui->setupUi(this);

    diagnosis = new QStringList();
    doctors = new QStringList();
    students = new QStringList();
    ids = new QVector<int>;

    fillDiagnosis();
    fillDoctors();
    fillStudents();

    ui->doctorEdit->setEditable(true);
    ui->diagnosisEdit->setEditable(true);
    ui->studentNameEdit->setEditable(true);

    ui->dateEdit->setMaximumDate(QDate::currentDate());
    ui->dateEdit->setDate(QDate::currentDate());


    connect(ui->studentNameEdit,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeStudentId(QString)));
    connect(ui->studentIdEdit, SIGNAL(valueChanged(int)), this, SLOT(changeStudentName(int)));
    connect(ui->submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->revertButton, SIGNAL(clicked()),this,SLOT(revert()));
}



void AddVisitDialog::fillDiagnosis()
{
    QSqlQuery query("SELECT name FROM diagnosis");
    while(query.next())
    {
        QString diagnosisName = query.value(0).toString();
        diagnosis->push_back(diagnosisName);
    }
    ui->diagnosisEdit->addItems(*diagnosis);
}

void AddVisitDialog::fillDoctors()
{
    QSqlQuery query("SELECT name FROM doctor");
    while(query.next())
    {
        QString doctorName = query.value(0).toString();
        doctors->push_back(doctorName);
    }
    ui->doctorEdit->addItems(*doctors);
}

void AddVisitDialog::fillStudents()
{
    ids->clear();
    QSqlQuery query("SELECT name FROM student");
    while(query.next())
    {
        QString studentName = query.value(0).toString();
        students->push_back(studentName);
    }
    ui->studentNameEdit->addItems(*students);

    QSqlQuery queryId("SELECT id from student");
    while(queryId.next())
    {
        int studentId = queryId.value(0).toInt();
        ids->push_back(studentId);
    }
    int maxId = ids->at(0);
    int minId = ids->at(0);
    for(int i=0;i<ids->size();i++)
    {
        if (ids->at(i)>maxId) maxId=ids->at(i);
        if (ids->at(i)<minId) minId=ids->at(i);
    }
    ui->studentIdEdit->setMinimum(minId);
    ui->studentIdEdit->setMaximum(maxId);
}

void AddVisitDialog::changeStudentId(QString studentName)
{
    QSqlQuery query;
    query.exec(QString("SELECT id from student WHERE name = '%1'").arg(studentName));
    query.next();
    int studentId = query.value(0).toInt();
    ui->studentIdEdit->setValue(studentId);
}

void AddVisitDialog::changeStudentName(int studentId)
{
    QSqlQuery query;
    query.exec(QString("SELECT name from student WHERE id = '%1'").arg(studentId));
    query.next();
    QString studentName = query.value(0).toString();

    int position = ui->studentNameEdit->findText(studentName);

    if(position != -1 && ui->studentNameEdit->currentText() != studentName)
    {
        ui->studentNameEdit->setCurrentIndex(position);
    }
    else
    {
    }
}

void AddVisitDialog::submit()
{
    QDate currentDateSelected = ui->dateEdit->date();
    QString currentDateString = currentDateSelected.toString("yyyy-MM-dd");
    QString currentDiagnosisSelected = ui->diagnosisEdit->currentText();
    QString currentDoctorSelected = ui->doctorEdit->currentText();

    int studentId = ui->studentIdEdit->value();
    int diagId;
    int doctorId;


    QSqlQuery query;

    query.exec(QString("SELECT id from diagnosis WHERE name = '%1'").arg(currentDiagnosisSelected));
    query.next();
    diagId=query.value(0).toInt();

    query.exec(QString("SELECT id from doctor WHERE name = '%1'").arg(currentDoctorSelected));
    query.next();
    doctorId=query.value(0).toInt();

    query.exec(QString("INSERT into visit values(NULL, '%1', '%2', '%3', '%4')").arg(studentId).arg(currentDateString).arg(diagId).arg(doctorId));
    accept();
}

void AddVisitDialog::revert()
{
    ui->dateEdit->setDate(QDate::currentDate());
    ui->studentNameEdit->setCurrentIndex(0);
    ui->doctorEdit->setCurrentIndex(0);
    ui->diagnosisEdit->setCurrentIndex(0);
}

AddVisitDialog::~AddVisitDialog()
{
    delete diagnosis;
    delete doctors;
    delete students;
    delete ids;
    delete ui;
}

void AddVisitDialog::on_closeButton_clicked()
{
    reject();
}
