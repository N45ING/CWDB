#include "student.h"

Student::Student()
{
}

void Student::show()
{
    qDebug() << name << " " << facultyName << " " << groupName;
}
