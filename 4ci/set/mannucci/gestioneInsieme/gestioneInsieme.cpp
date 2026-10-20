
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
