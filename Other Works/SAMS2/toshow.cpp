#include <toshow.h>
void toShow(string *name, string *id, string *score, int i){
    string _sum = ""; //用于展示学生列表
    for (int j = 0; j < i; j++)
    {
        _sum.append(name[j]);
        _sum.append("\t");
        _sum.append(id[j]);
        _sum.append("\t");
        _sum.append(score[j]);
        _sum.append("\n");
    }
    QString tempSum = QString::fromStdString(_sum);
    ui->sum->setText(tempSum);
}
