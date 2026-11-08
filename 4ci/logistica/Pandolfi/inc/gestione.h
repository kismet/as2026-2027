#ifndef PREPARAZIONE_VERIFICA_GESTIONE_H
#define PREPARAZIONE_VERIFICA_GESTIONE_H

#include "types.h"
#include <string>

Pacco_t* creaPacco(int id, float peso, std::string destinazione);

void inserimentoPacchi(Pacco_t* province[], Pacco_t* pacco);

void stampaProvincia(Pacco_t* province[], std::string destinazione);

void stampaPacchi(Pacco_t* province[]);

#endif //PREPARAZIONE_VERIFICA_GESTIONE_H