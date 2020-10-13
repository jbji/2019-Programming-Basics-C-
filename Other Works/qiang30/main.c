#include <stdio.h>
#include <string.h>
#define AI 0
#define PLAYER 1

int main() {
    int nums[31];
    memset(nums,-1,31* sizeof(int));
    printf("Please Choose: \nAI First (Type 0 \nPlayer First (Type 1\nAND PRESS ENTER TO CONTINUE...\n=========================\n");
    scanf("%d",&nums[0]);
    int role=nums[0];
    char tmpChar;//13 stands for enter, 32 stands for space.
    for(int i=1;i<=30;i++){
        if(role==PLAYER){
            //if the player is on an input.
            if(i==1){
                printf("Your Input: ");
            }else if(nums[i-1]!=PLAYER){
                printf("Your Input: ");
            }
            if (nums[i-2]==PLAYER){
                goto AIturn;
            }

            while((tmpChar=getchar())){ //get a num
                if(tmpChar==32){
                    nums[i]=role; //a successful input
                    break;
                }else if(tmpChar==13){
                    nums[i]=role;
                    role=AI; //switch
                    break;
                }
            }
        }else{
            AIturn:
            //if it's AI's turn to input.
            if(i==1){
                printf("AI's Input: %d %d\n",i,i+1);
                nums[i]=role;
                nums[i+1]=role;
                i++;
                role=PLAYER;
            }
            if(nums[i-1]!=AI){
                printf("AI's Input: %d",i);
                nums[i]=role;
                if(nums[i-2]==AI){
                    printf(" %d\n",i+1);
                    nums[i]=role;
                    i++;
                }else{
                    printf("\n");
                }
            }else{
                role=PLAYER;
            }
        }
    }
    printf("%s is win!\n",role==PLAYER?"AI":"PLAYER");
    return 0;
}