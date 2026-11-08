
#ifndef LOGISTICA_LOGISTICATYPES_H
#define LOGISTICA_LOGISTICATYPES_H

#include <string>

typedef struct PaccoInfo {

    int id;

    float peso;

    // Provincia
    std::string destinazione;
} PaccoInfo_t;

typedef struct Pacco {

    PaccoInfo_t pacco;

    struct Pacco *next;
} Pacco_t;

typedef struct ElemArray {

    std::string provincia;

    Pacco_t *head;
} ElemArray_t;

int NUMPROVINCE = 3;    // Firenze - Pisa - Livorno

#endif //LOGISTICA_LOGISTICATYPES_H
