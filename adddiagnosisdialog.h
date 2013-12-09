#ifndef ADDDIAGNOSISDIALOG_H
#define ADDDIAGNOSISDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QtSql>

namespace Ui {
class AddDiagnosisDialog;
}

class AddDiagnosisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDiagnosisDialog(QWidget *parent = 0);
    ~AddDiagnosisDialog();

private:
    Ui::AddDiagnosisDialog *ui;
private slots:
    void submit();
    void revert();
    void on_closeButton_clicked();
};

#endif // ADDDIAGNOSISDIALOG_H
