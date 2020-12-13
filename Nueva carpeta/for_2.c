#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
// para las funciones de biblioteca de OpenMP

int main()
{
#pragma omp parallel for num_threads( 4 )
    for( int i = 0; i < 20; ++i){
        printf("Iteración: %d, Hilo %d\n", i, omp_get_thread_num() );
    }

}