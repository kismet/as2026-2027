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

void rimuoviElemento(Nodo_t** pHead, int valore){
    if (*pHead != nullptr){
        Nodo_t* curr = *pHead;
        Nodo_t* pre = nullptr;
        bool presente = false;

        while(curr->info != valore and !presente){
            if(curr->next != nullptr){
                pre = curr;
                curr = curr->next;
            }
            else{
                presente = true;
            }
        }

        if(presente){
            pre->next = curr->next;
            curr->next = nullptr;
            delete curr;
        }
    }
}

Nodo_t* unioneInsiemi(Nodo_t* pA, Nodo_t* pB){
    if (pA == nullptr) {
        if (pB == nullptr) {
            return nullptr;
        }
        else {
            return pB;
        }
    }
    else if (pB == nullptr) {
        return pA;
    }

    Nodo_t* unite = pA;
    Nodo_t* cursor = pB;
    Nodo_t* check = nullptr;
    bool presente;

    while(cursor != nullptr) {
        presente = false;
        check = unite;

        while(check->info != cursor->info and !presente){
            if(check->next != nullptr){
                check = check->next;
            }
            else{
                presente = true;
            }
        }

        if(!presente) {
            Nodo_t* aux = new Nodo_t;
            aux->info = cursor->info;
            aux->next = unite;
            unite = aux;
        }

        cursor = cursor->next;
    }

    return unite;
}