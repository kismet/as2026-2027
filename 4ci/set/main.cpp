//
// Created by Admin on 21/10/2026.
//
#include <iostream>
#include "firme.h"
using namespace std;

int main() {
    Insieme_t* A = nullptr;
    Insieme_t* B = nullptr;

    //INSERIMENTO, VALORE GIA' PRESENTE, STAMPA
    inserisciElemento(&A,1);
    inserisciElemento(&A,2);
    inserisciElemento(&A,3);
    inserisciElemento(&A,3);
    stampaInsieme(A);

    inserisciElemento(&B,1);
    inserisciElemento(&B,2);
    inserisciElemento(&B,3);
    stampaInsieme(B);

    //INSIEME CONTENUTO E COINCIDENTE ENTRAMBI TRUE
    cout << insiemeContenuto(A,B) << endl;
    cout << insiemiCoincidenti(A,B) << endl;

    //RIMUOVI ELEMENTO, INSIEME CONTENUTO TRUE E COINCIDENTE FALSE
    rimuoviElemento(&B, 1);
    stampaInsieme(B);
    cout << insiemeContenuto(A,B) << endl;
    cout << insiemiCoincidenti(A,B) << endl;

    //NUMERO DI ELEMENTI
    cout << "A: " << numeroElementi(A) << endl;
    cout << "B: " << numeroElementi(B) << endl;

    //DIFFERENZA
    Insieme_t* diff = differenzaInsiemi(A,B);
    stampaInsieme(diff);

    //UNIONE
    Insieme_t* C = nullptr;
    inserisciElemento(&C,4);
    inserisciElemento(&C,5);
    inserisciElemento(&C,6);
    stampaInsieme(C);

    Insieme_t* unito = unioneInsiemi(A,C);
    stampaInsieme(unito);

    //INTERSEZIONE
    Insieme_t* intersect = intersezioneInsiemi(unito,B);
    stampaInsieme(intersect);

    return 0;
}