#include<stdio.h>
#include<omp.h>

void section_a(int id) {
    printf("Section A => thread %d\n", id);
}

void section_b(int id) {
    printf("Section B => thread %d\n", id);
}

void section_c(int id) {
    printf("Section C => thread %d\n", id);
}

int main(){
    #pragma omp parallel
    {
        int id;
        #pragma omp sections
        {
            #pragma omp section
            section_a(omp_get_thread_num());
            #pragma omp section
            section_b(omp_get_thread_num());
            #pragma omp section
            section_c(omp_get_thread_num());
        }
        id = omp_get_thread_num();
        printf("Parallel block thread %d.\n", id);
    }
}
