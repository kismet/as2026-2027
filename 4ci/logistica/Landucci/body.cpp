//
// Created by landucci.gianmarco on 05/11/2026.
//

#include "firme.h"
#include <iostream>

// Inizializza tutte le liste delle province ponendo testa e coda a nullptr
void inizializza(Provincia elenco[], int n) {
    for (int i = 0; i < n; i++) {
        elenco[i].testa = nullptr;
        elenco[i].coda = nullptr;
    }
}

// Cerca una provincia per nome e restituisce il suo indice, o -1 se non esiste
int trovaProvincia(Provincia elenco[], int n, string nomeProvincia) {
    for (int i = 0; i < n; i++) {
        if (elenco[i].nome == nomeProvincia) {
            return i;
        }
    }
    return -1;
}

// Aggiunge un nuovo pacco in coda alla lista della provincia di destinazione
bool spedisciPacco(Provincia elenco[], int nprovincie, Pacco p) {
    int id = trovaProvincia(elenco, nprovincie, p.destinazione);

    if (id == -1) {
        cout << "Provincia di destinazione non valida: " << p.destinazione << endl;
        return false;
    }

    // Creazione e allocazione dinamica del nuovo nodo
    Nodo* nuovo = new Nodo();
    nuovo->dato = p;
    nuovo->next = nullptr;

    // Inserimento in coda: gestisce il caso di lista vuota o già popolata
    if (elenco[id].testa == nullptr) {
        elenco[id].testa = nuovo;
        elenco[id].coda = nuovo;
    } else {
        elenco[id].coda->next = nuovo;
        elenco[id].coda = nuovo;
    }

    return true;
}

// Rimuove un pacco cercandolo tramite il suo ID in tutte le province
bool rimuoviPacco(Provincia elenco[], int nprovincie, int id) {
    for (int i = 0; i < nprovincie; i++) {
        Nodo* curr = elenco[i].testa;
        Nodo* prec = nullptr;

        while (curr != nullptr) {
            if (curr->dato.id == id) {
                // Gestione della testa se rimuoviamo il primo elemento
                if (prec == nullptr) {
                    elenco[i].testa = curr->next;
                } else {
                    prec->next = curr->next;
                }

                // Aggiornamento della coda se rimuoviamo l'ultimo elemento
                if (curr == elenco[i].coda) {
                    elenco[i].coda = prec;
                }

                delete curr;
                cout << "Pacco ID " << id << " rimosso con successo." << endl;
                return true;
            }
            prec = curr;
            curr = curr->next;
        }
    }
    cout << "Pacco ID " << id << " non trovato." << endl;
    return false;
}

// Stampa tutti i pacchi associati a una specifica provincia
void printPacchi(Provincia elenco[], int nprovincie, string provincia) {
    int id = trovaProvincia(elenco, nprovincie, provincia);

    if (id == -1) {
        cout << "[Errore] Provincia non trovata." << endl;
        return;
    }

    cout << "=== Pacchi per la destinazione '" << elenco[id].nome << "'" << endl;

    Nodo* curr = elenco[id].testa;
    if (curr == nullptr) {
        cout << "Nessun pacco presente." << endl;
        return;
    }

    // Scorre e stampa ogni nodo della lista
    while (curr != nullptr) {
        cout << "  - ID: " << curr->dato.id
             << " | Peso: " << curr->dato.peso << " kg" << endl;
        curr = curr->next;
    }
}

// Stampa l'elenco completo dei pacchi di tutte le province
void printAll(Provincia elenco[], int nprovincie) {
    cout << "========================================" << endl;
    cout << "       ELENCO COMPLETO PACCHI           " << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < nprovincie; i++) {
        printPacchi(elenco, nprovincie, elenco[i].nome);
    }

    cout << "========================================" << endl;
}