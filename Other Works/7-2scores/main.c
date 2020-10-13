#include <stdio.h>
#include <ctype.h>

typedef struct student{
    int ID;
    int sc[3];
    double ave;
}Stu;

double aveCalc(Stu*);

int main() {
    char inputs[3];
    Stu stus[3]={{1,{90,80,70}},{2,{85,75,95}},{3,{88,84,65}}};
    gets(inputs);//输入学号
    int tmp=-1;
    if(isalpha(inputs[0])){
        for(int i=0;i<3;i++){
            aveCalc(&stus[i]);
            tmp=stus[i].ave>stus[tmp].ave?i:tmp;//tmp用于存储数组下标
        }
        printf("%d\n",stus[tmp].ID);
    }else{
        for(int i=0;i<3;i++){
            if(stus[i].ID==inputs[0]-'0'){
                tmp=i;
                break;//tmp用于存储id下标从而对应学生
            }
        }
        if(tmp!=-1){
            printf("%g\n",aveCalc(&stus[tmp]));
        }else{
            printf("0\n");
        }

    }

    return 0;
}

double aveCalc(Stu *s){
    int cnt=0;
    for(int i=0;i<3;i++){
        cnt+=s->sc[i];
    }
    return s->ave=(double)cnt/3;//return and store ave.
}