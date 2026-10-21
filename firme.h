#ifndef INSIEMI_LISTE_FIRME_H
#define INSIEMI_LISTE_FIRME_H

#include "type.h"

void stampaInsieme(Nodo_t* head);
bool appartiene(Nodo_t* head, int valore);
void inserisciElemento(Nodo_t** pHead, int valore);
void rimuoviElemento(Nodo_t** pHead, int valore);
Nodo_t* intersezione(Nodo_t* pA, Nodo_t* pB);
Nodo_t* unione(Nodo_t* pA, Nodo_t* pB);
Nodo_t* differenza(Nodo_t* pA, Nodo_t* pB);
int cardinalita(Nodo_t* head);
bool uguaglianza(Nodo_t* pA, Nodo_t* pB);
// Inclusione stretta: A e' contenuto in B, ma A e B non sono uguali.
bool contenuto(Nodo_t* pA, Nodo_t* pB);

#endif