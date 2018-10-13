#ifndef STU_H
#define STU_H
#include <QString>


class student
{
public:
    int number;
    QString name;
    int achievements1;
    int achievements2;

};
bool bjname(const student student1,const student student2)
{
    return student1.name> student2.name;
}
bool bjscore1(const student student1,const student student2)
{
    return student1.achievements1> student2.achievements1;
}
bool bjscore2(const student student1,const student student2)
{
    return student1.achievements2> student2.achievements2;
}
void display(QList<student> list)
{
    qDebug()<<"   学号   "<<"      姓名   "<<" 课程一"<<"   课程二  ";
    for(int i=0;i<4;i++)
       qDebug()<<list.at(i).number<<"   "<<list.at(i).name<<"   "<<list.at(i).achievements1<<"       "<<list.at(i).achievements2;
}
#endif // STU_H
