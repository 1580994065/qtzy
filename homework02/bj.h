#ifndef BJ_H
#define BJ_H
#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>
#define bj(a)   (d1.stud.at(a)>=d2.stud.at(a))?  1:0
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};}


typedef struct
{
    QStringList stud;
} studData;
QDebug operator << (QDebug d, const studData &data)
{
    for(int i=0;i<data.stud.size();i++)
    d.noquote().nospace()<<QString(data.stud.at(i))<<"\t" ;
    return d;
}
class mybj
{
public:
    mybj(int hresult) { this-> qresult = hresult; }
    bool operator() (const studData& d1,const studData& d2) ;
private:
    int qresult;
};


bool mybj::operator()(const studData &d1,const  studData &d2)
{
    bool result = false;
    quint32 sortedresult = 0x00000001<<qresult;
    switch (sortedresult)
    {
       case SK::col01:result=bj(1);break;
       case SK::col02:result=bj(2);break;
       case SK::col03:result=bj(3);break;
       case SK::col04:result=bj(4);break;
       case SK::col05:result=bj(5);break;
       case SK::col06:result=bj(6);break;
       case SK::col07:result=bj(7);break;
       case SK::col08:result=bj(8);break;
       case SK::col09:result=bj(9);break;
       case SK::col10:result=bj(10);break;
       case SK::col11:result=bj(11);break;
       case SK::col12:result=bj(12);break;
       case SK::col13:result=bj(13);break;
       case SK::col14:result=bj(14);break;
       case SK::col15:result=bj(15);break;
       case SK::col16:result=bj(16);break;
       case SK::col17:result=bj(17);break;
       case SK::col18:result=bj(18);break;
       case SK::col19:result=bj(19);break;
       case SK::col20:result=bj(20);break;
       case SK::col21:result=bj(21);break;
       case SK::col22:result=bj(22);break;
       case SK::col23:result=bj(23);break;
       case SK::col24:result=bj(24);break;
       case SK::col25:result=bj(25);break;
       case SK::col26:result=bj(26);break;
       case SK::col27:result=bj(27);break;
       case SK::col28:result=bj(28);break;
       case SK::col29:result=bj(29);break;
       case SK::col30:result=bj(30);break;
       case SK::col31:result=bj(31);break;
       case SK::col32:result=bj(32);break;
       default:;break;
    }
    return result;
}
#endif // CMP_H
