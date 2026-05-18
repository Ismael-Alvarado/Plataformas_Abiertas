#include <stdio.h>
int potencia (int base , int exp) {
int resultado=1;
while ( exp > 0 ) {
resultado=resultado*base;
exp=exp - 1 ;// elimine el int que inicializaba o sobreescribia sin cesar al exp, hacia bucle infinito
}
return resultado;
}

void es_par(int n) {
int resultado=0;
resultado=n%2;
if (resultado==0) {
    printf("El resultado es par");
} else {
    printf("EL resultado es impar");
}
}


int main ( void ) {

printf( "3^4 = %d\n", potencia (3, 4));

int base;
int exponente;
do {
printf("Ingrese numero base: ");
scanf("%d", &base);

printf("Ingrese numero exponente: ");
scanf("%d", &exponente);
if ( exponente < 0 || base == 0 ) {
    printf("Error al ingresar numero");
}
} while ( exponente < 0 || base == 0 );

}
