#include <stu.h>
#include <iostream>
#include<QList>
#include <QCoreApplication>
#include<QDebug>
#include<QString>
#include<QVector>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    student student1,student2,student3,student4;
        student1.number=1403130209;
        student1.name="鲁智";
        student1.achievements1=80;
        student1.achievements2=72;
        student2.number=1403140101;
        student2.name="林冲";
        student2.achievements1=82;
        student2.achievements2=76;
        student3.number=1403140102;
        student3.name="宋江";
        student3.achievements1=76;
        student3.achievements2=85;
        student4.number=1403140103;
        student4.name="武松";
        student4.achievements1=88;
        student4.achievements2=80;
        QList<student> list;
        list<<student1<<student2<<student3<<student4;
        qDebug()<<" ---------------------------------------";
        qDebug()<<"                 原成绩";
        display( list);
        std:: sort(list.begin(),list.end(),bjname);
        qDebug()<<" ---------------------------------------";
        qDebug()<<"             按照姓名排序";
        display( list);
        std:: sort(list.begin(),list.end(),bjscore1);
        qDebug()<<" ----------------------------------------";
        qDebug()<<"             按照课程1排序";
        display(list);
        std:: sort(list.begin(),list.end(),bjscore2);
        qDebug()<<" -----------------------------------------";
        qDebug()<<"             按照课程2排序";
        display(list);
        return a.exec();
}
