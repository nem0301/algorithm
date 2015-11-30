#include <stdio.h>
#include <string.h>

int n = 4;

int W = 12;

int w[5] = {2, 5, 7, 3, 1};
int p[5] = {20, 30, 35, 12, 3};

char include[4][5];
char bestset[4][5];

int numbest = -1;
int maxprofit = 0;

int promising (int i, int profit, int weight){
    int j, k;
    int totweight;
    float bound;

    if (weight >= W)
        return 0;
    else {
        j = i;
        bound = profit;
        totweight = weight;
        while (j <= n && totweight + w[j] <= W){
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }

        k = j;
        if(k <= n)
            bound = bound + (W - totweight) * p[k]/w[k];

        return bound > maxprofit;
    }
}

void knapsack (int i, int profit, int weight){
    int k;
    if (weight <= W && profit > maxprofit){
        maxprofit = profit;
        numbest = i;
        for ( k = 0; k < 5; k++){
            strcpy(bestset[k], include[k]);
        }

    }

    if ( promising(i, profit, weight) ){
        strcpy(include[i], "yes");
        knapsack(i+1, profit + p[i], weight + w[i]);
        strcpy(include[i], "no");
        knapsack(i+1, profit, weight);
    }
}

int main(void){
    int i;
    knapsack(0, 0, 0);

    for (i = 0; i < 5; i++){
        printf("item %d %s\n", i, bestset[i]);
    }
    
    return 0;
}


