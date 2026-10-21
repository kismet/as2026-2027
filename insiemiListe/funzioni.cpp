#include "funzioni.h"
#include <iostream>
using namespace std;

Insieme_t* creaInsieme(int valore){
	
	Insieme_t* nodo = new Insieme_t;
	nodo -> info = valore;
	nodo -> next = nullptr;
	return nodo;
	
}

void stampaInsieme(Insieme_t *head){

	while(head != nullptr){
		
		cout << head -> info << endl;
		head = head -> next;
		
	}	

}

void inserisci(Insieme_t** pHead, int valore){
	
	Insieme_t* nodo = creaInsieme(valore);
	
	Insieme_t* tmp = *pHead;
	
	if(tmp == nullptr){
		
		*pHead = nodo;
		
	}
	else{
		
		while((tmp -> next != nullptr) && (tmp -> info != nodo -> info)){
			

			tmp = tmp -> next;				
		}
		if(tmp -> info != nodo -> info){
			
			nodo -> next = *pHead;
			*pHead = nodo;
		}
		
	}

	
}

void rimuovi(Insieme_t** pHead, int valore){
	
	Insieme_t* tmp = *pHead;
	
	if(tmp != nullptr){
		
		while((tmp -> next != nullptr) && (tmp -> next -> info != valore)){
			
			tmp = tmp -> next;

			
			if(tmp -> next -> info != valore){
				
				Insieme_t* daRimuovere = tmp -> next;
				tmp -> next = daRimuovere -> next;
				daRimuovere -> next = nullptr;
				
				delete daRimuovere;
			}
		}
	}
}

Insieme_t* differenza(Insieme_t* head, Insieme_t* testa){
	
	Insieme_t* combo = nullptr;
	
	if(head == nullptr || testa == nullptr){
		
		if(head == nullptr){
			
			combo = testa;
		}
		else combo = head;
		
	}
	while(testa -> next != nullptr){
		
		while(head -> next != nullptr){
			
			if(testa -> info == head-> info){
				
				int informazione = head -> info;
				inserisci(&combo, informazione);
			}
			head = head -> next;
		}
		testa = testa -> next;
	}
	return combo;
	
}
Insieme_t* unione(Insieme_t* head, Insieme_t* testa){
	
	Insieme_t* tmp = head;
	while(head ->next != nullptr ){
		
		tmp = tmp -> next;
		
	}
	tmp -> next = testa;
	
	return head;
	
}
Insieme_t* intersezione(Insieme_t* head, Insieme_t* testa){
	
	Insieme_t* tmp = unione(head, testa);
	Insieme_t* ritorno = tmp;
	
	Insieme_t* togli = differenza(head, testa);
	
	while(tmp -> next == nullptr){
		
		while(togli -> next == nullptr){
			
			togli = togli-> next;
		}
		tmp = tmp-> next;
	}
	return ritorno;
	
	
}
int cardinalita(Insieme_t* head){
	int i = 0;
	if(head == nullptr){
		
		return 0;
	}
	do{
		i++;
		head = head -> next;
		
	}while(head -> next == nullptr);
	return i;
}

bool coincidente(Insieme_t* head, Insieme_t* testa){
	
	while(head -> next != nullptr){
		
		while(testa -> next != nullptr){
			if(testa -> info != head -> info) return false;
			testa = testa -> next;
		}
		head = head -> next;
	}
	return true;
}
bool contenuto(Insieme_t* head, Insieme_t* testa){
	
	int lista1 = cardinalita(head);
	int lista2 = cardinalita(testa);
	
	if(lista1 >= lista2){
		
		while(head -> next != nullptr){
			
			while(testa -> next != nullptr){
				if(testa -> info != head -> info) return false;
				testa = testa -> next;
			}
			head = head -> next;
		}
		return true;
	}
	return false;
}
