#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QtSql>

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = 0);
    ~AddGroupDialog();
    void fillFaculties();
    QStringList *faculties;

private:
    Ui::AddGroupDialog *ui;
private slots:
    void submit();
    void revert();
};

#endif // ADDGROUPDIALOG_H
