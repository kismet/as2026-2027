#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include "library_types.h"

void stampaInsieme(Insieme_t* insieme);

bool inserisciInsieme(Insieme_t*& insieme, int valore);

bool rimuoviElementoInsieme(Insieme_t*& insieme, int valore);

Insieme_t* intersezioneInsiemi(Insieme_t* insieme1, Insieme_t* insieme2);

Insieme_t* unioneInsiemi(Insieme_t* insieme1, Insieme_t* insieme2);

Insieme_t* differenzaInsiemi(Insieme_t* insieme1, Insieme_t* insieme2);

int cardinalitaInsieme(Insieme_t* insieme);

bool uguaglianzaInsiemi(Insieme_t* insieme1, Insieme_t* insieme2);

bool contenimentoInsiemi(Insieme_t* insieme1, Insieme_t* insieme2);

void aggiungiInFondo(Insieme_t*& testa, Insieme_t*& fine, int valore);

#endif // UNTITLED_LIBRARY_H