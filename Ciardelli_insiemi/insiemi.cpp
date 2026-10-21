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
	
	while (curr != nullptr){
		
		cout << curr->info << " ";
		curr = curr->next;
		
	}
	
	cout << endl << endl;
	
}

nodo_t* rimuovi_nodo(nodo_t* head[], int &insieme, int posizione){
	
	if (head[insieme] == nullptr){
		
		return nullptr;
		
	}
	
	nodo_t* rim = head[insieme];
	int cont = 1;
	bool condizione = true;
	
	while (rim->next != nullptr && condizione == true){
		
		if (posizione == cont){
			
			head[insieme] = head[insieme]->next;
			rim->next = nullptr;
			condizione = false;
			
		}
		
		rim = rim->next;
		cont++;
		
	}
	
	return rim;
	
}

void unione(nodo_t* head[], int &insieme1, int &insieme2){
	
	nodo_t* tmp = head[insieme1];
	
	while (tmp->next != nullptr){
		
		tmp = tmp->next;
		
	}
	
	tmp->next = head[insieme2];
	
}

int numero_elementi(nodo_t* head[], int &insieme){
	
	int elementi = 0;
	nodo_t* tmp = head[insieme];
	
	while (tmp != nullptr){
		
		elementi++;
		tmp = tmp->next;
		
	}
	
	return elementi;
	
}

bool uguaglianza(nodo_t* head[], int &insieme1, int &insieme2){
	
	if (numero_elementi(head, insieme1) == numero_elementi(head, insieme2)){
		
		return true;
		
	}
	
	return false;
	
}

int differenza(nodo_t* head[], int &insieme1, int &insieme2){
	
	int dif, ins1 = numero_elementi(head, insieme1), ins2 = numero_elementi(head, insieme2);
	
	if (ins1 >= ins2){
		
		dif = ins1 - ins2;
		
	}
	else {
		
		dif = ins2 - ins1;
		
	}
	
	return dif;
	
}
