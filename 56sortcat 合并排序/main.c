/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int merge_sort(char *a,char *b,char *c);
int main(int argc, char *argv[]) {

    char a[100];
    char b[100];
    char c[200];

    gets(a);
    gets(b);
    merge_sort(a,b,c);
    puts(c);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int merge_sort(char *a,char *b,char *c){
    char *pc=c;
    char temp;
    while(*pc++=*a++);
    pc--;
    while(*pc++=*b++);
    pc=c;
    for(int i=0;*(pc+i);i++){
        for(int j=i+1;*(pc+j);j++){
            if(*(pc+i)>*(pc+j)){
                temp=*(pc+i);
                *(pc+i)=*(pc+j);
                *(pc+j)=temp;
            }
        }
    }
    return 0;
}