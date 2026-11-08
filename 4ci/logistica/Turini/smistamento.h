#ifndef SMISTAMENTO_H
#define SMISTAMENTO_H

#include "types.h"

bool spedisciPacco(provincie_t Provincie[], pacco_t* pack, int numeroProvincie);

void printPacchi(provincie_t Provincie[], string nomeProvincia, int numeroProvincie);

void printAll(provincie_t Provincie[], int numeroProvincie);

bool cambiaDestinazione(provincie_t Provincie[], int ID, string vecchiaprovincia, string nuovaprovincia, int numeroProvincie);

bool rimuoviPacco(provincie_t Provincie[], int ID, int numeroProvincie);

void stampaBolleCarico(provincie_t Provincie[], provincie_t Spedizioni[], int numeroProvincie, int numeroSpedizioni);

#endif
