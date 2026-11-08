//
// Created by landucci.gianmarco on 05/11/2026.
//
#include "type.h"

#ifndef UNTITLED_FIRME_H
#define UNTITLED_FIRME_H

void inizializza(Provincia elenco[], int n);
int trovaProvincia(Provincia elenco[], int n, string nomeProvincia);
bool spedisciPacco(Provincia elenco[], int nprovincie, Pacco p);
bool rimuoviPacco(Provincia elenco[], int nprovincie, int id);
void printPacchi(Provincia elenco[], int nprovincie, string provincia);
void printAll(Provincia elenco[], int nprovincie);

#endif //UNTITLED_FIRME_H
