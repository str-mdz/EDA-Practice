#include<stdio.h>
#include<omp.h>

int main(){
    #pragma omp parallel
    {
        int id;
        #pragma omp master
        {
            id = omp_get_thread_num();
            printf("Master block thread %d.\n", id);
        }
        id = omp_get_thread_num();
        printf("Parallel block thread %d.\n", id);
    }
    return 0;
}

