#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <cstdio>
#include <climits>
using namespace std;

#define a 0x12345678
#define LLO(xxx)  ((quint8) ((quint32)(xxx) & 255))
#define HLO(xxx)  ((quint8) ((quint32)(xxx) >> 8))
#define LHI(xxx)  ((quint8) ((quint32)(xxx) >> 16))
#define HHI(xxx)  ((quint8) ((quint32)(xxx) >> 24))

int main(int argc,char *argv[])
{
    QList <quint8> values;
    values.append(HHI(a));
    values.append(LHI(a));
    values.append(HLO(a));
    values.append(LLO(a));
    qDebug("原始值：0x%x==%d",a,a);
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",HHI(a),HHI(a),LHI(a),LHI(a),HLO(a),HLO(a),LLO(a),LLO(a));
    return 0;
}
