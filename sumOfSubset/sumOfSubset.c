#include <stdio.h>
#include <string.h>

int w[4] = {3,4,5,6};
int W = 13;
char include[4][5];

int promising (int i, int weight, int total){
    //printf("weight + total : %d\nweight : %d\nweight + w[%d] : %d\n", weight+total, weight, i, weight + w[i]);
    return (weight + total >= W) && (weight == W || weight + w[i] <= W);
}

void sumOfSubset (int i, int weight, int total){
    //printf("i: %d, weight : %d\n", i, weight);
    int j;
    if (promising(i, weight, total)){
        if(weight == W){
            for(j = 0; j < i; j++)
                printf("include :%s\n", include[j]);
        } else {
            strcpy(include[i], "yes");
            sumOfSubset(i + 1, weight + w[i], total - w[i]);
            strcpy(include[i], "no");
            sumOfSubset(i + 1, weight, total - w[i]);
       }
    }
}

int main(void){
    int j;
    sumOfSubset(0, 0, 18);
    return 0;
}

