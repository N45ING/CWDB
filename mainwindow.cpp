#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel;
    delegate = new QSqlRelationalDelegate(ui->tableView);
    initializeModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeModel(QSqlRelationalTableModel *model)
{

        model->setTable("student");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Faculty_ID"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Group_ID"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adress"));
        model->select();
}
