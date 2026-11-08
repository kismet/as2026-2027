#ifndef PREPARAZIONE_VERIFICA_TYPES_H
#define PREPARAZIONE_VERIFICA_TYPES_H

#include <string>

typedef struct InfoPacco {
    int id;
    float peso;
    std::string destinazione;
}InfoPacco_t;

typedef struct Pacco {
    InfoPacco_t pacco;
    struct Pacco *next;
}Pacco_t;

std::string province[5];
#endif //PREPARAZIONE_VERIFICA_TYPES_H