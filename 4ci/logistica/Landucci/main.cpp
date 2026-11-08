//
// Created by landucci.gianmarco on 05/11/2026.
//

#include <iostream>
#include "firme.h"

int main() {

    Provincia elenco[NPROVINCE];

    // Inizializzazione delle province
    elenco[0].nome = "Pisa";
    elenco[1].nome = "Firenze";
    elenco[2].nome = "Livorno";
    elenco[3].nome = "Lucca";
    elenco[4].nome = "Siena";

    inizializza(elenco, NPROVINCE);

    //Inserimento pacchi
    spedisciPacco(elenco, NPROVINCE, {1, 20.5, "Pisa"});
    spedisciPacco(elenco, NPROVINCE, {2, 35.0, "Firenze"});
    spedisciPacco(elenco, NPROVINCE, {3, 50.0, "Pisa"});
    spedisciPacco(elenco, NPROVINCE, {4, 1600.0, "Livorno"}); // Pacco pesante (> 1500kg) per test fase 3
    spedisciPacco(elenco, NPROVINCE, {5, 15.0, "Siena"});

    printAll(elenco, NPROVINCE);

    rimuoviPacco(elenco, NPROVINCE, 1); // Rimuove Pisa ID 1

    printAll(elenco, NPROVINCE);
}