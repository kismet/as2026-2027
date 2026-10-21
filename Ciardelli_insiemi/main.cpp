#include <iostream>
#include "insiemi.h"
using namespace std;

int main(){
	
	bool errore = true;
	int insiemi, scelta, insieme, nodi, valore, posizione, insieme1, insieme2;
	
	do {
		
		cout << "Inserisci il numero di insiemi (da 2 in poi): ";
		cin >> insiemi;
		cout << endl;
		
		if (insiemi < 2){
			
			cout << "Errore, riprova.\n\n";
			
		}
		else {
			
			errore = false;
			
		}
		
	}
	while (errore);
	
	errore = true;
	nodo_t* head[insiemi];
	
	for (int i = 0; i < insiemi; i++){
		
		head[i] = nullptr;
		
	}
	
	while (true){
		
		cout << "1) Inserisci nodo.\n";
		cout << "2) Stampa.\n";
		cout << "3) Rimuovi nodo.\n";
		cout << "4) Unione.\n";
		cout << "5) Intersezione.\n";
		cout << "6) Differenza.\n";
		cout << "7) Numero elementi.\n";
		cout << "8) Uguaglianza.\n";
		cout << "9) Insieme contenuto.\n\n";
		
		do {
			
			cout << "Scelta: ";
			cin >> scelta;
			cout << endl;
			
			if (scelta < 1 || scelta > 9){
				
				cout << "Errore, riprova.\n\n";
				
			}
			else {
				
				errore = false;
				
			}
			
		}
		while (errore);
		
		errore = true;
		
		if (scelta == 1){
			
			while (insieme <= 5){
				
				cout << "Inserisci il numero dell'insieme (da 1 a tot insiemi): ";
				cin >> insieme;
				cout << endl;
				insieme--;
				cout << "Inserisci il numero di nodi dell'insieme (da 1 in poi): ";
				cin >> nodi;
				cout << endl;
				
				for (int i = 0; i < nodi; i++){
					
					cout << "inserisci il valore nel nuovo nodo: ";
					cin >> valore;
					cout << endl;
					
					nodo_t* nodo = crea_nodo(valore);
					inserisci_nodo_in_testa(head, insieme, nodo);
					
				}
				
			}
			
		}
		else if (scelta == 2){
			
			cout << "Inserisci il numero dell'insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme--;
			
			stampa(head, insieme);
			
		}
		else if (scelta == 3){
			
			cout << "Inserisci il numero dell'insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme--;
			cout << "Inserisci la posizione del nodo dell'insieme che vuoi rimuovere (da 1 in poi): ";
			cin >> posizione;
			cout << endl;
			
			rimuovi_nodo(head, insieme, posizione);
		}
		else if (scelta == 4){
			
			cout << "Inserisci il numero del primo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme1--;
			cout << "Inserisci il numero del secondo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme2--;
			
			unione(head, insieme1, insieme2);
			
		}
		else if (scelta == 5){
			
			cout << "Inserisci il numero del primo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme1--;
			cout << "Inserisci il numero del secondo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme2--;
			
			intersezione(head, insieme1, insieme2);
			
		}
		else if (scelta == 6){
			
			cout << "Inserisci il numero del primo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme1--;
			cout << "Inserisci il numero del secondo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme2--;
			
			differenza(head, insieme1, insieme2);
			
		}
		else if (scelta == 7){
			
			cout << "Inserisci il numero dell'insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme--;
			
			numero_elementi(head, insieme);
			
		}
		else if (scelta == 8){
			
			cout << "Inserisci il numero del primo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme1--;
			cout << "Inserisci il numero del secondo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme2--;
			
			uguaglianza(head, insieme1, insieme2);
			
		}
		else {
			
			cout << "Inserisci il numero del primo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme1--;
			cout << "Inserisci il numero del secondo insieme (da 1 a tot insiemi): ";
			cin >> insieme;
			cout << endl;
			insieme2--;
			
			insieme_contenuto(head, insieme1, insieme2);
			
		}
		
	}
	
	return 0;
	
}
