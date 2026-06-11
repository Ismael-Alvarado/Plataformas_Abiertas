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
    int tmp=0; //variable temporal que indica el maximo de 1s
    int unos=0; // contador de unos
    for (int i = 0; i < size; i++) { //for que va a traves de cada columna
        for (int j = 0; j < size; j++) { // for que va a traves de cada fila, formato copiado del print
            //printf("%d ", *(*(matrix+ i) + j));
            if (*(*(matrix+ i) + j)) { //condicional que observa si es 1 = TRue
                unos++; // suma 1 al contador
                if (unos>tmp) { // si la suma de unos es mayor que el maximo anterior lo guarda
                    tmp=unos;
                }
            } 
            else {
                unos=0; //cuando ya no observa un 1 reinicia contador
            }
    }
    }
    *result=tmp; //guarda valor maximo
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
    *matrix = malloc(size * sizeof(int *)); //crea espacio de tamano size para enteros
    if (*matrix == NULL)
        return;
    for (int i = 0; i < size; i++) { // crea espacio para tamano size para enteros en cada espacio anterior
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
    srand(time(NULL)); //inicializa semilla para rand
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { // se mueve a traves de cada elemento de matriz
            *(*(matrix+ i) + j) = rand()%2; //asigna valor aleatorio con modulo de 2
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
    do { //request size con validacion
        printf("Digite tamano de matriz: ");
        validar = scanf("%d",&size);
        while(getchar() != '\n'); //limpia buffer, espacio contaminado de un scan incorrecto, no se muy bien como funciona
    } while (validar !=1 || size <=0);
    allocateMatrix(&matrix, size); //asigna espacio de memoria
    fillMatrix(matrix, size); // llena con variables random binarios la matriz
    printMatrix(matrix, size); // imprime matriz
    findLargestLine(matrix, size, &largestLine); //encuentra cadena de 1s mas larga
    freeMatrix(matrix, size);//libera espacio
    
    /* El estudiante completa: leer size , llamar allocateMatrix ,
    fillMatrix , printMatrix, findLargestLine y freeMatrix. ∗/*/

    printf("El tamano de la secuencia de 1s mas grande es: %d\n",
    largestLine);
    return 0;
 }
