//
// Created by landucci.gianmarco on 05/11/2026.
//

#ifndef UNTITLED_TYPE_H
#define UNTITLED_TYPE_H

#include <string>
using namespace std;

const int NPROVINCE = 5;

struct Pacco {
    int id;
    float peso;
    string destinazione;
};

struct Nodo {
    Pacco dato;
    Nodo* next;
};

struct Provincia {
    string nome;
    Nodo* testa;
    Nodo* coda;
};


#endif //UNTITLED_TYPE_H
