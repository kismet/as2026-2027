#ifndef FIRME_H
#define FIRME_H
#include "types.h"

void inizializzaElenco();

int getProvincia(string p);

bool spedisciPacco(string dest, int identity, float peso);

void printPacchi(string provincia);

void printAll();

bool cambiaDestinazione(int identity, string oldDestination, string newDestination);

bool rimuoviPacco(int identity);

void stampaCarico();
#endif
