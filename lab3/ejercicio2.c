#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

int contar_unos_fila( int m[ ][ SIZE ] , int fila ) ;
int contar_unos_columna( int m[ ][ SIZE ] , int col ) ;
int es_identidad(int m[ ][ SIZE ] ) ;
int tiene_fila_completa( int m[ ][ SIZE ] ) ;
int tiene_columna_completa( int m[ ][ SIZE ] ) ;
void imprimir( int m[ ][ SIZE ] ) ;
void analisis( int m[ ][ SIZE ] ) ;



int main ( void ) {

int m[ SIZE ][ SIZE ];
    for ( int i = 0 ; i < SIZE ; i ++ ) { 
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        if ( i == j ) {
        m[ i ][ j ] = 1;
        } else { m[ i ][ j ] = 0; }
    }}

imprimir(m);
analisis(m);

srand(time(NULL));
int p[ SIZE ][ SIZE ];

    for ( int i = 0 ; i < SIZE ; i ++ ) { //crea matriz con numeros aleatorios entre 0 y 1
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        p[ i ][ j ] = rand() % 2 ;
    }}
imprimir(p);
analisis(p);

return 0;
}

int contar_unos_fila( int m[ ][ SIZE ] , int fila ) {
int i , cont = 0 ;  
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( m[ fila ][ i ] == 1 ) {
cont ++ ;
}
}
return cont ;
}

int contar_unos_columna( int m[ ][ SIZE ] , int col ) {
int i , cont = 0 ;  
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( m[ i ][ col ] == 1 ) {
cont ++ ;
}
}
return cont ;
}

int es_identidad (int m[ ][ SIZE ] ) {
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

int tiene_fila_completa ( int m[ ][ SIZE ] ) {
int i ;
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( contar_unos_fila( m , i ) == SIZE ) {
return 1 ;
}
}
return 0 ;
}

int tiene_columna_completa ( int m[ ][ SIZE ] ) {
int i ;
for ( i = 0 ; i < SIZE ; i ++ ) {
if ( contar_unos_columna( m , i ) == SIZE ) {
return 1 ;
}
}
return 0 ;
}

void imprimir ( int m[ ][ SIZE ] ) {
    printf ( "Matriz : \n" ) ;
for ( int i = 0 ; i < SIZE ; i ++ ) {
    for ( int j = 0 ; j < SIZE ; j ++ ) {
        printf ( "%d " , m[ i ][ j ] ) ;  
    }
printf ( "\n" ) ;
}
}
void analisis ( int m[ ][ SIZE ] ) {
    const char *identidad = es_identidad(m) ? "si" : "no";
    printf ( "Es matriz identidad: %s \n" , identidad ) ;
    const char *columna1 = tiene_columna_completa(m) ? "si" : "no";
    printf ( "Tiene columna completa de unos: %s \n" , columna1 ) ;
    const char *fila1 = tiene_fila_completa(m) ? "si" : "no";
    printf ( "Tiene fila completa de unos: %s \n" , fila1 ) ;
}



