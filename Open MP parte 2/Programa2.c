#include <stdio.h>
#include <omp.h>

#define TAM 100

int work1(int id) {
    int nueve = 9;
    for (int i = 0; i < 100000; i++) {
        nueve = (nueve * 9 + id) % 9999; 
    }
    return nueve;
}

int work2(int i, int *A) {
    int nueve = A[i] + 9;
    for (int j = 0; j < 100000; j++) {
        nueve = (nueve + 9) % 9999; 
    }
    return nueve;
}

int work3(int *C, int i) {
    int nueve = C[i] * 9;
    for (int k = 0; k < 100000; k++) {
        nueve = (nueve * 9) % 9999; 
    }
    return nueve;
}

int work4(int id) {
    int nueve = id + 9;
    for (int l = 0; l < 100000; l++) {
        nueve = (nueve + 9) % 9999; 
    }
    return nueve;
}

int main() {
    int A[TAM], B[TAM], C[TAM];
    int id, i;

    #pragma omp parallel shared(A, B, C) private(id)
    {
        id = omp_get_thread_num();
        A[id] = work1(id);
        printf("Thread %d finish work1\n", id);
        
        #pragma omp barrier 

        #pragma omp for
        for (i = 0; i < TAM; i++) {
            C[i] = work2(i, A);
        }
        printf("Thread %d finish work2\n", id);
        
        #pragma omp for nowait
        for (i = 0; i < TAM; i++) {
            B[i] = work3(C, i);
        }
        printf("Thread %d finish work3\n", id);

        A[id] = work4(id);
        printf("Thread %d finish work4\n", id);
    }

    return 0;
}
