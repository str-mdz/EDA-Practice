#include<stdio.h>
#include<omp.h> // Biblioteca OMP

int main() {
    #pragma omp parallel // Sección paralela
    {
        int id = omp_get_thread_num();  // Identificador del hilo
        printf("Hello (%d)", id);
        printf("world!! (%d)\n", id);
    }
    return 0;
}

