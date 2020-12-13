#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include <omp.h>

void suma_sec( int arr1[], int arr2[], int res[], int tam )
{
    for( int i = 0; i < tam; ++i ){
        res[ i ] = arr1[ i ] + arr2[ i ];
    }
}

void suma_par( int arr1[], int arr2[], int res[], int tam )
{
    int mitad = tam / 2;
    /*Para que este ejemplo funciones correctamente, 'tam' DEBE ser miltiplo 
    de 2*/
#pragma omp parallel num_threads( 2 )
{// abre la región paralela
    int id = omp_get_thread_num();
    //obtenemos el id de este hilo

    int inicio = id * mitad;

    int fin = inicio + mitad;

    for( int i = inicio; i < fin; ++i ){
        printf("El hilo %d esta calculando res[ %d ]\n", id, i );

        res[ i ] = arr1[ i ] + arr2[ i ]; 
    }

}//Cierra la ragion paralela

}

#define TAM 10

int main()
{
    int a[ TAM ];
    int b[ TAM ];
    int c[ TAM ];

    srand( time( NULL) );

    for( int i = 0; i < TAM; ++i ){
        a[ i ] = rand() % 100;
        b[ i ] = rand() % 100;
    }

    suma_par( a, b, c, TAM );

    for( int i = 0; i < TAM; ++i ){
        printf("%2d) %d + %d = %d\n", i, a[ i ], b[ i ], c[ i ] );
    }
}

