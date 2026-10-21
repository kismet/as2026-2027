#ifndef INSIEMI_H
#define INSIEMI_H

#include <iostream>
using namespace std;

typedef struct Nodo{
	int info;
	struct Nodo* next;
}nodo_t;

nodo_t* crea_nodo(int valore);

void inserisci_nodo(nodo_t* head[], int tot_insiemi, nodo_t* nodo);

void stampa(nodo_t* head[], int tot_insiemi);

nodo_t* rimuovi_nodo(nodo_t* head[], int tot_insiemi);

void intersezione(nodo_t* head[], int tot_insiemi);

void unione(nodo_t* head[], int tot_insiemi);

void differenza(nodo_t* head[], int tot_insiemi);

int numero_elementi(nodo_t* head[], int tot_insiemi);

bool uguaglianza(nodo_t* head[], int tot_insiemi);

bool insieme_contenuto(nodo_t* head[], int tot_insiemi);

#endif
