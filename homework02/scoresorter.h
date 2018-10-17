#ifndef SCORESORTER_H
#define SCORESORTER_H
#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>
class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
    friend QDebug operator << (QDebug d, const studData &data);
private:
    QString path;
    QList<studData > data;
    studData Listtitle;
    void out(quint8 lie);
};
ScoreSorter::ScoreSorter(QString dataFile)
{
    this->path=dataFile;
}
void ScoreSorter::readFile()
{
    QFile file(this->path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"不能打开文件!"<<endl;
    }
    QString titile(file.readLine());
    this->Listtitle.stud = titile.split(" ", QString::SkipEmptyParts);
    if((this->Listtitle.stud).last() == "\n") this->Listtitle.stud.removeLast();
    studData eachdata;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        eachdata.stud = str.split(" ", QString::SkipEmptyParts);
        if((eachdata.stud).last() == "\n") eachdata.stud.removeLast();
        if(eachdata.stud.size()==0) continue;
        this->data.append(eachdata);
    }
    file.close();
}
void ScoreSorter::doSort()
{
    for(int i=1;i<this->Listtitle.stud.size();i++)
    {
        mybj stdubj(i-1);
        std::sort(this->data.begin() , this->data.end() , stdubj );
        qDebug()<<"排序后输出，当前排序第 "<<i+1 <<" 列：";
        qDebug() << '\t'<< (this->Listtitle);
        for(int i=0;i<this->data.size();i++)  qDebug() << this->data.at(i);
        qDebug()<<"---------------------------------------------------------------\n";
        this->out(i+1);
    }
}
void ScoreSorter::out(quint8 lie)
{
    QFile file("sorted_"+this->path);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream<<QString("排序后输出，当前排序第 ")<<lie <<QString(" 列：")<<"\r\n";
    stream<<"\t";
    for(int j=0;j<this->Listtitle.stud.size();j++)
        stream<<this->Listtitle.stud.at(j)<<"\t";
        stream<<"\r\n";
    for(int i=0;i<this->data.size();i++)
    {
        for(int j=0;j<this->Listtitle.stud.size();j++)
        stream<<this->data.at(i).stud.at(j)<<"\t";
        stream<<"\r\n";
    }
    stream<<"------------------------------------------------------------------"<<"\r\n\r\n";
    file.close();
}
#endif // SCORESORTER_H
