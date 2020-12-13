#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i;
    //variable compartida en una región paralela

#pragma omp parallel num_threads( 4 )
{// abre la región paralela
    printf("Hola mundo\n");

    for( i = 0; i < 1000; ++i ){
        printf(" %d\n", i );
    }
}//Cierra la región paralela

}