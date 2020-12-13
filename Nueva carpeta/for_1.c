#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads( 4 )
{// abre la region paralela
    int id = omp_get_thread_num();
#pragma omp for
    for( int i = 0; i < 20; ++i ){
        printf("Iteración: %d, Hilo %d\n", i, id );
    }

}// cierra la región paralela

}