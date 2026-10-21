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