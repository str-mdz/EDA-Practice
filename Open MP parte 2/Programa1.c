#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

int main() {
    double pi = 0.0;
    step = 1.0 / (double)num_steps;

    #pragma omp parallel
    {
        double sum_local = 0.0;
        double x;

        #pragma omp for
        for (int i = 0; i < num_steps; i++) {
            x = (i + 0.5) * step;
            sum_local += 4.0 / (1.0 + x * x);
        }

        #pragma omp atomic
        pi += sum_local * step;
    }

    printf("Pi = %f\n", pi);
}
