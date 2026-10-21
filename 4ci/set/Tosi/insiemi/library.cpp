#include "library.h"
#include <iostream>

using namespace std;

// Funzione di supporto
bool appartieneInsieme(Insieme_t* insieme, int valore) {
    Insieme_t* aux = insieme;
    while (aux != nullptr) {
        if (aux->info == valore) {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

void stampaInsieme(Insieme_t* insieme) {
    Insieme_t* aux = insieme;
    while (aux != nullptr) {
        cout << aux->info;
        if (aux->next != nullptr) {
            cout << ", ";
        }
        aux = aux->next;

    }cout << endl;
}

bool inserisciInsieme(Insieme_t*& insieme, int valore) {
    if (appartieneInsieme(insieme, valore)) {
        return false; // No doppi
    }
    Insieme_t* nuovo = new Insieme_t;
    nuovo->info = valore;
    nuovo->next = insieme;
    insieme = nuovo;
    return true;
}

bool rimuoviElementoInsieme(Insieme_t*& testa, int valore) {
    if (testa == nullptr) {
        return false;
    }

    if (testa->info == valore) {
        Insieme_t* temp = testa;
        testa = testa->next;
        delete temp;
        return true;
    }

    Insieme_t* aux = testa;
    while (aux->next != nullptr) {
        if (aux->next->info == valore) {
            Insieme_t* temp = aux->next;
            aux->next = aux->next->next;
            delete temp;
            return true;
        }
        aux = aux->next;
    }

    return false;
}

void aggiungiInFondo(Insieme_t*& testa, Insieme_t*& fine, int valore) {
    Insieme_t* nuovo = new Insieme_t{valore, nullptr};
    if (testa == nullptr) {
        testa = nuovo;
        fine = nuovo;
    } else {
        fine->next = nuovo;
        fine = nuovo;
    }
}

Insieme_t* intersezioneInsiemi(Insieme_t* insieme1, Insieme_t* insieme2) {
    Insieme_t* risultato = nullptr;
    Insieme_t* aux = insieme1;
    while (aux != nullptr) {
        if (appartieneInsieme(insieme2, aux->info)) {
            Insieme_t* nuovo = new Insieme_t{aux->info, risultato};
            risultato = nuovo;
        }
        aux = aux->next;
    }
    return risultato;
}

Insieme_t* unioneInsiemi(Insieme_t* insieme1, Insieme_t* insieme2) {
    Insieme_t* risultato = nullptr;
    
    // Copia tutti gli elementi del primo insieme
    Insieme_t* aux = insieme1;
    while (aux != nullptr) {
        Insieme_t* nuovo = new Insieme_t{aux->info, risultato};
        risultato = nuovo;
        aux = aux->next;
    }
    
    // Aggiunge gli elementi del secondo insieme se non sono già presenti
    aux = insieme2;
    while (aux != nullptr) {
        if (!appartieneInsieme(risultato, aux->info)) {
            Insieme_t* nuovo = new Insieme_t{aux->info, risultato};
            risultato = nuovo;
        }
        aux = aux->next;
    }
    
    return risultato;
}

Insieme_t* differenzaInsiemi(Insieme_t* insieme1, Insieme_t* insieme2) {
    Insieme_t* risultato = nullptr;
    Insieme_t* aux = insieme1;
    while (aux != nullptr) {
        if (!appartieneInsieme(insieme2, aux->info)) {
            Insieme_t* nuovo = new Insieme_t{aux->info, risultato};
            risultato = nuovo;
        }
        aux = aux->next;
    }
    return risultato;
}

int cardinalitaInsieme(Insieme_t* insieme) {
    int risultato = 0;
    Insieme_t* aux = insieme;
    while (aux != nullptr) {
        risultato++;
        aux = aux->next; // Corretto l'incremento mancante
    }
    return risultato;
}

bool contenimentoInsiemi(Insieme_t* insieme1, Insieme_t* insieme2) {
    // Verifica se insieme1 è contenuto in insieme2 (ogni elemento di 1 appartiene a 2)
    Insieme_t* aux = insieme1;
    while (aux != nullptr) {
        if (!appartieneInsieme(insieme2, aux->info)) {
            return false;
        }
        aux = aux->next;
    }
    return true;
}

bool uguaglianzaInsiemi(Insieme_t* insieme1, Insieme_t* insieme2) {
    if (cardinalitaInsieme(insieme1) != cardinalitaInsieme(insieme2)) {
        return false;
    }
    return contenimentoInsiemi(insieme1, insieme2);
}