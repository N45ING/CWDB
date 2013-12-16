#include "findstudentdialog.h"
#include "ui_findstudentdialog.h"

findStudentDialog::findStudentDialog(Student *student, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findStudentDialog)
{
    ui->setupUi(this);
    this->student = student;
    faculties = new QStringList();
    fillFaculties();
    ui->facultyEdit->setEditable(true);
    ui->groupEdit->setEditable(true);
    ui->cancelButton->setFocus();
    connect(ui->facultyEdit, SIGNAL(currentIndexChanged(QString)), this, SLOT(fillGroups(QString)));
}

findStudentDialog::~findStudentDialog()
{
    delete ui;
    delete faculties;
}

void findStudentDialog::fillFaculties()
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

void findStudentDialog::fillGroups(QString facultyName)
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

void findStudentDialog::on_findButton_clicked()
{
    QString currentNameSelected = ui->nameEdit->toPlainText();
    QString currentFacultySelected = ui->facultyEdit->currentText();
    QString currentGroupSelected = ui->groupEdit->currentText();

    this->student->name = currentNameSelected;
    this->student->facultyName = currentFacultySelected;
    this->student->groupName = currentGroupSelected;
    accept();
}

void findStudentDialog::on_prevertButton_clicked()
{
    ui->nameEdit->clear();
    ui->facultyEdit->setCurrentIndex(0);
    ui->groupEdit->setCurrentIndex(0);
}

void findStudentDialog::on_cancelButton_clicked()
{
    reject();
}
