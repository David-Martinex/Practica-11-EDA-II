#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{

//aqui iría codigo secuencial
#pragma omp parallel num_threads( 4 )
{// abre la región paralela
    printf("La región paralela es ejecutada por el hilo %d\n", omp_get_thread_num() );

    if( omp_get_thread_num() == 2 ){
        printf("    El hilo %d hace las cosas diferentes\n", omp_get_thread_num() );
    }
}// cierra la región paralela

//Aqui iría más código secuencial

}