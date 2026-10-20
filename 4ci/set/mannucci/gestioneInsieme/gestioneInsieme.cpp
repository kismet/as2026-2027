
#include "gestioneInsieme.h"
#include <iostream>

using namespace std;

Insieme_t *creaInsieme() {
    
    return nullptr;
}

Insieme_t *creaElemento( int elemento ) {

    Insieme_t *pElemento = new Insieme_t;

    pElemento->info = elemento;
    pElemento->next = nullptr;

    return pElemento;
}

bool checkInsiemeVuoto( Insieme_t *insieme ) {
    
    if ( insieme == nullptr ) {
        return true;
    }

    return false;
}

bool cercaElemento( Insieme_t *insieme, int elemento ) {

    Insieme_t *pTmp = insieme;

    // Insieme vuoto: il ciclo non parte e si ritorna false
    while ( pTmp != nullptr ) {
        if ( pTmp->info == elemento ) {
            return true;
        }

        pTmp = pTmp->next;
    }

    return false;
}