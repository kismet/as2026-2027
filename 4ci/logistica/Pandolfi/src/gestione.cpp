#include <iostream>
#include <string>
#include "../inc/gestione.h"

using namespace std;

Pacco_t* creaPacco(int id, float peso, string destinazione) {
    Pacco_t* nuovoPacco=new Pacco_t;
    nuovoPacco->pacco.id=id;
    nuovoPacco->pacco.peso=peso;
    nuovoPacco->pacco.destinazione=destinazione;

    return nuovoPacco;
}

void inserimentoPacchi(Pacco_t* province[], int id, float peso, string destinazione) {
    int indice=-1;
    for (int i=0;i<5;i++) {
        if (province[i]==destinazione) {
            indice=i;
            i==5;
        }
    }

    if (indice==-1) {
        cout<<"Errore";
        return;
    }

    Pacco_t* nuovoPacco=creaPacco(id,peso, destinazione);

    if (province[indice]==nullptr) {
        province[indice]=nuovoPacco;
    }
    else {
        Pacco_t* curr=province[indice];
        while (curr!=nullptr) {
         curr=curr->next;
        }
        curr->next=nuovoPacco;
    }
}

void stampaProvincia(Pacco_t* province[], string destinazione) {
    int indice=-1;
    for (int i=0;i<5;i++) {
        if (province[i]==destinazione) {
            indice=i;
            i==5;
        }
    }

    if (indice==-1) {
        cout<<"Errore";
        return;
    }

    Pacco_t* curr=province[indice];
    if (curr==nullptr) {
        cout<<"Errore";
    }
    else {
        while (curr!=nullptr) {
            cout<<"ID: "<<curr->pacco.id<<". Peso: "<<curr->pacco.peso<<"kg.";
            curr=curr->next;
        }
    }
}

void stampaPacchi(Pacco_t* province[]) {
    for (int i=0;i<5;i++) {
        cout<<"Province: "<<province[i]<<endl;

        Pacco_t* curr=province[i];
        if (curr==nullptr) {
            cout<<"Errore";
        }
        else {
            while (curr!=nullptr) {
                cout<<"ID: "<<curr->pacco.id<<". Peso: "<<curr->pacco.peso<<"kg.";
                curr=curr->next;
            }
        }
    }
}