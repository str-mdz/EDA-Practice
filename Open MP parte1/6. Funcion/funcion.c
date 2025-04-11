#include <stdio.h>
#include <omp.h>

void func(int id, double *A) {
    for (int i = 0; i < id; i++) {
        A[i] = i * 9;
    }
}

int main() {
    double A[4]; // Riesgo de sobreescritura
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        func(id, A);
    }

    for (int i = 0; i < 4; i++) {
        printf("%f ", A[i]);
    }
    return 0;
}

