#include <iostream>
#include "firme.h"
using namespace std;

int main() {
    // Inizializza gli insiemi come vuoti.
    Nodo_t* A = nullptr;
    Nodo_t* B = nullptr;

    // Inserisce gli elementi nei due insiemi.
    inserisciElemento(&A, 1);
    inserisciElemento(&A, 2);
    inserisciElemento(&A, 3);
    inserisciElemento(&A, 2); // Duplicato: non viene inserito.
    inserisciElemento(&B, 2);
    inserisciElemento(&B, 3);
    inserisciElemento(&B, 4);

    cout << "A = "; stampaInsieme(A); cout << endl;
    cout << "B = "; stampaInsieme(B); cout << endl;

    // Crea tre nuovi insiemi per i risultati delle operazioni successive.
    Nodo_t* I = intersezione(A, B);
    Nodo_t* U = unione(A, B);
    Nodo_t* D = differenza(A, B);

    cout << "Intersezione A e B = "; stampaInsieme(I); cout << endl;
    cout << "Unione A e B = "; stampaInsieme(U); cout << endl;
    cout << "Differenza A - B = "; stampaInsieme(D); cout << endl;
    cout << "Cardinalita di A: " << cardinalita(A) << endl;
    cout << "Cardinalita di B: " << cardinalita(B) << endl;

    // Visualizza i risultati booleani come true e false.
    //Trovato per sfizio personale per non far apparire 1 e 0 ma true e false,
    //per evitare di usare il sistema con gli if, esteticamnete piu piacevole.
    //https://www.w3schools.com/cpp/cpp_booleans.asp
    cout << boolalpha;

    cout << "A = B: " << uguaglianza(A, B) << endl;
    cout << "A contenuto in B: " << contenuto(A, B) << endl;

    // Rimuove 1 da A e verifica nuovamente l'inclusione.
    rimuoviElemento(&A, 1);
    cout << "A dopo la rimozione di 1 = "; stampaInsieme(A); cout << endl;
    cout << "A contenuto in B: " << contenuto(A, B) << endl;

    return 0;
}