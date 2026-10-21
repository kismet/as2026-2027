#ifndef LISTECONSISTEMI_H
#define LISTECONSISTEMI_H
#include <iostream>

using namespace std;

typedef struct element {
	int info;
	struct element* next;
}element_t;

element_t* creaInsieme(int valore);

void stampa(element_t* head);

element_t* inserisciOrdinato(element_t* head, element_t* aux);

element_t* rimuovi(element_t* head, element_t* aux = nullptr, int numero = 0);

element_t* intersezione(element_t* head, element_t* head2);

element_t* copia(element_t* head, element_t* aux = nullptr);

element_t* unione(element_t* head, element_t* head2);

element_t* sottrazione(element_t* head, element_t* head2);

int cardinalita(element_t* head); //numero di elementi nell'insieme

bool uguaglianza(element_t* head, element_t* head2);

bool contenuto(element_t* head, element_t* head2); //se head contiene head2

#endif
