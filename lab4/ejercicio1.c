 #include <stdio .h>
 #include <stdlib .h>

 /∗
 Encuentra la secuencia de 1s consecutivos mas larga en la
matriz, tratandola como un arreglo lineal (los 1s que
 continuan en la siguiente fila cuentan como consecutivos).
 Utiliza unicamente aritmetica de punteros , sin sintaxis [].

Params:
 − int ∗∗matrix : puntero a la matriz cuadrada.
 − int size : numero de filas y columnas.
− int ∗result : donde se almacena la longitud encontrada.
 ∗/
 void findLargestLine(int ∗∗matrix, int size , int ∗result) {
 }

/∗
Reserva memoria dinamica para una matriz cuadrada de
enteros de tamano size x size.

Params:
− int ∗∗∗matrix : triple puntero; al salir , ∗matrix apunta
a la matriz creada.
− int size : numero de filas y columnas.
 ∗/
 void allocateMatrix(int ∗∗∗matrix, int size) {
 }

/∗
Llena la matriz con valores binarios aleatorios (0 o 1).

Params:
− int ∗∗matrix : puntero a la matriz a llenar.
 − int size : numero de filas y columnas.
∗/
 void fillMatrix(int ∗∗matrix, int size) {
 }
 /∗

Imprime la matriz en stdout.
Params:
− int ∗∗matrix : puntero a la matriz.
− int size : numero de filas y columnas.
∗/
void printMatrix(int ∗∗matrix, int size) {
printf("Matriz (%dx%d):\n", size , size);
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
printf("%d ", ∗(∗(matrix+ i) + j));
}
printf("\n");
}
}

 /∗
Libera la memoria asignada a la matriz.

 Params:
 − int ∗∗matrix : puntero a la matriz a liberar.
 − int size : numero de filas y columnas.
 ∗/
 void freeMatrix(int ∗∗matrix, int size) {
for (int i = 0; i < size; i++) {
 free(∗(matrix+ i));
}
 free(matrix);
 }

 int main(void) {
 int size , largestLine;
 int ∗∗matrix=NULL;

 /∗ El estudiante completa: leer size , llamar allocateMatrix ,
 fillMatrix , printMatrix, findLargestLine y freeMatrix. ∗/

 printf("El tamano de la secuencia de 1s mas grande es: %d\n",
 largestLine);
 return 0;
 }
