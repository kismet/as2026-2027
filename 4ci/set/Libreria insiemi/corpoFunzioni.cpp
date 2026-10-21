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
        cout << endl;
    }
}

void inserisciElemento(Nodo_t** pHead, int valore){
    if (*pHead == nullptr) {
        Nodo_t* aux = new Nodo_t;
        aux->info = valore;
        *pHead = aux;
        return;
    }

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

Nodo_t* intersezioneInsiemi(Nodo_t* pA, Nodo_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return nullptr;
    }

    Nodo_t* intersect = nullptr;
    Nodo_t* cursor = pA;
    Nodo_t* check = nullptr;
    bool presente;

    while(cursor != nullptr) {
        presente = false;
        check = pB;

        while(check->info != cursor->info and !presente){
            if(check->next != nullptr){
                check = check->next;
            }
            else{
                presente = true;
            }
        }

        if(presente) {
            Nodo_t* aux = new Nodo_t;
            aux->info = cursor->info;
            aux->next = intersect;
            intersect = aux;
        }

        cursor = cursor->next;
    }

    return intersect;
}

Nodo_t* differenzaInsiemi(Nodo_t* pA, Nodo_t* pB){
    if (pA == nullptr) {
        return nullptr;
    }
    else if (pB == nullptr) {
        return pA;
    }

    Nodo_t* difference = pA;
    Nodo_t* cursor = pB;
    Nodo_t* check = nullptr;
    bool presente;

    while(cursor != nullptr) {
        presente = true;
        check = pA;

        while(check->info != cursor->info and presente){
            if(check->next != nullptr){
                check = check->next;
            }
            else{
                presente = false;
            }
        }

        if(presente) {
            rimuoviElemento(&difference, cursor->info);
        }

        cursor = cursor->next;
    }

    return difference;
}

int numeroElementi(Nodo_t* head){
    int nElem = 0;

    if(head != nullptr){
        Nodo_t* curr = head;

        while(curr != nullptr){
            nElem++;
            curr = curr->next;
        }
    }

    return nElem;
}

bool insiemeContenuto(Nodo_t* pA, Nodo_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return false;
    }

    Nodo_t* cursor = pB;
    Nodo_t* check = pA;

    while(cursor != nullptr) {
        while (check != nullptr) {
            if(check->info != cursor->info) {
                check = check->next;
            }
            else {
                if (cursor->next != nullptr) {
                    cursor = cursor->next;
                    check = pA;
                }
                else {
                    return true;
                }
            }
        }

        return false;
    }
}

bool insiemiCoincidente(Nodo_t* pA, Nodo_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return false;
    }
    else if (numeroElementi(pA) != numeroElementi(pB)) {
        return false;
    }

    Nodo_t* cursor = pB;
    Nodo_t* check = pA;

    while(cursor != nullptr) {
        while (check != nullptr) {
            if(check->info != cursor->info) {
                check = check->next;
            }
            else {
                if (cursor->next != nullptr) {
                    cursor = cursor->next;
                    check = pA;
                }
                else {
                    return true;
                }
            }
        }

        return false;
    }
}