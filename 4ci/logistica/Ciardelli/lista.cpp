#include <iostream>
#include "lista.h"
using namespace std;

node_t* creaNodo(int codice, float kg, string prov){
	
	node_t* node = new node_t;
	node->next = nullptr;
	node->pacco.ID = codice;
	node->pacco.peso = kg;
	node->pacco.destinazione = prov;
	
	return node;
	
}

int letteraIniziale(string dest){
	
	char first = dest[0];
	
	if (first >= 'a' && first <= 'z'){
		
		return (first - 'a');
		
	}
	
	return (first - 'A');
	
}

void inserisciPacco(node_t* nodo, string provincia){
	
	int iniziale = letteraIniziale(provincia);
	
	if (elenco[iniziale] != nullptr){
		
		nodo->next = elenco[iniziale];
		
	}
	
	elenco[iniziale] = nodo;
	
}
