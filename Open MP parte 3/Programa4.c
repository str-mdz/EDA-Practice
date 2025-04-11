#include<stdio.h>
#include<omp.h> 

// Divide y vencerás 
static long num_steps = 5;
double step;

int main(){
    int i;
    double x, pi, sum = 0.0;
    step = 1.0 / ( double )num_steps;

    // En general, ocupa SPMD porque ejecuta el mismo
    // bloque de instrucciones
    // Paralelismo de ciclos
    #pragma omp parallel for private(x) reduction(+:sum)
    for ( i = 0; i < num_steps; i++ ){
        x = (i+0.5)*step;
        sum = sum + 4.0 / ( 1.0 + x * x);
        printf("Hilo %d -> %d\n", omp_get_thread_num(), i);
    }
    pi = step * sum;
    printf("PI = %f\n", pi);
}

