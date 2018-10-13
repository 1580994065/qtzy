#include "stu.h"
#include <QDebug>



bool Student::comparename(student student1, student student2)
{
    return student1.name> student2.name;
}
bool Student::comparescore1(student student1, student student2)
{
    return student1.score1> student2.score1;
}
bool Student::comparescore2( student student1, student student2)

{
    return student1.score2> student2.score2;
}







