#include "qiang30prompts.h"
#include <stdio.h>

int initPrompt(int i){
    printf("INITIAL%d:",i);
    return 0;
}

int modeChoose(int *nums){
    printf("Please Choose a Mode: \nAI First (Type 0 \nPlayer First (Type 1\nAND PRESS ENTER TO CONTINUE...\n=========================\n");
    scanf("%d",nums);
    return 0;
}