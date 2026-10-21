#ifndef INSIEMI_H
#define INSIEMI_H

#include <iostream>
using namespace std;

typedef struct Nodo{
	int info;
	struct Nodo* next;
}nodo_t;

nodo_t* crea_nodo(int valore);

void inserisci_nodo_in_testa(nodo_t* head[], int &insieme, nodo_t* nodo);

void stampa(nodo_t* head[], int &insieme);

nodo_t* rimuovi_nodo(nodo_t* head[], int &insieme, int posizione);

void unione(nodo_t* head[], int &insieme1, int &insieme2);

void intersezione(nodo_t* head[], int &insieme);

int differenza(nodo_t* head[], int &insieme1, int &insieme2);

int numero_elementi(nodo_t* head[], int &insieme);

bool uguaglianza(nodo_t* head[], int &insieme1, int &insieme2);

bool insieme_contenuto(nodo_t* head[], int &insieme1, int &insieme2);

#endif
