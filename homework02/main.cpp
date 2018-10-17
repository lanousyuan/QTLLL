#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>
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
};
}


typedef struct{
    // 结构定义
    QStringList txt;
} studData;

QDebug operator<< (QDebug d, const studData &data) {
    // 直接输出studData结构
    for(int i=0;i<data.txt.size();i++)
        d.noquote().nospace()<<QString(data.txt.at(i))<<"\t";
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
        case SK::col01:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col02:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col03:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col04:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col05:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col06:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col07:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col08:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col09:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col10:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col11:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col12:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col13:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col14:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col15:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
        case SK::col16:result=d1.txt.at(currentColumn)>=d2.txt.at(currentColumn);break;
    default:break;
    }
    return result;
}

class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    readFile();
    doSort();
    QString tempFile;
    QList<studData> data;
    studData list;
    inFile(quint8 lie);
};
ScoreSorter::ScoreSorter(QString dataFile){
    tempFile=dataFile;
}
ScoreSorter::doSort()
{
    for(int i=0;i<list.txt.size();i++)
    {
        myCmp no(i);
        std::sort(data.begin(),data.end(),no);
        qDebug()<<"排序后输出，当前排序第 "<<i+1<<" 列：";
        qDebug()<<"    "<<list;
        for(int j=0;j<data.size();j++)
            qDebug()<<data.at(j);
        qDebug()<<"-------------------------------------------------------\n";
        inFile(i+1);
    }
}
ScoreSorter::inFile(quint8 l)
{
    QFile file("sorted_"+tempFile);
    file.open(QIODevice::ReadWrite|QIODevice::Append);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    in<<QString("排序后输出，当前排序第")<<l<<QString("列：")<<"\r\n";
    in<<"\t";
    for(int j=0;j<list.txt.size();j++)
        in<<list.txt.at(j)<<"\t";
    in<<"\r\n";
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<list.txt.size();j++)
            in<<data.at(i).txt.at(j)<<"\t";
        in<<"\r\n";
    }
    in<<"-------------------------------------------------------"<<"\r\n\r\n";
    file.close();
}
ScoreSorter::readFile()
{
    QFile file(tempFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"文件打开失败!"<<endl;
    QString f(file.readLine());
    list.txt=f.split(" ", QString::SkipEmptyParts);
    if((list.txt).last()=="\n")list.txt.removeLast();
    studData datax;
    while(!file.atEnd())
    {
        QByteArray line=file.readLine();
        QString str(line);
        datax.txt=str.split(" ", QString::SkipEmptyParts);
        if((datax.txt).last()=="\n")
            datax.txt.removeLast();
        if(datax.txt.size()==0)
            continue;
        data.append(datax);
    }
}

//void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
//{
    // 自定义qDebug

//}
int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    //qInstallMessageHandler(myMessageOutput);
       QString datafile = "data.txt";


       // 如果排序后文件已存在，则删除之
       QFile f("sorted_"+datafile);
       if (f.exists()){
           f.remove();
       }

       ScoreSorter s(datafile);
       s.readFile();
       s.doSort();
    return 0;
}
