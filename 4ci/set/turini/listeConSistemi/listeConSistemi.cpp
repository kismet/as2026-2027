#include <iostream>
#include "listeConSistemi.h"

using namespace std;

element_t* creaInsieme(int valori[], int numValori){
	element_t* head = nullptr;
	int contatore = 0;
	
	while(contatore < numValori){
		element_t* aux = new element_t;
		aux->info = valori[contatore];
		contatore++;
		head = inserisciOrdinato(head, aux);
	}
	
	return head;
}

void stampa(element_t* head){
	element_t* scorri = head;
	int conta = 1;
	
	while(scorri != nullptr){
		cout<<"elemento N: "<<conta<<" valore: "<< scorri -> info <<endl;
		scorri = scorri->next;
		conta++;
	}
}

element_t* inserisciOrdinato(element_t* head, element_t* aux){
	element_t* scorri = head;
	if(head != nullptr){
		while(scorri -> next -> info > aux -> info){
			scorri = scorri -> next;
		}
		if(scorri->info != aux->info){
			aux -> next = scorri -> next;
			scorri -> next = aux;
		}
	}
	else{
		head = aux;
	}
	return head;
}

element_t* rimuovi(element_t* head, element_t* aux, int numero){
	element_t* salvaElemento = nullptr;
	element_t* scorri = head;
	
	if(aux != nullptr){
		bool keepGoing = true;
		while(scorri != nullptr and keepGoing){
			if(aux -> info == scorri -> next -> info){
				salvaElemento = scorri -> next;
				scorri -> next = salvaElemento -> next;
				salvaElemento -> next = nullptr;
				keepGoing = false;
			}
			scorri = scorri -> next;
		}
		delete salvaElemento;
	}
	if(numero != 0){
		numero--;
		while(scorri != nullptr and numero != 0){
			numero--;
			scorri = scorri -> next;
		}
		salvaElemento = scorri -> next -> next;
		scorri -> next = salvaElemento -> next;
		salvaElemento -> next = nullptr;
	}
	
	return head;
}

element_t* intersezione(element_t* head, element_t* head2){
	element_t* insieme = nullptr;
	element_t* keepHead2 = head2;
	while(head != 0){
		while(head2 != 0){
			if(head -> info == head2 -> info){
				element_t* copiaNodo = copia(head2);
				insieme = inserisciOrdinato(insieme, copiaNodo);
			}
			head2 = head2 -> next;
		}
		head2 = keepHead2;
		head = head -> next;
	}
	return insieme;
}

element_t* copia(element_t* head, element_t* aux){
	if(aux == nullptr){
		aux = new element_t;
	}
	aux -> info = head -> info;
	aux -> next = nullptr;
	return aux;
}

element_t* unione(element_t* head, element_t* head2){
	element_t* keepHead2 = head2;
	element_t* insieme = nullptr;
	element_t* scorriInsieme = insieme;
	bool isPresent = false;
	while(head2 != nullptr){
		scorriInsieme = new element_t;
		copia(head2, scorriInsieme);
		head2 = head2 -> next;
		scorriInsieme = scorriInsieme -> next;
	}
	head2 = keepHead2;
	while(head != 0){
		while(head2 != 0){
			if(head -> info == head2 -> info){
				isPresent = true;
			}
			head2 = head2 -> next;
		}
		
		if(!isPresent){
			element_t* nodo = copia(head);
			insieme = inserisciOrdinato(insieme, nodo);
		}
		
		isPresent = false;
		head2 = keepHead2;
		head = head -> next;
	}
	return insieme;
}

element_t* sottrazione(element_t* head, element_t* head2){
	element_t* keepHead = head;
	element_t* keepHead2 = head2;
	element_t* insieme = nullptr;
	element_t* scorriInsieme = insieme;
	while(head2 != nullptr){
		scorriInsieme = new element_t;
		copia(head, scorriInsieme);
		head = head -> next;
		scorriInsieme = scorriInsieme -> next;
	}
	head = keepHead;
	while(head != 0){
		while(head2 != 0){
			
			if(head -> info == head2 -> info){
				element_t* nodo = copia(head);
				insieme = rimuovi(insieme, nodo);
			}
			
			head2 = head2 -> next;
		}
		head2 = keepHead2;
		head = head -> next;
	}
	return insieme;
}

int cardinalita(element_t* head){
	int contatore = 0;
	while(head != nullptr){
		contatore++;
		head = head -> next;
	}
	return contatore;
}

bool uguaglianza(element_t* head, element_t* head2){
	element_t* keepHead2 = head2;
	bool isPresent = false, final = true;
	while(head != 0){
		while(head2 != 0){
			if(head -> info == head2 -> info){
				isPresent = true;
			}
			head2 = head2 -> next;
		}
		
		if(!isPresent){
			final = false;
		}
		
		isPresent = false;
		head2 = keepHead2;
		head = head -> next;
	}
	return final;
}

bool contenuto(element_t* head, element_t* head2){
	element_t* keepHead = head;
	bool isPresent = false, final = true;
	while(head2 != 0){
		while(head != 0){
			if(head -> info == head2 -> info){
				isPresent = true;
			}
			head = head -> next;
		}
		
		if(!isPresent){
			final = false;
		}
		
		isPresent = false;
		head = keepHead;
		head2 = head2 -> next;
	}
	return final;
}
