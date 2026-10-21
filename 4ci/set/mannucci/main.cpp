
#include "gestioneInsieme/gestioneInsieme.h"
#include <iostream>
#include <string>

using namespace std;

// Aggiunge n valori a un insieme
void riempi( Insieme_t **pInsieme, int valori[], int n ) {
    
    for ( int i = 0; i < n; i++ ) {
        aggiungiElemento( pInsieme, creaElemento( valori[i] ) );
    }
}

// Confronta il risultato ottenuto con quello atteso
void verifica( string descrizione, bool ottenuto, bool atteso ) {
    
    if ( ottenuto == atteso ) {
        cout << "Ok     " << descrizione << endl;
    }
    else {
        cout << "Errore " << descrizione << endl;
    }
}

void mostra( string nome, Insieme_t *insieme ) {

    cout << nome << " (" << cardinalitaInsieme( insieme ) << " elementi):" << endl;

    if ( !stampaInsieme( insieme ) ) {
        cout << " (vuoto)" << endl;
    }
}

int main() 
{
    int valoriA[] = { 1, 2, 3 };
    int valoriB[] = { 2, 3, 4 };
    int valoriC[] = { 2, 3 };

    Insieme_t *A = creaInsieme();
    Insieme_t *B = creaInsieme();
    Insieme_t *C = creaInsieme();
    Insieme_t *vuoto = creaInsieme();

    riempi( &A, valoriA, 3 );
    riempi( &B, valoriB, 3 );
    riempi( &C, valoriC, 2 );

    cout << "===== CASI NORMALI =====" << endl;
    mostra( "A", A );
    verifica( "2 e' in A", cercaElemento( A, 2 ), true );
    verifica( "9 non e' in A", cercaElemento( A, 9 ), false );
    verifica( "aggiungo 5 ad A", aggiungiElemento( &A, creaElemento( 5 ) ), true );
    verifica( "cancello 5 da A", cancellaElementoInInsieme( &A, 5 ), true );

    Insieme_t *U = unioneInsiemi( A, B );
    Insieme_t *I = intersezioneInsiemi( A, B );
    Insieme_t *D = differenzaInsiemi( A, B );

    mostra( "A U B", U );
    mostra( "A n B", I );
    mostra( "A - B", D );
    verifica( "|A U B| = 4", cardinalitaInsieme( U ) == 4, true );
    verifica( "A n B coincide con {2,3}", coincidente( I, C ), true );
    verifica( "A - B = {1}", cardinalitaInsieme( D ) == 1 && cercaElemento( D, 1 ), true );
    verifica( "C = {2,3} contenuto in A", contenuto( C, A ), true );
    verifica( "A non contenuto in C", contenuto( A, C ), false );
    verifica( "A non coincide con B", coincidente( A, B ), false );

    cout << endl << "===== CASI LIMITE =====" << endl;
    mostra( "vuoto", vuoto );
    verifica( "vuoto e' vuoto", checkInsiemeVuoto( vuoto ), true );
    verifica( "aggiungo 2 ad A (duplicato)", aggiungiElemento( &A, creaElemento( 2 ) ), false );
    verifica( "A ha ancora 3 elementi", cardinalitaInsieme( A ) == 3, true );
    Insieme_t *U2 = unioneInsiemi( A, vuoto ), *I2 = intersezioneInsiemi( A, vuoto );
    Insieme_t *D2 = differenzaInsiemi( vuoto, A ), *D3 = differenzaInsiemi( A, A );
    verifica( "A U vuoto coincide con A", coincidente( U2, A ), true );
    verifica( "A n vuoto e' vuoto", checkInsiemeVuoto( I2 ), true );
    verifica( "vuoto - A e' vuoto", checkInsiemeVuoto( D2 ), true );
    verifica( "A - A e' vuoto", checkInsiemeVuoto( D3 ), true );
    verifica( "vuoto contenuto in A", contenuto( vuoto, A ), true );
    verifica( "A non contenuto nel vuoto", contenuto( A, vuoto ), false );
    verifica( "vuoto coincide con vuoto", coincidente( vuoto, vuoto ), true );
    verifica( "cancello 9 (assente)", cancellaElementoInInsieme( &A, 9 ), false );
    verifica( "cancello 2 (mezzo)", cancellaElementoInInsieme( &A, 2 ), true );
    verifica( "cancello 1 (coda)", cancellaElementoInInsieme( &A, 1 ), true );
    verifica( "cancello 3 (testa e unico elemento)", cancellaElementoInInsieme( &A, 3 ), true );
    verifica( "A ora e' vuoto", checkInsiemeVuoto( A ), true );
    verifica( "cancello in testa su vuoto", cancellaElementoInTesta( &A ), false );

    // Libero la memoria
    Insieme_t *tutti[] = { A, B, C, U, I, D, U2, I2, D2, D3 };
    for ( int i = 0; i < 10; i++ ) {
        cancellaInsieme( &tutti[i] );
    }
    
    return 0;
}