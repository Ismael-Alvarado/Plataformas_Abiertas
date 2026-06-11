 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 /*
 Encuentra la secuencia de 1s consecutivos mas larga en la
matriz, tratandola como un arreglo lineal (los 1s que
 continuan en la siguiente fila cuentan como consecutivos).
 Utiliza unicamente aritmetica de punteros , sin sintaxis [].

Params:
 − int ∗∗matrix : puntero a la matriz cuadrada.
 − int size : numero de filas y columnas.
− int ∗result : donde se almacena la longitud encontrada.
 */
void findLargestLine(int **matrix, int size , int *result) {
    int tmp=0;
    int unos=0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //printf("%d ", *(*(matrix+ i) + j));
            if (*(*(matrix+ i) + j)) {
                unos++;
                if (unos>tmp) {
                    tmp=unos;
                }
            } 
            else {
                unos=0;
            }
    }
    }
    *result=tmp;
 }

/*
Reserva memoria dinamica para una matriz cuadrada de
enteros de tamano size x size.

Params:
− int ∗∗∗matrix : triple puntero; al salir , ∗matrix apunta
a la matriz creada.
− int size : numero de filas y columnas.
 ∗/*/
void allocateMatrix(int ***matrix, int size) {
    *matrix = malloc(size * sizeof(int *));
    if (*matrix == NULL)
        return;
    for (int i = 0; i < size; i++) {
        *(*matrix + i) = malloc(size * sizeof(int));
        if (*(*matrix + i) == NULL)
            return;
    }
}
/*
Llena la matriz con valores binarios aleatorios (0 o 1).

Params:
− int ∗∗matrix : puntero a la matriz a llenar.
 − int size : numero de filas y columnas.
∗/*/
 void fillMatrix(int **matrix, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(matrix+ i) + j) = rand()%2;
            }

    }
 }
 /*
 

Imprime la matriz en stdout.
Params:
int ∗∗matrix : puntero a la matriz.
int size : numero de filas y columnas.
*/
void printMatrix(int **matrix, int size) {
    printf("Matriz (%dx%d):\n", size , size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix+ i) + j));
            }
    printf("\n");
    }
}

 /*
Libera la memoria asignada a la matriz.

 Params:
 − int ∗∗matrix : puntero a la matriz a liberar.
 − int size : numero de filas y columnas.
 ∗/*/

void freeMatrix(int **matrix, int size) {
for (int i = 0; i < size; i++) {
 free(*(matrix+ i));
}
 free(matrix);
 }

int main(void) {
    int size , largestLine;
    int **matrix=NULL;
    int validar = 0;
    do {
        printf("Digite tamano de matriz: ");
        validar = scanf("%d",&size);
    } while (validar !=0 && size <= 0);
    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    printMatrix(matrix, size);
    findLargestLine(matrix, size, &largestLine);
    freeMatrix(matrix, size);
    
    /* El estudiante completa: leer size , llamar allocateMatrix ,
    fillMatrix , printMatrix, findLargestLine y freeMatrix. ∗/*/

    printf("El tamano de la secuencia de 1s mas grande es: %d\n",
    largestLine);
    return 0;
 }
