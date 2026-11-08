#include <iostream>
using namespace std;

/*il sistema deve:
inserire pacchi
stampare tutti i pacchi da spedire per una specifica destinazionene
stampare tutti i pacchi da spedire*/

/*suggerimenti:
bool spedisciPacco(Pacco* elenco[], Pacco p);
void printPacchi(string provincia);
void printAll(Pacco* elenco[], int nprovincie);*/

//livorno pisa firenze lucca prato (province scelte)

typedef struct Info {
	int id;
	int peso;
	string destinazione;
}Info_t;

typedef struct Nodo{
	Info_t* info;
	struct Nodo* next;
}Nodo_t;

Nodo_t* provincie[4];

void inizialize(){
	for (int i = 0; i < 4; i++){
		provincie[i] = nullptr;
	}
}
//Non funxions per numero di provincie elevato
int GetIndex (string provincia){
	if (provincia == "Pisa" or provincia == "pisa") return 0;
	if (provincia == "Firenze" or provincia == "firenze") return 1;
	if (provincia == "Prato" or provincia == "prato") return 2;
	if (provincia == "Livorno" or provincia == "livorno") return 3;
	return -1;
}

Nodo_t* creaNodo (Info_t* p){
	Nodo_t* pNodo = new Nodo_t;
	pNodo->info = p;
	pNodo->next = nullptr;
	return pNodo;
}

bool spedisciPacco(Info_t p) {
	int indice = GetIndex(p.destinazione);
	if (indice < 0 || indice >= 5) {
		cout << "provincia non valida" << endl;
		return false;
	}
	//Non compila creaNodo vuole un puntatore ad Info_t e seondo come la riscrivi crei un problema di memory corruption
	Nodo_t* nuovoNodo = creaNodo(p);
	
	if (provincie[indice] == nullptr) {
		provincie[indice] = nuovoNodo;
	} else {
		Nodo_t* curr = provincie[indice];
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = nuovoNodo;
	}
	
	cout << "pacco ID " << p.id << " registrato con successo per " << p.destinazione << endl;
	return true;
}
void printPacchi(string provincia) {
	int indice = GetIndex(provincia);
	if (indice < 0 || indice >= 4) {
		cout << "questa provincias non esiste" << endl;
		return;
	}
	
	cout << "Pacchi da spedire per la provincia di " << provincia << endl;
	Nodo_t* curr = provincie[indice];
	if (curr == nullptr) {
		cout << "non ci sono pacchi in attesa per questa provincia" << endl;
		return;
	}
	//Non stampi la provincia
	while (curr != nullptr) {
		cout << "ID derl pacco: " << curr->info.id << " ,peso del pacco: " << curr->info.peso << " kg" << endl;
		curr = curr->next;
	}
}
void printAll(Nodo_t* elenco[], int nprovincie) {
	string nomiProvince[4] = {"Pisa", "Firenze", "Prato", "Livorno"};
	bool vuotoTotale = true;
	
	for (int i = 0; i < nprovincie; i++) {
		//Potevi riusare la funzion printPacchi
		cout << "destinazione: " << nomiProvince[i] << endl;
		Nodo_t* curr = elenco[i];
		if (curr == nullptr) {
			cout << "  nessun pacco " << endl;
		} else {
			vuotoTotale = false;
			while (curr != nullptr) {
				cout << "id el pacco: " << curr->info.id << " e peso del pacco: " << curr->info.peso << " kg" << endl;
				curr = curr->next;
			}
		}
	}
}
