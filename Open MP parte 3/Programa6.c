#include <stdio.h>

#define RA 3 
#define CA 3 
#define RB 3 
#define CB 3 

void multiply(int a[RA][CA], int b[RB][CB], int c[RA][CB]) {
    int i, j, k;
    for (i = 0; i < RA; i++) {
        for (j = 0; j < CB; j++) {
            c[i][j] = 0; 
            for (k = 0; k < CA; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[RA][CA] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int b[RB][CB] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int c[RA][CB]; 

    multiply(a, b, c);

    for (int i = 0; i < RA; i++) {
        for (int j = 0; j < CB; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
