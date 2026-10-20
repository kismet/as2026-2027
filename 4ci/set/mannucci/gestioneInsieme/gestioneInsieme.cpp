
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

bool cercaElemento( Insieme_t *insieme, int info ) {

    Insieme_t *pTmp = insieme;

    // Insieme vuoto: il ciclo non parte e si ritorna false
    while ( pTmp != nullptr ) {
        if ( pTmp->info == info ) {
            return true;
        }

        pTmp = pTmp->next;
    }

    return false;
}

bool aggiungiElemento( Insieme_t **pInsieme, Insieme_t *pElemento ) {

    // Utilizzo l'algoritmo per l'inserimento in testa ( più pratico e veloce )

    if ( cercaElemento( ( *pInsieme ), pElemento->info ) ) {
        cancellaElemento( pElemento );

        return false;
    }
    
    pElemento->next = *pInsieme;
    *pInsieme = pElemento;

    return true;
}

void cancellaElemento( Insieme_t *pElemento ) {

    delete pElemento;
}

bool cancellaElementoInTesta( Insieme_t **pInsieme ) {

    if ( checkInsiemeVuoto( *pInsieme ) ) {
        return false;
    }

    Insieme_t *pTmp = ( *pInsieme );
    ( *pInsieme ) = ( *pInsieme )->next;

    cancellaElemento( pTmp );

    return true;
}

bool cancellaElementoInInsieme( Insieme_t **pInsieme, int info ) {

    // Elemento assente o insieme vuoto
    if ( !cercaElemento( ( *pInsieme ), info ) ) {
        return false;
    }

    // L'elemento da rimuovere è in testa
    if ( ( *pInsieme )->info == info ) {
        cancellaElementoInTesta( pInsieme );

        return true;
    }

    Insieme_t *pPrev = *pInsieme;
    Insieme_t *pTmp = pPrev->next;
    
    while ( pTmp != nullptr ) {
        if ( pTmp->info == info ) {
            pPrev->next = pTmp->next;

            cancellaElemento( pTmp );

            return true;
        }

        pPrev = pTmp;
        pTmp = pTmp->next;
    }

    return false;
}

void cancellaInsieme( Insieme_t **pInsieme ) {

    while ( !checkInsiemeVuoto( *pInsieme ) ) {
        cancellaElementoInTesta( pInsieme );
    }
}

bool stampaInsieme( Insieme_t *insieme ) {

    if ( checkInsiemeVuoto( insieme ) ) {
        return false;
    }

    Insieme_t *pTmp = insieme;

    while ( pTmp != nullptr ) {
        cout << pTmp->info << endl;

        pTmp = pTmp->next;
    }
    
    return true;
}

int cardinalitaInsieme( Insieme_t *insieme ) {

    if ( checkInsiemeVuoto( insieme ) ) {
        return 0;
    }

    Insieme_t *pTmp = insieme;
    int contatore = 0;

    while ( pTmp != nullptr ) {
        contatore++;

        pTmp = pTmp->next;
    }

    return contatore;
}

Insieme_t *unioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 ) {

    // Insieme che conterrà l'unione delle due
    Insieme_t *insiemeUnione = creaInsieme();

    // insieme1 non ha duplicati: ne copio tutti gli elementi
    for ( Insieme_t *p = insieme1; p != nullptr; p = p->next ) {
        aggiungiElemento( &insiemeUnione, creaElemento( p->info ) );
    }

    // Di insieme2 copio solo gli elementi non ancora nell'unione
    for ( Insieme_t *p = insieme2; p != nullptr; p = p->next ) {
        if ( !cercaElemento( insiemeUnione, p->info ) ) {
            aggiungiElemento( &insiemeUnione, creaElemento( p->info ) );
        }
    }

    return insiemeUnione;
}

Insieme_t *intersezioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 ) {
    
    Insieme_t *insiemeIntersezione = creaInsieme();

    // Copio gli elementi di insieme1 presenti anche in insieme2
    for ( Insieme_t *p = insieme1; p != nullptr; p = p->next ) {
        if ( cercaElemento( insieme2, p->info ) ) {
            aggiungiElemento( &insiemeIntersezione, creaElemento( p->info ) );
        }
    }

    return insiemeIntersezione;
}

Insieme_t *differenzaInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 ) {
    
    Insieme_t *insiemeDifferenza = creaInsieme();

    // Copio gli elementi di insieme1 che non sono in insieme2
    for ( Insieme_t *p = insieme1; p != nullptr; p = p->next ) {
        if ( !cercaElemento( insieme2, p->info ) ) {
            aggiungiElemento( &insiemeDifferenza, creaElemento( p->info ) );
        }
    }

    return insiemeDifferenza;
}