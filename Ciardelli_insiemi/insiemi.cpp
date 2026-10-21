#include <iostream>
#include "insiemi.h"
using namespace std;

nodo_t* crea_nodo(int valore){
	
	nodo_t* nodo = new nodo_t;
	nodo->info = valore;
	nodo->next = nullptr;
	
	return nodo;
	
}

void inserisci_nodo_in_testa(nodo_t* head[], int &insieme, nodo_t* nodo){
	
	if (head[insieme] != nullptr){
		
		nodo->next = head[insieme];
		
	}
	
	head[insieme] = nodo;
	
}

void stampa(nodo_t* head[], int &insieme){
	
	nodo_t* curr = head[insieme];
	
	while(curr != nullptr){
		
		cout << curr->info << " ";
		curr = curr->next;
		
	}
	
	cout << endl << endl;
	
}
