
#ifndef GESTIONEINSIEME_H
#define GESTIONEINSIEME_H

#include "insiemeTypes.h"

// Creazione e controllo
Insieme_t *creaInsieme();
Insieme_t *creaElemento( int elemento );
bool checkInsiemeVuoto( Insieme_t *insieme );

// Ricerca
// Restituisce true se l'insieme è vuoto, altrimenti false
bool cercaElemento( Insieme_t *insieme, int elemento );

// Modifica
// Se l'elemento è già presente nell'insieme restituisco false e cancello l'elemento
bool aggiungiElemento( Insieme_t **pInsieme, Insieme_t *pElemento );
// Per rimozione intendo rimozione elemento dall'insieme + cancellazione
void cancellaElemento( Insieme_t **pInsieme, int elemento );
void cancellaInsieme( Insieme_t **pInsieme );

// Stampa e conta
// Restituisco false se l'insieme è vuoto
bool stampaInsieme( Insieme_t *insieme );
int cardinalitaInsieme( Insieme_t *insieme );

// Operazioni fra insiemi
Insieme_t *unioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );
Insieme_t *intersezioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );
Insieme_t *differenzaInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );

// Confronti
bool contenuto( Insieme_t *insieme1, Insieme_t *insieme2 );
bool coincidente( Insieme_t *insieme1, Insieme_t *insieme2 );

#endif