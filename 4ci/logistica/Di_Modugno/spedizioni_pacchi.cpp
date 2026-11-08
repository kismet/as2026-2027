#include <iostream>
using namespace std;
/*
Scenario di realtà
Un centro di smistamento logistico riceve colli continui su un nastro trasportatore. Ogni pacco possiede un codice numerico univoco (ID), un peso in kg e una provincia di destinazione (quindi l'elenco delle province è noto a priori).

Strutture dati
Ogni Pacco è rappraresentato (id, peso, destinazione).
Un array contenente le liste di destinazioni delle provincie.
Obiettivi
Fase 1 (Base - Voto 6):
Per velocizzare lo smistamento ogni pacco viene inserimento in sequenziale in una coda legata alla provincia di destinazione. Il sistema deve essere in grado di:

inserire pacchi;
stampare tutti i pacchi da spedire per una specifica destinazionene
stampare tutti i pacchi da spedire.
Suggerimento API
bool spedisciPacco(Pacco p);
void printPacchi(string provincia);
void printAll(Pacco* elenco[], int nprovincie);
*/

// 1) creo la struct con i campi dell'ordine
// 2) creo la struct del nodo
// 3) faccio un'array in cui contiene tutte le liste con le varie province
// 4) fare una funzione che inserisci il pacco nella propria lista in base alla provincia inserita
// 5) fare una funziona che stampa i pacchi della destinazione scelta
// 6) fare una funziona che stampa i tutti i pacchi


// 1) struct che da i campi info
typedef struct Info{
	int id;
	int peso;
	string destinazione;
}Info_t;

// 2) struct che crea il nodo e da al campo info che ha i valori della struct info
typedef struct Node{
	Info_t info;			
	struct Node* next;
}Nodo_t;

Nodo_t* Province[5];		// così abbiamo creato un array di liste dove la testa viene chiamata Provincie e contiene 5 liste al suo interno
// province[0] = Pisa
// province[1] = Firenze
// province[2] = Prato
// province[3] = Lucca
// province[4] = Livorno

// inizializzo l'array che contiene le provincie a nullptr
void initialize(){					
	for(int i=0; i<5;i++){		
		Province[i] = nullptr;		
	}
}

// Funzione ausiliaria per trovare l'indice della provincia nell'array
int getIndex(string provincia) {
	if (provincia == "Pisa" || provincia == "pisa") return 0;
	if (provincia == "Firenze" || provincia == "firenze") return 1;
	if (provincia == "Prato" || provincia == "prato") return 2;
	if (provincia == "Lucca" || provincia == "lucca") return 3;
	if (provincia == "Livorno" || provincia == "livorno") return 4;
	return -1; // Provincia non valida
}

// Funzione ausiliaria per creare un nuovo nodo
Nodo_t* creaNodo(Info_t p) {
	Nodo_t* pNodo = new Nodo_t;
	pNodo->info = p;
	pNodo->next = nullptr;
	return pNodo;
}


// 4) Funzione che inserisce il pacco nella propria lista in base alla provincia inserita (in coda)
bool spedisciPacco(Info_t p) {
	int indice = getIndex(p.destinazione);
	if (indice < 0 || indice >= 5) {
		cout << "Errore: Provincia di destinazione non valida!" << endl;
		return false;
	}
	
	Nodo_t* nuovoNodo = creaNodo(p);
	
	// Inserimento in coda per rispettare la logica della coda di spedizione
	if (Province[indice] == nullptr) {
		Province[indice] = nuovoNodo;
	} else {
		Nodo_t* curr = Province[indice];
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = nuovoNodo;
	}
	
	cout << "Pacco ID " << p.id << " registrato con successo per " << p.destinazione << "." << endl;
	return true;
}

// 5) Funzione che stampa i pacchi della destinazione scelta
void printPacchi(string provincia) {
	int indice = getIndex(provincia);
	if (indice < 0 || indice >= 5) {
	}
	
	Nodo_t* curr = Province[indice];
	if (curr == nullptr) {
		cout << "Nessun pacco in attesa per questa provincia." << endl;
	}
	
	while (curr != nullptr) {
		cout << "ID Pacco: " << curr->info.id << " Peso: " << curr->info.peso << " kg" << endl;
		curr = curr->next;
	}
}

// 6) funzione che stampa tutti i pacchi
void printAll(Nodo_t* elenco[], int nprovincie){
	string nomiProvince[5] = {"Pisa", "Firenze", "Prato", "Lucca", "Livorno"};
	bool vuotoTotale = true;
	
	for (int i = 0; i < nprovincie; i++) {
		cout << "Destinazione: " << nomiProvince[i] << endl;
		Nodo_t* curr = elenco[i];
		if (curr == nullptr) {
			cout << "  (Nessun pacco)" << endl;
		} else {
			vuotoTotale = false;
			while (curr != nullptr) {
				cout << "ID: " << curr->info.id << "; Peso: " << curr->info.peso << "; kg" << endl;
				curr = curr->next;
			}
		}
	}
}

