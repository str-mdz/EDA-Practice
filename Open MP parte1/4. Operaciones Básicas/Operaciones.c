#include<stdio.h>
#include<omp.h>
int main(){
    int procs = omp_get_num_procs(); // núm procesadores
    printf("Procs: %d\n", procs);
    printf("Max threads: %d\n", omp_get_max_threads()); // max hilos
    omp_set_num_threads(procs);
    printf("In parallel: %d\n", omp_in_parallel()); // verifica paralelismo
    #pragma omp parallel
    {
        int threads = omp_get_num_threads(); // núm de hilos activos 
        printf("Threads: %d\n", threads);
        int id = omp_get_thread_num(); // id del hilo 
        printf("ID: %d\n", id);
        printf("In paralllel: %d\n", omp_in_parallel());
    }
    return 0;
}

