#include <stdio.h>

int main() {
    int input[2][37][50] = {[0][0][0]=0};
    int indexs[2][37]= {[0][0]=0};
    char baseConvert[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int in[2];
    int proIn;
    int flag=0;
    int fixedBase,floatingBase;
    scanf("%i %i", &in[0], &in[1]);
    for (int i = 0; i<2;i++) {
        for(int base=2;base<=36;base++){
            proIn=in[i];
            do {
                input[i][base][indexs[i][base]] = proIn % base;
                proIn = proIn/base;
                indexs[i][base]++;
            } while (proIn != 0);
        }
    }
    for(fixedBase=2;fixedBase<37&&flag<50;fixedBase++){
        for(floatingBase=2;floatingBase<37&&flag<50;floatingBase++){
            flag==0;
            for(int digit=0;digit<50;digit++){
                if(input[0][fixedBase][digit]==input[1][floatingBase][digit]){
                    flag++;
                }
            }
        }
    }
    if(flag<50){
        printf("%i is not equal to %i in any base 2..36\n",in[0],in[1]);
    }else{
        for(indexs[0][fixedBase]--;indexs[0][fixedBase]>=0;indexs[0][fixedBase]--){
            printf("%c",baseConvert[ input[0][fixedBase][ indexs[0][fixedBase] ] ]);
        }
        printf(" ( Base %i ) = ",fixedBase);
        for(indexs[1][fixedBase]--;indexs[1][fixedBase]>=0;indexs[1][fixedBase]--){
            printf("%c",baseConvert[ input[1][fixedBase][ indexs[1][fixedBase] ] ]);
        }
        printf(" ( Base %i )\n",floatingBase);
    }
    return 0;
}