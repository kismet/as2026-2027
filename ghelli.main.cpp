#include <iostream>
#include "funzioni.h"
using namespace std;

int main() {
	
	//inizializzo i punatori alle liste come vuoti
	insiemi lista1 = nullptr;
	insiemi lista2 = nullptr;
	
	//inserisco alcuni valori nella prima lista
	inserisci (lista1, 10);
	inserisci (lista1, 40);
	inserisci (lista1, 30);
	
	//inserisco alcuno valori nella seconda lista
	inserisci (lista2, 10);
	inserisci (lista2, 20);
	inserisci (lista2, 30);
	
	//testo la funzione coincidente
	if (coincidente(lista1, lista2)){
		cout << "Le due liste sono coincidenti" << endl;
	}
	else{
		cout << "Le due liste non sono coincidenti" << endl;
	}
	return 0;
}
