//
// Created by Admin on 21/10/2026.
//
#include <iostream>
#include "firme.h"
using namespace std;

void stampaInsieme(Nodo_t* head){
    if(head != nullptr){
        Nodo_t* curr = head;

        while(curr != nullptr){
            cout << curr->info << " ";
            curr = curr->next;
        }
    }
}

void inserisciElemento(Nodo_t** pHead, int valore){
    Nodo_t* curr = *pHead;
    bool presente = false;

    while(curr->info != valore and !presente){
        if(curr->next != nullptr){
            curr = curr->next;
        }
        else{
            presente = true;
        }
    }

    if(!presente){
        Nodo_t* aux = new Nodo_t;
        aux->info = valore;
        aux->next = *pHead;
        *pHead = aux;
    }
}