#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define TAM 16

int main()
{
    int global_result = 0;
    int mitad = TAM/4;

#pragma omp parallel num_threads( 4 )
{
    int my_result;
    int my_rank = omp_get_thread_num();
    int inicio = my_rank * mitad;
    int fin = inicio + mitad;
    
    int i = inicio;
    while ( i < fin )
    {
        printf("EL hilo %d esta procesando el valor %d\n", my_rank, i);
        my_result += i;
        ++i;
    }
    printf("=>Resultado local del hilo %d es: %d\n\n",my_rank ,my_result);
    global_result += my_result;   
}
    printf("La suma total de 0 a %d es: %d\n", TAM, global_result);
}