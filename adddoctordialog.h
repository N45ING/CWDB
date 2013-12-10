#ifndef ADDDOCTORDIALOG_H
#define ADDDOCTORDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QtSql>

namespace Ui {
class AddDoctorDialog;
}

class AddDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctorDialog(QWidget *parent = 0);
    ~AddDoctorDialog();

private:
    Ui::AddDoctorDialog *ui;
private slots:
    void submit();
    void revert();
    void on_closeButton_clicked();
};

#endif // ADDDOCTORDIALOG_H
