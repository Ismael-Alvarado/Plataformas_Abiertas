#include <stdio.h>
int potencia (int base , int exp) { 
int resultado=1;
while ( exp > 0 ) {
resultado=resultado*base;
exp=exp - 1 ;// elimine el int que inicializaba o sobreescribia sin cesar al exp, hacia bucle infinito
}
return resultado;
}

void es_par(int n) { //funcion que identifica si es par o no un numero mediante modulo
int resultado=0;
resultado=n%2;
if (resultado==0) {
    printf("El resultado es par");
} else {
    printf("EL resultado es impar");
}
}


int main ( void ) { //funcion que muestra el resultado de pontencia 2 a la 3 y luego pide usuario base y exponente para calacular identificando si resultado es par

printf( "3^4 = %d\n", potencia (3, 4));

int base; // inicializacion de variables a infresar usuario y resultado
int exponente;
int resultado;
do {
printf("Ingrese numero base: ");
scanf("%d", &base);

printf("Ingrese numero exponente: ");
scanf("%d", &exponente);
if ( exponente < 0 || base == 0 ) {
    printf("Error al ingresar numero");
}
} while ( exponente < 0 || base == 0 ); // un do while para seguir preguntando dado nos dan datos erroneos
resultado=potencia(base, exponente); // se llama a la funcion que calcula potencia
printf( "%d^%d = %d\n", base, exponente, resultado); // se imprimer resultado
es_par(resultado); // se determina si resultado es par
}
