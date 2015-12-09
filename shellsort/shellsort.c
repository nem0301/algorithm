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
            while ( j >= h && A[j-h] > temp ) {
                A[j] = A[j-h];
                j -= h;
            }
            A[j] = temp;
        }

        for( i = 0; i < n; i++){
            printf("%d, ", A[i]);
        }
        printf("\n");
    }

    return 0;
}
