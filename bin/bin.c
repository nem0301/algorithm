#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int bin1(int n, int k){
    int i, j;
    int B[n+1][k+1];

    for (i = 0; i <= n; i++)
    {
        for(j = 0; j <= MIN(i, k); j++)
        {
            if (j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = B[i-1][j-1] + B[i-1][j];
        }
    }

    return B[n][k];
}

int bin2(int n, int k){

    int i, j;
    int temp, temp2;
    int B[k+1];
    for (i = 0; i <= n; i++)
    {
        for(j = 0; j <= MIN(i, k); j++)
        {
            if (j == 0 || j == i){
                temp = 1;
                B[j] = 1;
            }
            else{
                temp2 = temp;
                temp = B[j];
                B[j] = B[j] + temp2;
            }
        }
    }

    return B[k];
    
}

int main(){
    printf("%d\n", bin1(4, 2));
    printf("%d\n", bin2(4, 2));
    return 0;
}
