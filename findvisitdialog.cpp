#include "findvisitdialog.h"
#include "ui_findvisitdialog.h"

FindVisitDialog::FindVisitDialog(Visit * visit,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindVisitDialog)
{
    ui->setupUi(this);
    this->visit = visit;
    faculties = new QStringList();
    diagnosis = new QStringList();
    ui->facultyEdit->setEditable(true);
    ui->groupEdit->setEditable(true);
    ui->closeButton->setFocus();
    fillFaculties();
    fillDiagnosis();


    ui->beginDateEdit->setMaximumDate(QDate::currentDate());
    ui->beginDateEdit->setDate(QDate::currentDate().addMonths(-1));
    ui->endDateEdit->setMaximumDate(QDate::currentDate());
    ui->endDateEdit->setDate(QDate::currentDate());

    connect(ui->facultyEdit, SIGNAL(currentIndexChanged(QString)), this, SLOT(fillGroups(QString)));
}

FindVisitDialog::~FindVisitDialog()
{
    delete ui;
}

void FindVisitDialog::fillFaculties()
{
    QSqlQuery query("SELECT name FROM faculty");
    ui->facultyEdit->addItem(QObject::tr("Невідомо"));
    while (query.next())
    {
        QString facultyName = query.value(0).toString();
        faculties->push_back(facultyName);
    }
    ui->facultyEdit->addItems(*faculties);
    fillGroups(ui->facultyEdit->itemText(0));
}

void FindVisitDialog::fillGroups(QString facultyName)
{
    QSqlQuery query;
    query.exec(QString("SELECT id from faculty WHERE name = '%1'").arg(facultyName));
    query.next();
    int facultyId = query.value(0).toInt();

    query.exec(QString("SELECT name from groups WHERE fac_id = '%1'").arg(facultyId));

    ui->groupEdit->clear();
    ui->groupEdit->addItem(QObject::tr("Невідомо"));
    while (query.next())
    {
        QString groupName = query.value(0).toString();
        ui->groupEdit->addItem(groupName);
    }
}

void FindVisitDialog::fillDiagnosis()
{
    QSqlQuery query("SELECT name FROM diagnosis");
    ui->diagnosisEdit->addItem(QObject::tr("Будь-яка"));
    while(query.next())
    {
        QString diagnosisName = query.value(0).toString();
        diagnosis->push_back(diagnosisName);
    }
    ui->diagnosisEdit->addItems(*diagnosis);
}

void FindVisitDialog::on_findButton_clicked()
{
   visit->facultyName  = ui->facultyEdit->currentText();
   visit->groupName = ui->groupEdit->currentText();
   visit->beginDate = ui->beginDateEdit->date();
   visit->endDate = ui->endDateEdit->date();
   visit->diagnosis = ui->diagnosisEdit->currentText();
   accept();
}

void FindVisitDialog::on_prevertButton_clicked()
{
    ui->facultyEdit->setCurrentIndex(0);
    ui->groupEdit->setCurrentIndex(0);
    ui->beginDateEdit->setDate(QDate::currentDate().addMonths(-1));
    ui->endDateEdit->setDate(QDate::currentDate());
}

void FindVisitDialog::on_closeButton_clicked()
{
    reject();
}
