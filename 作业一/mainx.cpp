#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <cstdio>
#include <climits>
using namespace std;

#define a 0x12345678
#define LLO(xxx) ((quint8) ((quint32)(xxx) & 255))
#define HLO(xxx) ((quint8) ((quint32)(xxx) >> 8))
#define LHI(xxx) ((quint8) ((quint32)(xxx) >> 16))
#define HHI(xxx) ((quint8) ((quint32)(xxx) >> 24))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))

int main(int argc,char *argv[])
{
    QList <quint8> values;
    values.append(HHI(a));
    values.append(LHI(a));
    values.append(HLO(a));
    values.append(LLO(a));
    qDebug("原始值：0x%x==%d",a,a);
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",HHI(a),HHI(a),LHI(a),LHI(a),HLO(a),HLO(a),LLO(a),LLO(a));
    qDebug("最高8位和次高8位最大值: 0x%x<%d>",MAX(HHI(a),LHI(a)),MAX(HHI(a),LHI(a)));
    qDebug("次低8位和最低8位最小值: 0x%x<%d>",MIN(HLO(a),LLO(a)),MIN(HLO(a),LLO(a)));
    return 0;
}
