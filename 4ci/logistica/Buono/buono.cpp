#include <iostream>
#include <string>

using namespace std;

typedef struct Pacco{
	
	int id;
	int peso;
	string destinazione;
	
}Pacco_t;

typedef struct Nodo{
	
	Pacco_t pacco;
	struct Nodo* next;
	
}Nodo_t;

const int nProvince = 3;

Nodo_t* elenco[nProvince];

void inizializzaElenco(){
	for(int i = 0; i < nProvince; i++){
		
		elenco[i]=nullptr;
	}
	
}
Nodo_t* creaPacco(int id, int weight, string destination){
	
	Nodo_t* p = new Nodo_t;
	
	p->next = nullptr;
	p->pacco.destinazione = destination;
	p->pacco.id = id;
	p->pacco.peso = weight;
	
	return p;
	
}
//inserimento in testa invece che in coda 
//errore nell'implementazione 
void inserisciInTesta(Nodo_t** pHead, Nodo_t* pacco){
	
	if(*pHead != nullptr){
		
		*pHead = pacco;
		
	}
	pacco->next = *pHead;
	
}

void stampaLista(Nodo_t* head){
	//dove si stampa la provincia?
	while(head != nullptr){
		
		cout<< head->pacco.id<< endl;
		cout<< head->pacco.peso<< endl<<endl;
		head = head->next;
	}
	
}

bool insericiPacco(Nodo_t* p){
	//uso del if limitato considerando un caso generico 
	if(p->pacco.destinazione == "Firenze"){
		
		inserisciInTesta(&elenco[0], p);
		//quale è il senso di questo
  //idem per le altre provincie 
		elenco[0]->pacco.destinazione == "Firenze";
		elenco[0]->pacco.peso = p->pacco.peso;
		elenco[0]->pacco.id = p->pacco.id;
		
		return true;
		
	}
	else if(p->pacco.destinazione == "Pisa"){
		
		inserisciInTesta(&elenco[1], p);
		//perché indice 0?
		elenco[0]->pacco.destinazione == "Pisa";
		elenco[0]->pacco.peso = p->pacco.peso;
		elenco[0]->pacco.id = p->pacco.id;
		
		return true;
	}
	else if(p->pacco.destinazione == "Livorno"){
		
		inserisciInTesta(&elenco[2], p);
		//perché indice 0?
		elenco[0]->pacco.destinazione == "Livorno";
		elenco[0]->pacco.peso = p->pacco.peso;
		elenco[0]->pacco.id = p->pacco.id;
		
		return true;
	}
	return false;
	
}
void printPacchi(string provincia){
	
	if(provincia == "Firenze"){
		
	}
	else if(provincia == "Pisa"){
		
	}
	else if(provincia == "Livorno"){
		
	}
	
}
void printAll(Pacco_t* elenco[], int nProvince);

int main(){
	
	inizializzaElenco();
	
	
}

