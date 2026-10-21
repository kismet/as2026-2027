#include <iostream>
#include "funzioni.h"
using namespace std;


int main(int argc, char** argv) {
	
	
	Insieme_t* testa = nullptr;
	Insieme_t* head = nullptr;
	
	inserisci(&head, 10);
	inserisci(&head, 7);
	inserisci(&head, 16);
	inserisci(&head, 10);
	inserisci(&head, 16);
	
	
	inserisci(&testa, 2);
	inserisci(&testa, 2);
	inserisci(&testa, 10);
	inserisci(&testa, 6);
	inserisci(&testa, 3);
	
//	rimuovi(&head, 10);
	
//	stampaInsieme(head);
	
//	stampaInsieme(testa);
	
	Insieme_t* difference = differenza(head, testa);
	stampaInsieme(difference);
	
	return 0;
}
