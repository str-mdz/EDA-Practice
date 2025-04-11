#include <stdio.h>
#include <omp.h>

int counter = 0;
// Cada hilo tiene su propia copia de counter
#pragma omp threadprivate(counter)

int getIDthread() {
    return omp_get_thread_num();
}

int increment_counter() {
    return ++counter + getIDthread();
}

int main() {
    // Ocupa SPMD porque ejecuta el mismo
    // bloque de instrucciones
    omp_set_num_threads(4); 

    #pragma omp parallel
    {

        printf("Hilo %d antes -> counter = %d\n", getIDthread(), counter);
        for (int i = 0; i < 3; ++i) {
            int result = increment_counter();
            printf("Hilo %d -> i = %d, resultado = %d\n, counter = %d", getIDthread(), i, result);
        }

        printf("Hilo %d despues-> counter = %d\n", getIDthread(), counter);
    }

    return 0;
}
