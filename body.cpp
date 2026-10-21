#include <iostream>
#include "firme.h"
using namespace std;

// Stampa tutti gli elementi dell'insieme tra parentesi graffe.
void stampaInsieme(Nodo_t* head) {
    cout << "{ ";

    // Scorre la lista fino alla fine.
    while (head != nullptr) {
        cout << head->info;
        if (head->next != nullptr) {
            cout << ", ";
        }
        head = head->next;
    }
    cout << " }";
}

// Cerca un valore nell'insieme e restituisce true se presente altrimenti false.
bool appartiene(Nodo_t* head, int valore) {
    while (head != nullptr) {

        // Se trova il valore interrompe subito la ricerca.
        if (head->info == valore) {
            return true;
        }
        head = head->next;
    }

    // La lista è terminata senza trovare il valore.
    return false;
}

// Inserisce un nuovo elemento in testa soltanto se non è già presente.
void inserisciElemento(Nodo_t** pHead, int valore) {

    // Se il valore è già presente non deve essere inserito.
    if (appartiene(*pHead, valore)) {
        return;
    }
    Nodo_t* nuovo = new Nodo_t;
    nuovo->info = valore;

    // Collega il nuovo nodo alla vecchia testa.
    nuovo->next = *pHead;

    // Il nuovo nodo diventa la testa dell'insieme.
    *pHead = nuovo;
}

// Cerca ed elimina l'elemento aggiornando i collegamenti e liberando il nodo.
void rimuoviElemento(Nodo_t** pHead, int valore) {
    Nodo_t* corrente = *pHead;
    Nodo_t* precedente = nullptr;

    // Cerca il valore, conservando il puntatore al nodo precedente.
    while (corrente != nullptr && corrente->info != valore) {
        precedente = corrente;
        corrente = corrente->next;
    }

    // Se il valore non esiste non modifica l'insieme.
    if (corrente == nullptr) {
        return;
    }

    // Se il nodo è il primo aggiorna la testa.
    else if (precedente == nullptr) {
        *pHead = corrente->next;
    }

    // Altrimenti collega il precedente al successivo saltando il nodo.
    else {
        precedente->next = corrente->next;
    }

    delete corrente;
}

// Crea un nuovo insieme con gli elementi presenti sia in A sia in B.
Nodo_t* intersezione(Nodo_t* pA, Nodo_t* pB) {
    Nodo_t* risultato = nullptr;

    // Esamina tutti gli elementi di A.
    while (pA != nullptr) {

        // Inserisce soltanto quelli presenti anche in B.
        if (appartiene(pB, pA->info)) {
            inserisciElemento(&risultato, pA->info);
        }
        pA = pA->next;
    }
    return risultato;
}

// Crea un nuovo insieme con tutti gli elementi di A e B, senza duplicati.
Nodo_t* unione(Nodo_t* pA, Nodo_t* pB) {
    Nodo_t* risultato = nullptr;

    // Inserisce tutti gli elementi di A.
    while (pA != nullptr) {
        inserisciElemento(&risultato, pA->info);
        pA = pA->next;
    }

    // Aggiunge gli elementi di B e inserisciElemento evita i duplicati.
    while (pB != nullptr) {
        inserisciElemento(&risultato, pB->info);
        pB = pB->next;
    }
    return risultato;
}

// Crea un nuovo insieme con gli elementi di A che non appartengono a B.
Nodo_t* differenza(Nodo_t* pA, Nodo_t* pB) {
    Nodo_t* risultato = nullptr;
    while (pA != nullptr) {

        // Inserisce l'elemento solo se non appartiene a B.
        if (!appartiene(pB, pA->info)) {
            inserisciElemento(&risultato, pA->info);
        }
        pA = pA->next;
    }
    return risultato;
}

// Conta i nodi della lista e restituisce il numero di elementi dell'insieme.
int cardinalita(Nodo_t* head) {
    int totale = 0;

    // Conta un elemento per ogni nodo trovato.
    while (head != nullptr) {
        totale++;
        head = head->next;
    }
    return totale;
}

// Verifica che i due insiemi contengano gli stessi elementi indipendentemente dall'ordine.
bool uguaglianza(Nodo_t* pA, Nodo_t* pB) {

    // Insiemi con cardinalità diverse non possono essere uguali.
    if (cardinalita(pA) != cardinalita(pB)) {
        return false;
    }
    while (pA != nullptr) {

        // Basta un elemento di A assente da B per escludere l'uguaglianza.
        if (!appartiene(pB, pA->info)) {
            return false;
        }
        pA = pA->next;
    }

    // Stessa cardinalità e tutti gli elementi di A presenti in B.
    return true;
}

// Verifica che ogni elemento di A appartenga a B e che A abbia meno elementi di B.
bool contenuto(Nodo_t* pA, Nodo_t* pB) {

    // L'inclusione richiede che A abbia meno elementi di B.
    if (cardinalita(pA) >= cardinalita(pB)) {
        return false;
    }
    while (pA != nullptr) {

        // Se un elemento di A manca in B, A non è contenuto in B.
        if (!appartiene(pB, pA->info)) {
            return false;
        }
        pA = pA->next;
    }
    return true;
}