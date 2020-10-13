#include <iostream>
int main() {
    int ninf[7]={10, 0}; //七天内新感染人口总计
    int infects[300]={10,0}; //日感染人数
    int infect_num=10; //累计感染人数
    int deaths[300]={0}; //日死亡日数
    int death_num=0; //累计死亡人数
    int population=12000000; //总人口
    int day;
    std::cin >> day;
    //这是决定要输出几天的数据
    for(int i=1;i<day;i++){
        if(i<7){
            ninf[i]= (infect_num-death_num);
            infects[i]=ninf[i];
            infect_num+=infects[i];
        }else{
            //存储移出的人口并让其死亡
            int tmp=ninf[0];
            deaths[i]=tmp;
            death_num+=tmp;
            //整体左移
            for(int j=0;j<6;j++){
                ninf[j]=ninf[j + 1];
            }
            if(infect_num<population){
                //判断新感染人口是否全部将人口感染
                if(infect_num + (infect_num-death_num) + deaths[i]< population){
                    ninf[6]= (infect_num-death_num)+deaths[i];
                }else{
                    ninf[6]= population - infect_num;
                }
            }else{
                ninf[6]=0;
            }
            infects[i]=ninf[6];
            infect_num+=infects[i];
        }
        std::cout << infect_num << std::endl;
//        std::cout << "On Day" << i << ", Infected:" << infect_num << "; Total Death:" << death_num <<" delta="<< infect_num - death_num<< std::endl;
//        std::cout << "  Death:" << deaths[i] << std::endl;
//        std::cout << "    Infect :" << infects[i] << std::endl;
    }
    std::cout << "=================================================="<< std::endl;
    std::cout << "Alive:" << population - infect_num << std::endl;
    std::cout << "Infected:" << infect_num << "; Total Death:" << death_num << std::endl;

    //total infects alive infects
    return 0;
}
