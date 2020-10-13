#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *classSeq;
    int date;
    int ans;
}Lesson;

int initLesson(Lesson *l);
int input(Lesson *l);
int calc(Lesson *l);
int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        Lesson *l;
        l = (Lesson *)malloc(sizeof(Lesson));
        initLesson(l);
        input(l);
        calc(l);
    }
    return 0;
}

int input(Lesson *l){
    for(int i=0;i<5;i++){
        scanf("%d ",l->classSeq+i);
    }
    int tmp;
    scanf("2020-0%d-%d",&tmp,&(l->date));
    return 0;
}

int initLesson(Lesson *l) {
    l->classSeq=(int *)malloc(sizeof(int)*5);
    l->date=0;
    l->ans=0;
    return 0;
}
int calc(Lesson *l){
    if(l->date>=24){
        for(int i=0;i<(l->date-23<=5?l->date-23:5);i++){
            l->ans+=*(l->classSeq+i);
        }
    }else{
        for(int i=0;i<5;i++){
            l->ans+=*(l->classSeq+i);
        }
        if(l->date>=16){
            for(int i=0;i<(l->date-15<=5?l->date-15:5);i++){
                l->ans+=*(l->classSeq+i);
            }
            for(int i=0;i<5;i++){
                l->ans+=*(l->classSeq+i)*2;
            }
        }else if(l->date>=9){
            for(int i=0;i<(l->date-8<=5?l->date-8:5);i++){
                l->ans+=*(l->classSeq+i);
            }
            for(int i=0;i<5;i++){
                l->ans+=*(l->classSeq+i);
            }
        }else if(l->date>=2){
            for(int i=0;i<(l->date-1<=5?l->date-1:5);i++){
                l->ans+=*(l->classSeq+i);
            }
        }
    }
    printf("%d\n",l->ans);
    return 0;
}
