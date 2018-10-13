#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#define nu 0x12345678
typedef quint32 doubleword;
typedef quint8  byte;
#define HHI(xxx) ( (byte) ((doubleword) (xxx) >> 24 ))              //取32位中高16位中的高8位
#define LHI(xxx) ( (byte) ((doubleword) (xxx) >> 16 ))              //取32位中高16位中的低8位
#define HLO(xxx) ( (byte) ((doubleword) (xxx) >> 8 ))               //取32位中低16位中的高8位
#define LLO(xxx) ( (byte) ((doubleword) (xxx) & 255 ))              //取32位中低16位中的低8位
#define MAX(x,y) ((x) > (y) ? (x) : (y))                            //取最大值
#define MIN(x,y) ((x) < (y) ? (x) : (y))                            //取最小值
#define out(x) QString("0x%1").arg(x,0,16,QLatin1Char(' '))         //输出转换为16进制
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList <qint8> values;
    qint32 x;

    qDebug()<<"原始值:"<<out(nu)<<"->"<<nu<<endl;                      //输出nu，转换为10进制
    qDebug()<< out(HHI(nu)) <<"->"<<dec<<HHI(nu);                     //输出高16位中高8位，转换为10进制
    qDebug()<< out(LHI(nu)) <<"->"<<dec<<LHI(nu);                     //输出高16位中低8位，转换为10进制
    qDebug()<< out(HLO(nu)) <<"->"<<dec<<HLO(nu);                     //输出低16位中高8位，转换为10进制
    qDebug()<< out(LLO(nu)) <<"->"<<dec<<LLO(nu)<<endl;               //输出低16位中低8位，转换为10进制

    qDebug()<<"最高8位和次高8位最大值:"<<MAX(out(HHI(nu)) , out(LHI(nu)))<<"->"<<MAX(HHI(nu) , LHI(nu));
    qDebug()<<"次低8位和最低8位最小值:"<<MIN(out(HLO(nu)) , out(LLO(nu)))<<"->"<<MIN(HLO(nu) , LLO(nu))<<endl;

    values << HHI(nu) << LHI(nu) << HLO(nu) << LLO(nu);
    x= (HHI(nu) << 16) + LHI(nu) + (HLO(nu) << 24) + (LLO(nu) << 8);
    qDebug() <<"重新组合后数值:"<<out(x)<<"->"<<x<<endl;

    qDebug() <<"排序前:"<<values;
    std::sort(values.begin() , values.end() , std::greater<qint8>()); //从大到小排序
    qDebug() <<"排序后:"<<values;
    return a.exec();

}
