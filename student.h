#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QDebug>

class Student
{
public:
    Student();
    QString name;
    QString facultyName;
    QString groupName;

public slots:
    void show();
};

#endif // STUDENT_H
