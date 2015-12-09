#include <stdio.h>

int main(void){

    int A[] = {5, 7, 3, 2, 9, 6, 1, 8, 4};
    int n = 9, i, j, h, k, temp;
    for( i = 0; i < n; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
    for(h = 5; h > 0; h -= 2){
        for(i = h; i < n; i++){
            temp = A[i];
            j = i;
            printf("temp is %d of A[%d]\n", temp, i);
            while ( j >= h && A[j-h] > temp ) {
                printf("assign A[%d]'s %d to A[%d]'s %d\n", j-h, A[j-h], j,  A[j]);
                A[j] = A[j-h];
                j -= h;
            }
            A[j] = temp;

            printf("A[%d] is %d \n", j, temp);
            printf("[");
            for( k = 0; k < n; k++){
                printf("%d, ", A[k]);
            }
            printf("]\n\n");

        }

        printf("result ");
        for( i = 0; i < n; i++){
            printf("%d, ", A[i]);
        }
        printf("\n\n");
    }

    return 0;
}
