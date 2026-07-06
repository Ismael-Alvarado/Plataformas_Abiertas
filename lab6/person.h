#ifndef PERSON_H    
#define PERSON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50]; // Nombre de la persona
    int age; // Edad de la persona
    double height; // Altura de la persona en centímetros
} Person;

typedef struct {
    Person listas[100]; // Lista de personas
    size_t size; // Número de personas en la multitud
} Multitud;

void init_multitud(Multitud* m);
void agregar_person(Multitud* m, char name, int age, double height);
#endif // PERSON_H      