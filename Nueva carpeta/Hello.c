#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//gcc -Wall -std=c99 -fopenmp -o Salida.out main.c && salida.out x //x numero de veces

void hello();

int main( int argc, char* argv[])
{
    if( argc < 2 ){
        printf("Usuage:\n %s num_threads\n num_threads is the numbre of threads\n", argv[ 0 ] );
    }

    int thread_count = strtol( argv[ 1 ], NULL, 10 );

#pragma omp parallel num_threads( thread_count )
{// abre la region paralela
    hello();
}// cierra la región paralela

}// cierra main()

void hello()
{
    int my_rank = omp_get_thread_num();

    int thread_count = omp_get_num_threads();

    printf("Hello from thread %d of %d\n", my_rank, thread_count );
}