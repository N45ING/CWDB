#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\Git\\cwdb\\db.sqlite");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;

    /*query.exec("insert into student values(1, 'Espen', 1, 1, 'DNIWE')");
    query.exec("insert into student values(2, 'Espens', 1, 1, 'DNIWE')");*/
    //query.exec("insert into student values(NULL, '123', 1, 2, 'asd')");
    return true;
}

#endif
