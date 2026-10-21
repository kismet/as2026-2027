#include "funzioni.h"

bool coincidente(insiemi* head, insiemi* head2){
	while(head -> next != nullptr){
		while(head2 -> next != nullptr){
			if(head2 -> valore != head -> valore) return false;
			head2 = head2 -> next;
		}
		head = head -> next;
	}
	return true;
}
	
insiemi creaInsieme(int valore){
		insiemi* nodo = new insiemi;
		nodo -> valore = valore;
		nodo -> next = nullptr;
		return *nodo;
}
	
void inserisci(insiemi** pHead, int valore){
		insiemi nodo = creaInsieme(valore);
		insiemi* tmp = *pHead;
		if(tmp == nullptr){
			**pHead = nodo;	
		}
		else{
			while((tmp -> next != nullptr) && (tmp -> valore != nodo.valore)){	
				tmp = tmp -> next;				
			}
			if(tmp -> valore != nodo.valore){
				nodo.next = *pHead;
				**pHead = nodo;
			}	
		}	
}

