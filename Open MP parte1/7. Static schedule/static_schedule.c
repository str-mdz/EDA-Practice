#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <windows.h> // Libreria para windows

#define THREADS 4
#define N 8

int main(){
    int i;
    #pragma omp parallel for schedule(static) num_threads(THREADS)
    for (i = 1; i < N; i++){
        Sleep(i); // Modificación con mayus
        printf("Thread %d iteration %d.\n", omp_get_thread_num(), i);
    }
    return 0;
}

