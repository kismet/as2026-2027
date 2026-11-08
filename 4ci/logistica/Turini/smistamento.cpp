#include "smistamento.h"

bool insersciPacco(provincie_t Provincie[], pacco_t* pack, int numeroProvincie){
	bool riuscito = true;
	int salvaI = -1;
	for(int i = 0; i < numeroProvincie; i++){
		if (Provincie[i].provincia == pack->provincia) {
			salvaI = i;
		}
	}
	
	if(salvaI != -1){
		if (Provincie[salvaI].next != nullptr){
			pacco_t* scorriProv = Provincie[salvaI].next;
			while(scorriProv -> next != nullptr){
				scorriProv = scorriProv -> next;
			}
			
			scorriProv -> next = pack;
		}
		else{
			Provincie[salvaI].next = pack;
		}
	}
	else{
		riuscito = false;
	}
	
	return riuscito;
	
}

void printPacchi(provincie_t Provincie[], string nomeProvincia, int numeroProvincie){
	int salvaI = -1;
	for(int i = 0; i < numeroProvincie; i++){
		if (Provincie[i].provincia == nomeProvincia) {
			salvaI = i;
		}
	}
	
	if(salvaI != -1){
		pacco_t* scorriProv = Provincie[salvaI].next;
		cout<<"Stampa di tutti i pacchi della provincia: "<<scorriProv ->provincia<<endl;
		while(scorriProv != nullptr){
			cout<<"ID: "<<scorriProv->id<<" Peso: "<<scorriProv->peso<<endl;
			scorriProv = scorriProv -> next;
		}
	}
	
}

void printAll(provincie_t Provincie[], int numeroProvincie){
	for(int i = 0; i < numeroProvincie; i++){
		printPacchi(Provincie, Provincie[i].provincia, numeroProvincie);
	}
}

bool cambiaDestinazione(provincie_t Provincie[], int ID, string vecchiaprovincia, string nuovaprovincia, int numeroProvincie){
	bool risultato = true;
	int salvaI = -1;
	for(int i = 0; i < numeroProvincie; i++){
		if (Provincie[i].provincia == vecchiaprovincia) {
			salvaI = i;
		}
	}
	
	if(salvaI == -1){
		risultato = false;
	}
	
	pacco_t* scorriLista;
	pacco_t* salvaNodo;
	
	scorriLista = Provincie[salvaI].next;
	while(scorriLista != nullptr){
		if(scorriLista->id == ID){
			salvaNodo = scorriLista -> next;
		}
	}
	
	if(salvaNodo == nullptr){
		risultato = false;
	}
	
	pacco_t* copiaNodo;
	copiaNodo->provincia = nuovaprovincia;
	copiaNodo->id = salvaNodo -> id;
	copiaNodo->peso = salvaNodo -> peso;
	copiaNodo -> next = nullptr;
	
	bool check = rimuoviPacco(Provincie, salvaNodo -> id, numeroProvincie);
	
	if(!check){
		risultato = false;
	}
	
	check = insersciPacco(Provincie, copiaNodo, numeroProvincie);
	
	if(!check){
		risultato = false;
	}
	
	return risultato;
	
}

bool rimuoviPacco(provincie_t Provincie[], int ID, int numeroProvincie){
	bool risultato = false;
	pacco_t* scorriLista;
	string provincia;
	pacco_t* puntatorePrecedente = nullptr;
	pacco_t* salvaNodo;
	for(int i = 0; i < numeroProvincie; i++){
		scorriLista = Provincie[i].next;
		if(scorriLista -> id == ID){
			salvaNodo = scorriLista;
			provincia = Provincie[i].provincia;
		}
		while(scorriLista != nullptr){
			if(scorriLista->next ->id == ID){
				puntatorePrecedente = scorriLista;
				salvaNodo = scorriLista -> next;
			}
		}
	}
	
	if(puntatorePrecedente != nullptr){
		puntatorePrecedente -> next = salvaNodo -> next;
		salvaNodo -> next = nullptr;
		delete salvaNodo;
		risultato = true;
	}
	else{
		int salvaI = -1;
		for(int i = 0; i < numeroProvincie; i++){
			if (Provincie[i].provincia == provincia) {
				salvaI = i;
			}
		}
		Provincie[salvaI].next = salvaNodo -> next;
		salvaNodo -> next = nullptr;
		delete salvaNodo;
		risultato = true;
	}
	
	return risultato;
	
}

void stampaBolleCarico(provincie_t Provincie[], provincie_t Spedizioni[], int numeroProvincie, int numeroSpedizioni){
	if(numeroProvincie == numeroSpedizioni){
		pacco_t* head = nullptr;
		pacco_t* scorriHead = head;
		pacco_t* scorriProvincie;
		pacco_t* copiaPacco;
		for(int i = 0; i < numeroProvincie; i++){
			scorriProvincie = Provincie[i].next;
			int sommapeso = 0;
			for(int j = 0; j < NUMEROMASSIMOPACCHI and scorriProvincie != nullptr; i++){
				scorriHead = head;
				if((sommapeso + scorriProvincie ->peso) <= PESOMASSIMOFURGONE){
					
					copiaPacco ->provincia = scorriProvincie ->provincia;
					copiaPacco ->id = scorriProvincie ->id;
					copiaPacco ->peso = scorriProvincie ->peso;
					copiaPacco ->next = nullptr;
					
					while(scorriHead -> next != nullptr){
						scorriHead = scorriHead -> next;
					}
					
					scorriHead -> next = copiaPacco;
					
				}
				sommapeso += scorriProvincie -> peso;
			}
			Spedizioni[i].provincia = Provincie[i].provincia;
			Spedizioni[i].next = head;
			head = nullptr;
		}
	}
}
