#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

typedef struct Pacco{
	
	int ID;
	float peso;
	string destinazione;
	
}pacco_t;

typedef struct Node{
	
	pacco_t pacco;
	struct Node* next;
	
}node_t;

node_t* elenco[26];

node_t* creaNodo(int codice, float kg, string prov);

int letteraIniziale(string dest);

void inserisciPacco(node_t* nodo, string provincia);

void printPacchi(string provincia);

void printAll(node_t* elenco[], int province);

#endif
