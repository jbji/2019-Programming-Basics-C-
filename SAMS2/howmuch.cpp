#include <howmuch.h>

int howMuch(string filename){
    ifstream filein(filename, ios::app | ios::binary); //打开文件
    if (!filein)                                      //读取失败
    {
        filein.close();
        return 0;
    }

    string getName, getId, getScore;
    int i = 0;
    while (getline(filein, getName, DEliM) && getline(filein, getId, DEliM) && getline(filein, getScore, DEliM))
    {
        i++; //统计学生数目
    }

    filein.close();
    return i;
}
