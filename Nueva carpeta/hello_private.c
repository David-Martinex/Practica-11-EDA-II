#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i;

#pragma omp parallel num_threads( 4 ) private( i )
{//abre la región paralela
    printf("Hola mundo\n");

    for( i = 0; i < 100; ++i){
        printf("Contador: %d\n", i );
    }
}// cierra la region paralela

}