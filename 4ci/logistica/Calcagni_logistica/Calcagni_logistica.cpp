#include <iostream>
#include <string>
using namespace std;

typedef struct Pacco{
	string id;
	int peso;
	string destinazione;
	struct Pacco* next;
} Pacco_t;

void inserisciPacco(Pacco_t* elenco, string ID, int Peso, string provincia){
	Pacco_t* nuovoPacco = new Pacco_t;
	nuovoPacco->id = ID;
	nuovoPacco->peso = Peso;
	nuovoPacco->destinazione = provincia;
	nuovoPacco->next = nullptr;
	//non funziona per la lista vuota perché 
 //non cambi elenco 
	Pacco_t* aux = elenco;
	while(aux != nullptr){
		aux = aux->next;
	}
	aux->next = nuovoPacco;
}

void stampaPacchiDataProvincia(Pacco_t* elenco[], int nProvince, string provincia){
//non selezioni la lista da cui stampare 
	Pacco_t* aux = nullptr;
	
	while(aux != nullptr){
		cout << aux->id << " " << aux->peso << "kg " << aux->destinazione << endl;
		aux = aux->next;
	}
}

void stampaPacchi(Pacco_t* elenco[], int nProvince){
	int contatore = 0;
	Pacco_t* aux = elenco[contatore];
	while(nProvince != contatore){
		while(aux != nullptr){
			cout << aux->id << " " << aux->peso << "kg " << aux->destinazione << endl;
			aux = aux->next;
		}
		contatore++;
		aux = elenco[contatore];
	}
}

int main(){
	const int nProvince = 20;
	Pacco_t* destinazioniProvincie[nProvince];
	
}
