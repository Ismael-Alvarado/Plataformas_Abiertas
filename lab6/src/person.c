#include "person.h"

void agregar_persona(Multitud *m, const char *name, int age, double height) {
    size_t tamano = m->size;
    if (tamano>=100){
        printf("Lista de personas llena")
        return
    }
    strcopy(m->gente[tamano].name, name);
    m->gente[tamano].age = age;
    m->gente[tamano].height = height;

}