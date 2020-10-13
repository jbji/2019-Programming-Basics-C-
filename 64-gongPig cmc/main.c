#include<stdio.h>
int find(char w[],int n[],int num);

int find(char w[],int n[],int num)
{
    int s=0,h=0,d=0,c=0;
    int R=0;
    int i;
    for(i=0;i<num;i++)
    {
        if(w[i]=='H')
        {
            switch(n[i])
            {
                case 1:R=R-50;break;
                case 2:R=R-2;break;
                case 3:R=R-3;break;
                case 4:R=R-4;break;
                case 5:R=R-5;break;
                case 6:R=R-6;break;
                case 7:R=R-7;break;
                case 8:R=R-8;break;
                case 9:R=R-9;break;
                case 10:R=R-10;break;
                case 11:R=R-20;break;
                case 12:R=R-30;break;
                case 13:R=R-40;break;

            }
            h++;
        }
        if(w[i]=='S')
            s++;
        if(w[i]=='D')
            d++;
        if(w[i]=='C')
            c++;
    }
    if(c==1&&num==1)
        R=50;
    else
    {
        if(h==13)
        {
            R=200;
            if(s==1&&d==1)
                R=500;
            else
            {
                if(s==1)
                    R=R-100;
                if(d==1)
                    R=R+100;
            }
            if(c==1)
                R=R*2;
        }
        else
        {
            if(s==1)
                R=R-100;
            if(d==1)
                R=R+100;
            if(c==1)
                R=R*2;
        }
    }
    return R;
}

int main()
{
    int i,j;
    int N;
    int flag1=0;
    int result[4]={0};
    char word[16]={0};
    int number[16]={0};
    while(1)
    {
        for(i=0;i<4;i++)
        {
            scanf("%d ",&N);
            if(N==0)
            {
                flag1++;
                if(flag1==4)
                {
                    goto end;
                }
                result[i]=0;
                continue;
            }
            else
            {
                for(j=0;j<N;j++)
                {

                    scanf(" %c %d",&word[j],&number[j]);
                }
                result[i]=find(word,number,N);
            }
        }
        for(int i=0;i<4;i++){
            if(result[i]!=0){
                printf("%+d",result[i]);
            }else{
                printf("0");
            }
            if(i!=3){
                printf(" ");
            }else{
                printf("\n");
            }
        }
        flag1=0;
    }
    end:return 0;
}
