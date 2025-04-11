#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 4

double big_call1(int id) {
    return id * 9.0;
}

double big_call2(int id) {
    return id * 9.0 + 9.0;
}

int main(){
    omp_set_num_threads(NUM_THREADS);
    double A[NUM_THREADS], B[NUM_THREADS]; 
    int id;
    
    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        A[id] = big_call1(id);
        #pragma omp barrier
        B[id] = big_call2(id);
    }

    int i = 0;
    while (i < NUM_THREADS) {
        printf("A[%d] = %f, B[%d] = %f\n", i, A[i], i, B[i]);
        i++;
    }
    return 0;
}

