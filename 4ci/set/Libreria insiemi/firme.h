//
// Created by Admin on 21/10/2026.
//

#ifndef AS2026_2027_FIRME_H
#define AS2026_2027_FIRME_H
#include "types.h"
void stampaInsieme(Insieme_t* head);

void inserisciElemento(Insieme_t** pHead, int valore);

void rimuoviElemento(Insieme_t** pHead, int valore);

Insieme_t* unioneInsiemi(Insieme_t* pA, Insieme_t* pB);

Insieme_t* intersezioneInsiemi(Insieme_t* pA, Insieme_t* pB);

Insieme_t* differenzaInsiemi(Insieme_t* pA, Insieme_t* pB);

int numeroElementi(Insieme_t* head);

bool insiemeContenuto(Insieme_t* pA, Insieme_t* pB);

bool insiemiCoincidenti(Insieme_t* pA, Insieme_t* pB);

Insieme_t* duplicaInsieme(Insieme_t* head);
#endif //AS2026_2027_FIRME_H
