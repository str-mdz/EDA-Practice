#include<stdio.h>
#include<omp.h>

static long num_steps = 100000;
double step;

int main(){
    double pi;
    step = 1.0 / ( double )num_steps;
    int num_t = omp_get_num_threads();
    double sum[num_t];
    for (int i = 0; i < num_t ; i++)
        sum[i] = 0.0;
    #pragma omp parallel
    {
        int i;
        int id = omp_get_thread_num();
        double x;

        for (i = id; i < num_steps ; i += num_t){
            x = ( i + 0.5 ) * step;
            sum[id] += 4.0/(1.0 + x * x);
        }
    }
        double total = 0.0;
        for ( int i = 0; i < num_t; i++ )
            total += sum[i];
        pi = step * total;
        printf("PI = %f\n", pi);
}