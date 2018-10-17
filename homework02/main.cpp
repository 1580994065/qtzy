#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>


namespace SK {                          //定义命名空间SK，将文本文件划分为不同的列
enum SortKind{

};
}


typedef struct                          //结构体
{
    QStringList stud;
} studData;




QDebug operator << ()                   //重载 " << "符号,输出结构体studData
{

}



class mybj                             //定义比较类
{
public:
    mybj(int hresult) { this->qresult = hresult; }
    bool operator() (const studData& d1,const studData& d2) ;
private:
    int qresult;
};


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();            //读文件
    void doSort();              //排序
    friend QDebug operator << (QDebug d, const studData &data);
private:
    QString path;
    QList<studData > data;
    studData Listtitle;
    void out(quint8 lie);
};

/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString datafile = "data.txt";
    QFile f("sorted_"+datafile);
    if (f.exists())  f.remove();
    ScoreSorter s(datafile);
    s.readFile();            //读取data.txt
    s.doSort();              //排序并导出文件
    return a.exec();
}
