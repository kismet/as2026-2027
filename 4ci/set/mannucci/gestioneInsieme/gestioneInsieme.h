
#ifndef GESTIONEINSIEME_H
#define GESTIONEINSIEME_H

#include "insiemeTypes.h"

// Creazione e controllo
Insieme_t *creaInsieme();
Insieme_t *creaElemento( int elemento );
// Restituisce true se l'insieme è vuoto, altrimenti false
bool checkInsiemeVuoto( Insieme_t *insieme );

// Ricerca
bool cercaElemento( Insieme_t *insieme, int info );

// Modifica
// Se l'elemento è già presente nell'insieme restituisco false e cancello l'elemento
bool aggiungiElemento( Insieme_t **pInsieme, Insieme_t *pElemento );
// Cancella il singolo nodo, senza toccare l'insieme
void cancellaElemento( Insieme_t *pElemento );
// Rimuove e cancella il primo elemento. false se l'insieme è vuoto
bool cancellaElementoInTesta( Insieme_t **pInsieme );
// Rimuove e cancella l'elemento con quel valore. false se non è presente
bool cancellaElementoInInsieme( Insieme_t **pInsieme, int info );
void cancellaInsieme( Insieme_t **pInsieme );

// Stampa e conta
// Restituisco false se l'insieme è vuoto
bool stampaInsieme( Insieme_t *insieme );
int cardinalitaInsieme( Insieme_t *insieme );       // 0 se l'insieme è vuoto

// Operazioni fra insiemi
Insieme_t *unioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );
Insieme_t *intersezioneInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );
Insieme_t *differenzaInsiemi( Insieme_t *insieme1, Insieme_t *insieme2 );

// Confronti
// true se insieme1 è contenuto in insieme2, l'insieme vuoto è contenuto in qualsiasi insieme
bool contenuto( Insieme_t *insieme1, Insieme_t *insieme2 );
// true se i due insiemi hanno gli stessi elementi, a prescindere dall'ordine
bool coincidente( Insieme_t *insieme1, Insieme_t *insieme2 );

#endif // GESTIONEINSIEME_H