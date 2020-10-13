#include <iostream>

int main() {
    int stuscore[10];
    int stuindex[10];
    int tmp;
    for(int i=0;i<10;i++){
        std::cin>>stuscore[i];
        stuindex[i]=i+1;
    }
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(stuscore[j]>stuscore[i]){
                tmp=stuscore[j];
                stuscore[j]=stuscore[i];
                stuscore[i]=tmp;
                tmp=stuindex[j];
                stuindex[j]=stuindex[i];
                stuindex[i]=tmp;
            }
        }
    }
    int cnt=0;
    for(cnt=0;stuscore[cnt]==stuscore[0];cnt++);
    std::cout<<"最高分为"<<stuscore[0]<<std::endl;
    std::cout<<"获得最高分的有"<<cnt<<"人"<<std::endl;
    std::cout<<"获得最高分的同学编号为";
    for(int i=0;i<cnt-1;i++){
        std::cout<<stuindex[i]<<",";
    }
    std::cout<<stuindex[cnt]<<std::endl;
    return 0;
}