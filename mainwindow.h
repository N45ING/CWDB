#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connection.h"

#include <QMainWindow>
#include <QTableView>
#include <QtSql>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeModel(QSqlRelationalTableModel *model);
    QSqlRelationalTableModel *model;
    QSqlRelationalDelegate *delegate;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
