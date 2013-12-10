#ifndef ADDDOCTORDIALOG_H
#define ADDDOCTORDIALOG_H

#include <QDialog>

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
};

#endif // ADDDOCTORDIALOG_H
