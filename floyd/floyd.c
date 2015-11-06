#include <stdio.h>

#define INF 9999

void printMatrix(int n, int mat[7][7]){
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (mat[i][j] == INF)
               printf("INF\t"); 
            else
                printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    
}

void floyd(int n, int D[7][7]){
    int i, j, k;
    int P[n][n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            P[i][j] = 0;


    for(k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }

        printf("D = \n");
        printMatrix(7, D);
        printf("\n");
        printf("P = \n");
        printMatrix(7, P);

        printf("\n\n");
    }
}

int main(){
    
    int W[7][7] = {0, 4, INF, INF, INF, 10, INF,
        3, 0, INF, 18, INF, INF, INF,
        INF, 6, 0, INF, INF, INF, INF,
        INF, 5, 15, 0, 2, 19, 5,
        INF, INF, 12, 1, 0, INF, INF,
        INF, INF, INF, INF, INF, 0, 10,
        INF, INF, INF, 8, INF, INF, 0};

    floyd(7, W);


    return 0;
}
