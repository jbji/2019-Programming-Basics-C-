#include<stdio.h>
#include<string.h>
struct people{
    char name[15];
    int cost;
    int income;
    int chae;
};
int main()
{
    int num,i,balance,per,m=0,perm,n,j,left;
    char name1[15],name2[15];
    scanf("%d",&num);
    fflush(stdin);
    struct people inf[num];
    for(j=0;j<num;j++){
        inf[j].cost=0,inf[j].income=0,inf[j].chae=0;
    }
    //get name
    for(i=0;i<num;i++){
        scanf("%s",inf[i].name);
    }
    fflush(stdin);


    for(i=0;i<num;i++){
        //get name
        scanf("%s",name1);
        //out and per
        scanf("%d %d",&balance,&per);
        if(per==0){
            perm=0;
            left=balance;
        }else{
            perm=balance/per;
            left=balance%per;
        }


        for(m=0;m<num;m++){
            if(strcmp(name1,inf[m].name)==0){
                inf[m].cost=balance-left;
                break;
            }
        }

        for(m=0;m<per;m++){
            scanf("%s",name2);
            for(n=0;n<num;n++){
                if(strcmp(name2,inf[n].name)==0){
                    inf[n].income+=perm;
                    break;
                }
            }
        }
    }
    for(i=0;i<num;i++)
    {inf[i].chae=inf[i].income-inf[i].cost;
    }
    for(i=0;i<num;i++){
        printf("%s",inf[i].name);
        printf(" %d\n",inf[i].chae);
    }
}
