//
// Created by Admin on 21/10/2026.
//

#ifndef AS2026_2027_FIRME_H
#define AS2026_2027_FIRME_H
#include "types.h"
void stampaInsieme(Nodo_t* head);

void inserisciElemento(Nodo_t** pHead, int valore);

void rimuoviElemento(Nodo_t** pHead, int valore);

Nodo_t* unioneInsiemi(Nodo_t* pA, Nodo_t* pB);

Nodo_t* intersezioneInsiemi(Nodo_t* pA, Nodo_t* pB);

Nodo_t* differenzaInsiemi(Nodo_t* pA, Nodo_t* pB);

int numeroElementi(Nodo_t* head);

bool insiemeContenuto(Nodo_t* pA, Nodo_t* pB);

bool insiemiCoincidente(Nodo_t* pA, Nodo_t* pB);

Nodo_t* duplicaInsieme(Nodo_t* head);
#endif //AS2026_2027_FIRME_H
