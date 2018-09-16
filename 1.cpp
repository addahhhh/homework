#include<QCoreApplication>
#include<QDebug>
#include<QList>

typedef quint32 word;
typedef quint8 byte;

#define str(s) #s//转字符串

#define word_llo(x) ((byte)((word)(x)&255))//次低八位
#define word_hlo(x) ((byte)(((word)(x)>>8)&255))//次高八位
#define word_lhi(x) ((byte)((word)((word)(x)>>16)&255))//高低八位
#define word_hhi(x) ((byte)((word)((word)(x)>>24)))//高高八位

#define max(x,y) (((x)>(y))?(x):(y))//求最大值
#define min(x,y) (((x)<(y))?(x):(y))//求最小值

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    int i=0x12345678;
    QList<qint8> values;
    //将取值结果存入QList<qint8>对象values中
    values.append(word_hhi(i));
    values.append(word_hlo(i));
    values.append(word_lhi(i));
    values.append(word_llo(i));
    //计算重组后的值
    int newi;
        newi=(values.at(3)<<24)+(values.at(0)<<16)+(values.at(1)<<8)+values.at(2);
    qDebug("原始值:0x%x==%d\n次低八位:0x%x==%d\n次高八位:0x%x==%d\n高低八位:0x%x==%d\n高高八位:0x%x==%d\n",
           i,i,values.at(3),values.at(3),values.at(1),values.at(1),values.at(2),values.at(2),values.at(0),values.at(0));
    qDebug("高高八位与次高八位的最大值:0x%x(%d)\n高低八位与次低八位的最小值:0x%x(%d)",
             max(values.at(0),values.at(1)),max(values.at(0),values.at(1)),min(values.at(2),values.at(3)),min(values.at(2),values.at(3)));
    qDebug("重组后的数:0x%x(%d)",newi,newi);
    qDebug()<<"排序前:"<<values;
    std::sort(values.begin(),values.end(),std::greater<qint8>());//从大到小进行排序
    qDebug()<<"排序后:"<<values;
}

