#include<stdio.h>
int main()
{
    int num,l,h=0,i=0,m=0;
    char f,g,c;
    scanf("%d,%c",&num,&f);
    char a[num][num];
    for(l=0;l<num;l++)
    {c=f+i-m;
        if(c=='z')
        {m+=26;
        }
        a[h][l]=c;
        i++;
    }
    h++;
    l=num-h-1;
    for(;;h++,l--)
    {if(h==num-1)
        {break;
        }
        c=f+i-m;
        if(c=='z')
        {m+=26;
        }
        a[h][l]=c;
        i++;
    }
    for(l=0;l<num;l++)
    {c=f+i-m;
        if(c=='z')
        {m+=26;
        }
        a[h][l]=c;
        i++;
    }
    for(h=0;h<num;h++)
    {for(l=0;l<num;l++)
        {if(h==0)
            {printf("%c",a[h][l]);
            }
            else if(h==num-1)
            {printf("%c",a[h][l]);
            }
            else if(l==num-h-1)
            {printf("%c",a[h][l]);
            }
            else {printf(" ");
            }
        }
        printf("\n");
    }
}
