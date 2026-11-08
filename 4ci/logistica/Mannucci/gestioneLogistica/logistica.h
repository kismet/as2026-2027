
#ifndef LOGISTICA_LOGISTICA_H
#define LOGISTICA_LOGISTICA_H

#include "logisticaTypes.h"
#include <string>

bool inserisciPacco( Pacco_t *pPacco, ElemArray_t province[] );

void stampaPacchiProvincia(ElemArray_t province[], std::string destinazione );

void stampaPacchi( ElemArray_t province[] );

bool cambiaDestinazione( int id, std::string oldProvincia, std::string newDestinazione, ElemArray_t province[] );

bool rimuoviPacco( int id );

#endif //LOGISTICA_LOGISTICA_H
