#include <iostream>
#include <cstring>
#include "firme.h"
using namespace std;

static Nodo_t* elencoProvince[5];

void inizializzaElenco(){
	for(int i = 0; i < 5; i++){
		elencoProvince[i]->next = nullptr;
	}
}
int getProvincia(string p){
	string provincia = p;
	if(provincia == "Pisa"){
		return 0;
	}
	else if(provincia == "Lucca"){
		return 1;
	}
	else if(provincia == "Roma"){
		return 2;
	}
	else if(provincia == "Milano"){
		return 3;
	}
	else if(provincia == "Livorno"){
		return 4;
	}
	return -1;
}
bool spedisciPacco(string dest, int identity, float peso){
	Pacco_t p;
	p.destinazione = dest;
	p.identificativo = identity; //ASSENTE IL CONTROLLO PER ID ESISTENTE
	p.peso = peso;
	
	int index = getProvincia(p.destinazione);
	
	if(index == -1){
		return false;
	}
	Nodo_t* cursor = elencoProvince[index];
	Nodo_t* tmp = new Nodo_t;
	tmp->next = nullptr;
	tmp->pacco.destinazione = p.destinazione;
	tmp->pacco.identificativo = p.identificativo;
	tmp->pacco.peso = p.peso;
	if(cursor == nullptr){
		elencoProvince[index] = tmp;
	}
	else{
		while(cursor->next != nullptr){
			cursor = cursor->next;
		}
		cursor->next = tmp;
	}
	return true;
}
void printPacchi(string provincia){
	int index = getProvincia(provincia);
	if(index != -1){
		Nodo_t* cursor = elencoProvince[index];
		while(cursor != nullptr){
			cout << cursor->pacco.identificativo << "  " << cursor->pacco.peso << "  " << cursor->pacco.destinazione << endl;
			cursor = cursor->next;
		}
	}
}
void printAll(){
	Nodo_t* cursor = nullptr;
	for(int i = 0; i < 5; i++){
		cursor = elencoProvince[i];
		//Potevi riusare printPacchi
		while(cursor != nullptr){
			cout << cursor->pacco.identificativo << "  " << cursor->pacco.peso << "  " << cursor->pacco.destinazione << endl;
			cursor = cursor->next;
		}
	}
}
bool cambiaDestinazione(int identity, string oldDestination, string newDestination){
	int index = getProvincia(oldDestination);
	if(index == -1){
		return false;
	}
	Nodo_t* cursor = elencoProvince[index];
	Nodo_t* pre = nullptr;
	//La condizione scritta cosi ti porta a "segmentation fault" quando arrivi a cursor == nullptr
	while(cursor->pacco.identificativo != identity and cursor != nullptr){
		pre = cursor;
		cursor = cursor->next;
	}
	if(cursor == nullptr) return false;
	pre->next = cursor->next;
	cursor->next = nullptr;
	//Avresti potuto riusare la funzione spedisciPacco
	index = getProvincia(newDestination);
	if(index == -1){
		return false;
	}
	Nodo_t* tail = elencoProvince[index];
	while(tail->next != nullptr){
		tail = tail->next;
	}
	tail->next = cursor;
	return true;
}
bool rimuoviPacco(int identity){
	Nodo_t* cursor = nullptr;
	Nodo_t* pre = nullptr;
	for(int i = 0; i < 5; i++){
		cursor = elencoProvince[i];
		pre = nullptr;
		while(cursor != nullptr){
			if(cursor->pacco.identificativo == identity and pre != nullptr){
				pre->next = cursor->next;
				cursor->next = nullptr;
			}
			else if(cursor->pacco.identificativo == identity and pre == nullptr){
				elencoProvince[i] = cursor->next;
				cursor->next = nullptr;
				return true;
			}
			pre = cursor;
			cursor = cursor->next;
		}
	}
	return false;
}
void stampaCarico(){
	int loadMax = 0;
	int nPacchi = 0;
	
	Nodo_t* furgone = nullptr;
	
	while(loadMax <= 1500 and nPacchi <= 200){
		//AGGIUNGE UN PACCO ALLA LISTA
		//LO RIMUOVO DALL'ELENCO
		//INCREMENTA PESO E NUMERO PACCHI
		//STAMPO UNA VOLTA USCITO DAL WHILE
	}
}
