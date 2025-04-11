#include <stdio.h>
#include <omp.h>

void func() {
    int tmp = 0;
    // En general, ocupa SPMD porque ejecuta el mismo
    // bloque de instrucciones
    // Paralelismo de ciclos
    #pragma omp parallel for private(tmp)
    for (int j = 0; j < 1000; ++j) {
        tmp += j;
        printf("Hilo %d, j = %d, tmp = %d\n", omp_get_thread_num(), j, tmp);
    }
    printf("tmp fuera (no se sobreescribe)");
    printf(" -> %d\n", tmp);
}

int main() {
    func();
    return 0;
}