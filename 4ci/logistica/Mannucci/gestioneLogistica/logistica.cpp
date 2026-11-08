
#include "logistica.h"
#include <iostream>
#include <string>

using namespace std;

static void inserisciInTesta( Pacco_t **phead, Pacco_t *pAux ) {

    if ( ( *phead ) != nullptr ) {
        pAux->next = ( *phead );
    }

    ( *phead ) = pAux;
}

static void rimuoviPacco( Pacco_t **phead, Pacco_t *pAux ) {
    //Questa non è quella richiesta dal testo, giusto?
    // TODO: check se solo 1 pacco

    Pacco_t *pPrev;

    while ( pPrev->next != pAux ) {
        pPrev = pPrev->next;
    }

    pPrev->next = pAux->next;

    pAux->next = nullptr;

    delete pAux;
}

bool inserisciPacco( Pacco_t *pPacco, ElemArray_t province[] ) {

    for ( int i = 0; i < NUMPROVINCE; i++ ) {
        if ( pPacco->pacco.destinazione == province[i].provincia ) {
            //Inserimento doveva essere in coda
            inserisciInTesta( &province[i].head, pPacco );

            return true;
        }
    }

    return false;
}

void stampaPacchiProvincia(ElemArray_t province[], std::string destinazione ) {

    bool stampato = false;

    for ( int i = 0; i < NUMPROVINCE && !stampato; i++ ) {
        if ( province[i].provincia == destinazione ) {
            // Stampo
            int i = 1;
            //Potevi riusare stampa pacchi
            for ( Pacco_t *pTmp = province[i].head ; pTmp != nullptr; pTmp = pTmp->next ) {
                cout << "Pacco: " << i << endl;
                cout << "ID: " << pTmp->pacco.id << endl;
                cout << "Peso: " << pTmp->pacco.peso << endl;
                cout << endl;

                i++;
            }

            stampato = true;
        }
    }

    if ( !stampato ) {
        cout << "La provincia del pacco non corrisponde a nessuna provincia presente in elenco." << endl;
    }
}

void stampaPacchi( ElemArray_t province[] ) {

    for ( int i = 0; i < NUMPROVINCE; i++ ) {
        // Stampo
        int j = 1;

        for ( Pacco_t *pTmp = province[j].head ; pTmp != nullptr; pTmp = pTmp->next ) {

            if ( j == 1 ) {
                cout << "Provincia: " << province[i].provincia << endl;
                cout << endl;
            }

            cout << "Pacco: " << j << endl;
            cout << "ID: " << pTmp->pacco.id << endl;
            cout << "Peso: " << pTmp->pacco.peso << endl;
            cout << endl;

            j++;
        }
    }
}

bool cambiaDestinazione( int id, std::string oldProvincia, std::string newDestinazione, ElemArray_t province[] ) {

    for ( int i = 0; i < NUMPROVINCE; i++ ) {
        if ( province[i].provincia == oldProvincia ) {
            for ( Pacco_t *pTmp = province[i].head ; pTmp != nullptr; pTmp = pTmp->next ) {
                if ( pTmp->pacco.id == id ) {
                    //Andava spostato anche nella lista corretta
                    pTmp->pacco.destinazione = newDestinazione;

                    return true;
                }
            }
        }
    }

    return false;
}

bool rimuoviPacco( int id, ElemArray_t province[] ) {

    for ( int i = 0; i < NUMPROVINCE; i++ )
    {
        for ( Pacco_t *pTmp = province[i].head ; pTmp != nullptr; pTmp = pTmp->next )
        {
            if ( pTmp->pacco.id == id )
            {
                // CHIAMATA A FUNZIONE
            }
        }
    }
}
