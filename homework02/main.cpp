#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<QString> number,name,test1,test2;
    number<<"1403130209"<<"1403140101"<<"1403140102"<<"1403140103";
    name<<"鲁智深"<<"林冲"<<"宋江"<<"武松";
    test1<<"80"<<"82"<<"76"<<"88";
    test2<<"72"<<"76"<<"85"<<"80";
    qDebug()<<"已知成绩表："<<endl<<number<<endl<<name<<endl<<test1<<endl<<test2<<endl;
    QVector<QVector<QString>> transcript;
    transcript<<number<<name<<test1<<test2;
    qDebug()<<"按姓名排序：";
    std::sort(name.begin(),name.end(),std::greater<QString>());
    int i,j;
    for(i=0;i<name.size();i++){
        for(j=0;j<name.size();j++)
            if(name.at(i)==transcript.at(1).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"按课程1的成绩排序：";
    std::sort(test1.begin(),test1.end(),std::greater<QString>());
    for(i=0;i<test1.size();i++){
        for(j=0;j<test1.size();j++)
            if(test1.at(i)==transcript.at(2).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"按课程2的成绩排序：";
    std::sort(test2.begin(),test2.end(),std::greater<QString>());
    for(i=0;i<test2.size();i++){
        for(j=0;j<test2.size();j++)
            if(test2.at(i)==transcript.at(3).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    return a.exec();
}
