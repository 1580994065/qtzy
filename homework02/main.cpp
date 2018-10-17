#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>
#include <bj.h>
#include <scoresorter.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString datafile = "data.txt";
    QFile f("sorted_"+datafile);
    if (f.exists())  f.remove();
    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return a.exec();
}
