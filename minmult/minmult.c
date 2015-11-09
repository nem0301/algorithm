#include <stdio.h>
#include <stdlib.h>

int minMult(int n, int d[], int* P[]){
    int i, j, k, diagonal;
    int M[n][n];
    int min;
    int temp;

    for (i = 0; i < n; i++)
        M[i][i] = 0;

    for ( diagonal = 0; diagonal <= n - 1; diagonal++){
        for (i = 0; i < n - diagonal; i++)
        {
            min = 9999999;
            j = i + diagonal;
            //printf("%d %d\n", i+1, j+1);
            for (k = i; k < j; k++)
            {
                temp = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];
                if ( temp < min ){
                    min = temp;
                    P[i][j] = k;
                    M[i][j] = temp;
                }
                //printf("%d %d %d %d %d %d\n", M[i][j], M[i][k], M[k+1][j], d[i], d[k+1], d[j+1]);
            }
        }
    }


    return M[0][n-1];
}

void order(int i, int j, int* P[]){
    int k;
    if ( i == j ) printf("A%d", i+1);
    else {
        k = P[i][j];
        printf("(");
        order(i, k, P);
        order(k+1, j, P);
        printf(")");
    }
}


int main(){
    int n = 5;
    int d[n+1];
    int* P[n];
    int i;
    
    d[0] = 10;
    d[1] = 4;
    d[2] = 5;
    d[3] = 20;
    d[4] = 2;
    d[5] = 50;

    
    for(i = 0; i < n; i++)
    {
        P[i] = (int*) malloc (sizeof(int)*n);
    }


    printf("%d\n", minMult(n, d, P));
    order(0, 4, P);
    printf("\n");


    return 0;
}
