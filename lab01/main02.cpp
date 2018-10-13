#include <QCoreApplication>
#include<QDebug>
#include<QVector>
#include<QList>
#include<QString>
#include <iostream>
using namespace std;
class student                                           //创建student类
{
public:
    int number;
    QString name;
    int score1;
    int score2;

};
//升序排序函数
bool comparename(const student student1,const student student2)
{
    return student1.name> student2.name;
}
bool comparescore1(const student student1,const student student2)
{
    return student1.score1> student2.score1;
}
bool comparescore2(const student student1,const student student2)
{
    return student1.score2> student2.score2;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    student student1,student2,student3,student4;        //给类赋值
        student1.number=1403130209;
        student1.name="鲁智深";
        student1.score1=80;
        student1.score2=72;
        student2.number=1403140101;
        student2.name="林冲";
        student2.score1=82;
        student2.score2=76;
        student3.number=1403140102;
        student3.name="宋江";
        student3.score1=76;
        student3.score2=85;
        student4.number=1403140103;
        student4.name="武松";
        student4.score1=88;
        student4.score2=80;
        QList<student> list;                            //使用QList函数创建数组
        list<<student1<<student2<<student3<<student4;
        qDebug("原表格为:");
        qDebug("学号\t\t 姓名\t\t课程一\t课程二");
        for(int i=0;i<4;i++)                            //循环输出每一列数值
           qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).score1<<"\t"<<list.at(i).score2;
        qDebug("\n");
        std:: sort(list.begin(),list.end(),comparename);//按姓名排序
        qDebug("按姓名排序:");
        qDebug("学号\t\t 姓名\t\t课程一\t课程二");
        for(int i=0;i<4;i++)
           qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).score1<<"\t"<<list.at(i).score2;
        qDebug("\n");
        std:: sort(list.begin(),list.end(),comparescore1);//按课程一排序
        qDebug("按课程一排序:");
        qDebug("学号\t\t 姓名\t\t课程一\t课程二");
        for(int i=0;i<4;i++)
           qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).score1<<"\t"<<list.at(i).score2;
        qDebug("\n");
        std:: sort(list.begin(),list.end(),comparescore2);//按课程二排序
        qDebug("按课程二排序:");
        qDebug("学号\t\t 姓名\t\t课程一\t课程二");
        for(int i=0;i<4;i++)
           qDebug()<<list.at(i).number<<"\t"<<list.at(i).name<<"\t"<<list.at(i).score1<<"\t"<<list.at(i).score2;
           return a.exec();
}
