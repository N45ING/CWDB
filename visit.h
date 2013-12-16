#ifndef VISIT_H
#define VISIT_H

#include <QString>
#include <QDate>


class Visit
{
public:
    Visit();
    QString facultyName;
    QString groupName;
    QDate beginDate;
    QDate endDate;
};

#endif // VISIT_H
