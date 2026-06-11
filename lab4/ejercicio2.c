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
    fscanf(fp, "%*s"); // para leer formato y pasar recto
        // leer dimensiones
    fscanf(fp, "%d %d", width, height);

    // leer valor maximo
    fscanf(fp, "%d", max_val);
    //return del arreglo de pixeles
    unsigned char *pixels = malloc((*width) * (*height) * sizeof(unsigned char));
    for (int i = 0; i < (*width) * (*height); i++) {
        int tmp;
        unsigned char pixel;
        fscanf(fp, "%d", &tmp); // leer cada pixel como entero
        pixel = (unsigned char)tmp; // convertir a unsigned char
        *(pixels + i) = pixel; // guardar pixel en arreglo
    }
    fclose(fp);
    return pixels; // devolver arreglo de pixeles
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
    for (int i = 0; i < total; i++) {
        if (*(pixels + i) >= threshold) {
            *(pixels + i) = 255;
        } else {
            *(pixels + i) = 0;
        }
    }
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
    unsigned char *negative = malloc(total * sizeof(unsigned char));
    if (negative == NULL) {
        fprintf(stderr, "Error: No se pudo reservar memoria para el negativo\n");
        return NULL;
    }
    for (int i = 0; i < total; i++) {
        *(negative + i) = 255 - *(pixels + i);
    }
    return negative;
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
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo %s para escribir\n", filename);
        return;
    }
    fprintf(fp, "P2\n%d %d\n%d\n", width, height, max_val);
    for (int i = 0; i < width * height; i++) {
        fprintf(fp, "%d ", *(pixels + i)); // escribe cada pixel
        if ((i + 1) % width == 0) { // salto de linea al acabar ancho
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
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
    int count_0 = 0, count_255 = 0;
}

int main(void) {
    int width, height, max_val, threshold;
    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;
    read_pgm("input.pgm", &width, &height, &max_val);
    printf("Ingrese umbral (0-%d): ", max_val);
    scanf("%d", &threshold);
    apply_threshold(pixels, width * height, threshold);
    /* El estudiante completa */

    return 0;
}