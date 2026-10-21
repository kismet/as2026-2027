#ifndef FUNZIONI_H
#define FUNZIONI_H
#include "types.h"

Insieme_t* creaInsieme(int valore);

void stampaInsieme(Insieme_t* head);

void inserisci(Insieme_t** pHead, int valore);

void rimuovi(Insieme_t** pHead, int valore);

Insieme_t* intersezione(Insieme_t* head, Insieme_t* testa);

Insieme_t* unione(Insieme_t* head, Insieme_t* testa);

Insieme_t* differenza(Insieme_t* head, Insieme_t* testa);

int cardinalita(Insieme_t* head);

bool coincidente(Insieme_t* head, Insieme_t* testa);

bool contenuto(Insieme_t* head, Insieme_t* testa);


#endif
