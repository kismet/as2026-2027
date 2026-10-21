//
// Created by Admin on 21/10/2026.
//
#include <iostream>
#include "firme.h"
using namespace std;

void stampaInsieme(Insieme_t* head){
    if(head != nullptr){
        Insieme_t* curr = head;

        while(curr != nullptr){
            cout << curr->info << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

void inserisciElemento(Insieme_t** pHead, int valore){
    if (*pHead == nullptr) {
        Insieme_t* aux = new Insieme_t;
        aux->info = valore;
        *pHead = aux;
        return;
    }

    Insieme_t* curr = *pHead;
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
        Insieme_t* aux = new Insieme_t;
        aux->info = valore;
        aux->next = *pHead;
        *pHead = aux;
    }
}

void rimuoviElemento(Insieme_t** pHead, int valore){
    if (*pHead != nullptr){
        Insieme_t* curr = *pHead;
        Insieme_t* pre = nullptr;
        bool presente = true;

        while(curr->info != valore and presente){
            if(curr->next != nullptr){
                pre = curr;
                curr = curr->next;
            }
            else{
                presente = false;
            }
        }

        if(presente){
            if (pre != nullptr) {
                pre->next = curr->next;
            }
            else {
                *pHead = curr->next;
            }

            curr->next = nullptr;
            delete curr;
        }
    }
}

Insieme_t* unioneInsiemi(Insieme_t* pA, Insieme_t* pB){
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

    Insieme_t* unite = duplicaInsieme(pA);
    Insieme_t* cursor = pB;
    Insieme_t* check = nullptr;
    bool aggiungere;

    while(cursor != nullptr) {
        aggiungere = false;
        check = unite;

        while(check->info != cursor->info and !aggiungere){
            if(check->next != nullptr){
                check = check->next;
            }
            else{
                aggiungere = true;
            }
        }

        if(aggiungere) {
            Insieme_t* aux = new Insieme_t;
            aux->info = cursor->info;
            aux->next = unite;
            unite = aux;
        }

        cursor = cursor->next;
    }

    return unite;
}

Insieme_t* intersezioneInsiemi(Insieme_t* pA, Insieme_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return nullptr;
    }

    Insieme_t* intersect = nullptr;
    Insieme_t* cursor = pA;
    Insieme_t* check = nullptr;
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
            Insieme_t* aux = new Insieme_t;
            aux->info = cursor->info;
            aux->next = intersect;
            intersect = aux;
        }

        cursor = cursor->next;
    }

    return intersect;
}

Insieme_t* differenzaInsiemi(Insieme_t* pA, Insieme_t* pB){
    if (pA == nullptr) {
        return nullptr;
    }
    else if (pB == nullptr) {
        return pA;
    }

    Insieme_t* difference = duplicaInsieme(pA);
    Insieme_t* cursor = pB;
    Insieme_t* check = nullptr;
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

int numeroElementi(Insieme_t* head){
    int nElem = 0;

    if(head != nullptr){
        Insieme_t* curr = head;

        while(curr != nullptr){
            nElem++;
            curr = curr->next;
        }
    }

    return nElem;
}

bool insiemeContenuto(Insieme_t* pA, Insieme_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return false;
    }

    Insieme_t* cursor = pB;
    Insieme_t* check = pA;

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

bool insiemiCoincidenti(Insieme_t* pA, Insieme_t* pB){
    if (pA == nullptr or pB == nullptr) {
        return false;
    }
    else if (numeroElementi(pA) != numeroElementi(pB)) {
        return false;
    }

    Insieme_t* cursor = pB;
    Insieme_t* check = pA;

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

//FUNZIONE STRETTAMENTE DI APPOGGIO
Insieme_t* duplicaInsieme(Insieme_t* head) {
    Insieme_t* cursor = head;
    Insieme_t* newList = nullptr;

    while(cursor != nullptr) {
        Insieme_t* aux = new Insieme_t;

        aux->info = cursor->info;
        aux->next = newList;
        newList = aux;

        cursor = cursor->next;
    }

    return newList;
}