#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

int contar_unos_fila( int m[ ][ SIZE ] , int fila ) ;
int contar_unos_columna( int m[ ][ SIZE ] , int col ) ;
int es_identidad(int m[ ][ SIZE ] ) ;
int tiene_fila_completa( int m[ ][ SIZE ] ) ;
int tiene_columna_completa( int m[ ][ SIZE ] ) ;
void imprimir( int m[ ][ SIZE ] ) ; // se crea prototipos de funciones adicionales
void analisis( int m[ ][ SIZE ] ) ;



int main ( void ) {

int m[ SIZE ][ SIZE ]; // se modifica matriz default a matriz identidad de tamano SIZE x SIZE, daba errores cuando SIZE menor a la definicion original
    for ( int i = 0 ; i < SIZE ; i ++ ) { 
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        if ( i == j ) {
        m[ i ][ j ] = 1;
        } else { m[ i ][ j ] = 0; } // se tuvo que asegurar que los elementos fuera de la diagonal fueran 0 por basura en memoria si no
    }}

imprimir(m);;// se imprime matriz default
analisis(m); // se muestra datos de identidad y si hay fila o columna de 1s

srand(time(NULL)); // se crea matriz con numeros aleatorios entre 0 y 1
int p[ SIZE ][ SIZE ];

    for ( int i = 0 ; i < SIZE ; i ++ ) { //crea matriz con numeros aleatorios entre 0 y 1
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        p[ i ][ j ] = rand() % 2 ;// el modulo 2 hace que sean 1 o 0 los numeros aleatorios
    }}
imprimir(p); // se imprime matriz random
analisis(p); // se analiza y muestra matriz random

return 0;
}

int contar_unos_fila( int m[ ][ SIZE ] , int fila ) { // recibe maatriz y fila y cuenta 1s en fila
int i , cont = 0 ;  
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( m[ fila ][ i ] == 1 ) {
cont ++ ;
}
}
return cont ;
}

int contar_unos_columna( int m[ ][ SIZE ] , int col ) { // recibe maatriz y columna y cuenta 1s en columna
int i , cont = 0 ;  
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( m[ i ][ col ] == 1 ) {
cont ++ ;
}
}
return cont ;
}

int es_identidad (int m[ ][ SIZE ] ) { // corrobora que siagnoal sea 1 y todo lo demass sea 0
int i , j ;
for ( i = 0 ; i < SIZE ; i ++ ) {
    for ( j = 0 ; j < SIZE ; j ++ ) {
        if ( i == j && m[ i ][ j ] != 1 ) {
        return 0 ;
        }
        if ( i != j && m[ i ][ j ] != 0 ) {
        return 0 ;
        }
    }
}
return 1 ;
}

int tiene_fila_completa ( int m[ ][ SIZE ] ) { // compara si cantidad de 1s es igual al tamano de fila
int i ;
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( contar_unos_fila( m , i ) == SIZE ) {
return 1 ;
}
}
return 0 ;
}

int tiene_columna_completa ( int m[ ][ SIZE ] ) { // compara si cantidad de 1s es igual al tamano de columna
int i ;
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( contar_unos_columna( m , i ) == SIZE ) {
return 1 ;
}
}
return 0 ;
}

void imprimir ( int m[ ][ SIZE ] ) { // funcion que imprime matrices con buen formato
    printf ( "Matriz : \n" ) ;
for ( int i = 0 ; i < SIZE ; i ++ ) {
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        printf ( "%d " , m[ i ][ j ] ) ;  
    }
printf ( "\n" ) ;
}
}
void analisis ( int m[ ][ SIZE ] ) { //funcion que muestra los datos de identidad y si hay fila o columna de 1s
    const char *identidad = es_identidad(m) ? "si" : "no";
    printf ( "Es matriz identidad: %s \n" , identidad ) ;
    const char *columna1 = tiene_columna_completa(m) ? "si" : "no";
    printf ( "Tiene columna completa de unos: %s \n" , columna1 ) ;
    const char *fila1 = tiene_fila_completa(m) ? "si" : "no";
    printf ( "Tiene fila completa de unos: %s \n" , fila1 ) ;
}



