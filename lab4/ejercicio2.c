#include <stdio.h>
#include <stdlib.h>

/*
Lee una imagen PGM (formato P2) desde un archivo.
Reserva memoria dinamica para los pixeles.

Params:
- const char *filename: ruta del archivo.
- int *width: donde se guarda el ancho leido.
- int *height: donde se guarda el alto leido.
- int *max_val: donde se guarda el valor maximo.

Retorno:
- Puntero al arreglo de pixeles, o NULL si hubo error.
*/
unsigned char *read_pgm(const char *filename,
                        int *width, int *height, int *max_val) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo %s\n", filename);
        return NULL;
    }
        // leer dimensiones
    fscanf(fp, "%d %d", width, height);

    // leer valor maximo
    fscanf(f, "%d", max_val);
}

/*
Aplica un umbral T al arreglo de pixeles in-place.
Usa unicamente aritmetica de punteros.
Pixeles >= T pasan a 255; el resto a 0.

Params:
- unsigned char *pixels: arreglo de pixeles a modificar.
- int total: numero total de pixeles.
- int threshold: valor del umbral T.
*/
void apply_threshold(unsigned char *pixels,
                     int total, int threshold) {
}

/*
Genera el negativo de un arreglo de pixeles en un nuevo arreglo.
Reserva memoria dinamica para el resultado.
Usa unicamente aritmetica de punteros.

Params:
- unsigned char *pixels: arreglo fuente.
- int total: numero total de pixeles.

Retorno:
- Nuevo arreglo con el negativo, o NULL si fallo malloc.
*/
unsigned char *make_negative(unsigned char *pixels,
                             int total) {
}

/*
Escribe un arreglo de pixeles como imagen PGM (formato P2).

Params:
- const char *filename: ruta del archivo de salida.
- unsigned char *pixels: arreglo de pixeles.
- int width: ancho de la imagen.
- int height: alto de la imagen.
- int max_val: valor maximo (tipicamente 255).
*/
void write_pgm(const char *filename,
               unsigned char *pixels,
               int width,
               int height,
               int max_val) {
}

/*
Calcula e imprime estadisticas del arreglo original y
del arreglo umbralizado.

Params:
- unsigned char *original: arreglo antes del umbral.
- unsigned char *thresholded: arreglo despues del umbral.
- int total: numero total de pixeles.
*/
void print_stats(unsigned char *original,
                 unsigned char *thresholded,
                 int total) {
}

int main(void) {
    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;
    read_pgm("input.pgm", &width, &height, &max_val);
    printf("Ingrese umbral (0-%d): ", max_val);
    /* El estudiante completa */

    return 0;
}