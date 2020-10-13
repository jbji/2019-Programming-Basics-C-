/*
 *д����������
 *1 ����10��ְ����������ְ����
 *2 ��ְ������С����˳����������˳��Ҳ��֮����
 *3 Ҫ������һ��ְ���ţ����۰���ҷ��ҳ���ְ����������
 * ������������Ҫ���ҵ�ְ���ţ������ְ������
 * */
#define NUM 10 //Ϊ�˷�ֹ10��ְ����Ϊħ���������ǰ�10����һ��
#include <stdio.h>
#include <stdlib.h>

typedef struct _people{
    int no;
    char name[20];
}People;

//����������ԭ�ͣ���
int getPeople(People *);//��ȡ����ĺ���
int sortPeople(People *);//������
int cmp(const void *,const void *); //qsort��������Ҫʹ�õıȽϺ���
int searchPeople(int,People *);//���Һ���


int main() {
    People a[NUM];
    getPeople(a);
    sortPeople(a);
    int num;
    do{
        printf("����Ҫ���ҵ�ְ���ţ�");
        scanf("%d",&num);
        num=searchPeople(num,a);
    }while(!num);


    return 0;
}

//�������壺
int getPeople(People * a){
    printf("����������%d��ְ����������ְ���ţ�\n��ʽ������ ְ���ţ��磺\nJason 666\n",NUM);
    for(int i=0;i<NUM;i++){
        printf("ְ��%d��",i+1);
        scanf("%s %d",(a+i)->name,&((a+i)->no));
    }
    return 0;
}
int sortPeople(People * a){
    qsort(a,NUM, sizeof(People),cmp);
    return 0;
}
int cmp(const void *a,const void *b){
    People * a1=(People *)a;
    People * b1=(People *)b;
    return a1->no-b1->no;
}

int searchPeople(int num,People *a){
    int inf=0,sup=NUM-1;
    int index = sup/2;
    int isFound=0;
    while(sup-inf!=0&&!isFound){
        if(num>(a+index)->no){
            inf=index;
            index=(sup+inf)/2;
            if(index==inf){
                index=sup;
            }
        }else if(num<(a+index)->no){
            if(sup==index){
                inf=sup;
            }
            sup=index;
            index=(sup+inf)/2;
        }else{
            isFound=1;
        }
    }
    if(isFound){
        printf("�ҵ�ְ��! ����:%s\n",(a+index)->name);
    }else{
        printf("ְ��δ�ҵ�! ������!\n");
    }
    return isFound;
}

/*
 * �۰����----�ֳ�Ϊ���ֲ��ң����ֲ��ҷ�����Ҫ����Ĳ��ұ������������������ȣ����ұ����ʹ��˳��洢�ṹ����Σ����ұ���밴�ؼ��ִ�С�������С�



����ͨ��һ��ʵ�ʵ������������۰�����㷨��ִ�в��衣���������¾�����������ݣ�3 ��12 ��31 ��42 ��54 ��59 ��69 ��77 ��90 ��97 �������ҹؼ���Ϊ42 �����۰���ҹ������£�

(1) ȡ�м�������mid ������ҹؼ���42 �Աȣ� mid ���ֵ��ǧ42 ����ˣ� 42 Ӧ�������ݵ�ǰ�벿�֡�

(2) ȡǰ�벿�ֵ��м�������mid ������ҹؼ���42 �Աȣ� mid ���ֵС��42 ����ˣ�42 Ӧ�������ݵĺ�벿�֡�

(3) ȡ��벿�ֵ��м�������mid ������ҹؼ���42 �Աȣ� mid ���ֵС��42 ����ˣ�42 Ӧ�������ݵĺ�벿�֡�

(4) ������ݽ�ʣһ�������Ϊmid ������ҹؼ���42 �Աȣ�������ȣ���ʾ���ҵ������ݡ�����������4 �αȽϱ���ҵ�42 ���ڵ�λ��.

 */