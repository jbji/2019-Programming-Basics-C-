#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "qiang30prompts.h"

#define AI 0
#define PLAYER 1


int main() {
    //随机数发生器
    srand((unsigned int)time(0));
    int nums[31];
    memset(nums,-1,31* sizeof(int));
    modeChoose(nums);
    int role=nums[0];
    int tmp=0;

    for(int i=1;i<=30;i++){
        if(role==PLAYER){
            //if the player is on an input.
            initPrompt(i);
            printf("Your Input:",i);
            scanf("%d",&tmp);
            initPrompt(i);
            printf("You've Inputed %d Numbers\n",tmp);
            switch (tmp){
                case 1:
                    initPrompt(i);
                    printf("PLAYER=%d\n",i,i);
                    nums[i]=role;
                    break;
                case 2:
                    initPrompt(i);
                    printf("PLAYER=%d %d\n",i,i+1);
                    nums[i]=role;
                    nums[i+1]=role;
                    i++;
                    break;
                default:
                    initPrompt(i);
                    printf("FATAL_EEROR\n");
                    return 0;
            }
            role=AI;
            printf("=========================\n");
        }else{
            if(i==1){
                initPrompt(i);
                printf("AI Inputs %d Numbers\n",2);
                initPrompt(i);
                printf("AI=%d %d\n",i,i+1);
                nums[i]=role;
                nums[i+1]=role;
                i++;
                role=PLAYER;
                continue;
            }
            if((tmp=(i-1)%3)==0){
                tmp=rand()%2+1;
            }
            switch (tmp){
                case 1:
                    initPrompt(i);
                    printf("AI Inputs %d Numbers\n",2);
                    initPrompt(i);
                    printf("AI=%d %d\n",i,i+1);
                    nums[i]=role;
                    nums[i+1]=role;
                    i++;
                    break;
                case 2:
                    initPrompt(i);
                    printf("AI=%d\n",i,i);
                    initPrompt(i);
                    printf("AI Inputs %d Number\n",1);
                    nums[i]=role;
                    break;
                default:
                    initPrompt(i);
                    printf("AI FATAL_EEROR\n");
                    return 0;
            }
            role=PLAYER;
            printf("=========================\n");
        }
    }
    printf("%s is win!\n",role==PLAYER?"AI":"PLAYER");
    return 0;
}