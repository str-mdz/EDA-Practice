#include<stdio.h>
#include<omp.h>
#define TAM 90

double work1(int id){
    return id * 9.0;
}

double work2(int i, double *A){
    return A[i] * 9.0;
}

double work3(double *C, int i){
    return C[i] * 9.0;
}

double work4(int id){
    return id * 9.0 + 9.0;
}

int main(){
    double A[4], B[TAM], C[TAM];
    int id;
    #pragma omp parallel shared(A, B, C) private(id)
    {
        id = omp_get_thread_num();
        A[id] = work1(id);
        printf("Thread %d finish work1\n", id);
        #pragma omp barrier
        #pragma omp for
        for ( int i = 0; i < TAM; i++ ){
            C[i]=work2(i,A);
        }
        printf("Thread %d finish work2\n", id);
        #pragma omp for nowait
        for ( int i = 0; i < TAM; i++ ){
            B[i]=work3(C,i);
        }
        printf("Thread %d finish work3\n", id);
        A[id] = work4(id);
        printf("Thread %d finish work4\n", id);
    }
    return 0;
}


    