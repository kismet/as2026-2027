#include <iostream>
#include "library.h"

using namespace std;

int main() {
    Insieme_t* ins1 = nullptr;
    Insieme_t* ins2 = nullptr;

    inserisciInsieme(ins1, 1);
    inserisciInsieme(ins1, 2);
    inserisciInsieme(ins1, 3);

    cout << "Insieme 1: ";
    stampaInsieme(ins1);

    inserisciInsieme(ins2, 4);
    inserisciInsieme(ins2, 5);
    inserisciInsieme(ins2, 6);
    inserisciInsieme(ins2, 7);
    cout << "Insieme 2: ";
    stampaInsieme(ins2);

    cout << "Cardinalita Insieme 1: " << cardinalitaInsieme(ins1) << endl;
    cout << "Cardinalita Insieme 2: " << cardinalitaInsieme(ins2) << endl;

    Insieme_t* u = unioneInsiemi(ins1, ins2);
    cout << "Unione (1 U 2): ";
    stampaInsieme(u);

    Insieme_t* inter = intersezioneInsiemi(ins1, ins2);
    cout << "Intersezione (1 n 2): ";
    stampaInsieme(inter);

    Insieme_t* diff = differenzaInsiemi(ins1, ins2);
    cout << "Differenza (1 \\ 2): ";
    stampaInsieme(diff);


    cout << "Sono uguali? ";
    if (uguaglianzaInsiemi(ins1, ins2)) cout<<"Si"<<endl;
    else cout<<"No"<<endl;
    return 0;
}