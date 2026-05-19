#include <stdio.h>
#define MAX_SENSORES 10

typedef enum{NORMAL, ALERTA, FALLO} EstadoSensor;

typedef struct {
    int id;
    float valor;
    EstadoSensor estado;
} Lectura;
 EstadoSensor clasificar(float valor);
int contar_estado(Lectura s[] , int n, EstadoSensor e);
int lectura_extrema(Lectura s[] , int n);
void imprimir_lecturas(Lectura s[] , int n);

int main(void) {
Lectura sensores[MAX_SENSORES];
for (int i = 0; i < MAX_SENSORES; i++) {
    printf("Ingrese el ID del sensor %d: ", i + 1);
    scanf("%d", &sensores[i].id);
    printf("Ingrese el valor del sensor %d: ", i + 1);
    scanf("%f", &sensores[i].valor);
    sensores[i].estado = clasificar(sensores[i].valor);
}

imprimir_lecturas(sensores, MAX_SENSORES);
printf("Número de sensores en estado NORMAL: %d\n", contar_estado(sensores, MAX_SENSORES, NORMAL));
printf("Número de sensores en estado ALERTA: %d\n", contar_estado(sensores, MAX_SENSORES, ALERTA));
printf("Número de sensores en estado FALLO: %d\n", contar_estado(sensores, MAX_SENSORES, FALLO));

printf("Sensor con lectura más extrema: ID %d, Valor %.2f\n", sensores[lectura_extrema(sensores, MAX_SENSORES)].id, sensores[lectura_extrema(sensores, MAX_SENSORES)].valor);   

return 0;
}
EstadoSensor clasificar(float valor) {
    if (valor < 20.0 || valor > 80.0) {
        return FALLO;
    } else if (valor < 40.0 || valor > 60.0) {
        return ALERTA;
    } else {
        return NORMAL;
    }
}
int contar_estado(Lectura s[] , int n, EstadoSensor e) {
    int cuenta = 0;  
    for (int i = 0; i < n; i++) {
        if (s[i].estado == e) {
            cuenta++;
        }
    }
    return cuenta;
}

int lectura_extrema(Lectura s[] , int n) {
    int indice_extremo = 0;
    int valor_extremo = 0;
    for (int i = 1; i < n; i++) {
        int temp=1;
        if (s[[i]].valor < 50) {
            temp=-1;
        }
        if (s[i].valor*temp - 50*temp > valor_extremo) {
            indice_extremo = i;
            valor_extremo = s[i].valor;

        }
    }
    return indice_extremo;
}

void imprimir_lecturas(Lectura s[] , int n) {
    printf("ID\tValor\tEstado\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t", s[i].id, s[i].valor);
        }
        switch (s[i].estado) {
            case NORMAL:
                printf("NORMAL\n");
                break;
            case ALERTA:
                printf("ALERTA\n");
                break;
            case FALLO:
                printf("FALLO\n");
                break;
        }
}