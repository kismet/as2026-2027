# Smistamento Hub Logistico Pacchi
## Scenario di realtà
Un centro di smistamento logistico riceve colli continui su un nastro trasportatore. Ogni pacco possiede un codice numerico univoco (ID), un peso in kg e una provincia di destinazione (quindi l'elenco delle province è noto a priori).
### Strutture dati
1. Ogni Pacco è rappraresentato (id, peso, destinazione). 
1. Un array contenente le liste di destinazioni delle provincie.
## Obiettivi

### Fase 1 (Base - Voto 6): 
Per velocizzare lo smistamento ogni pacco viene inserimento in sequenziale in una coda legata alla provincia di destinazione. 
Il sistema deve essere in grado di:
 - inserire pacchi;
 - stampare tutti i pacchi da spedire per una specifica destinazionene
 - stampare tutti i pacchi da spedire.
#### Suggerimento API
1. bool spedisciPacco(Pacco* elenco[], Pacco p);
1. void printPacchi(Pacco* elenco[], string provincia);
1. void printAll(Pacco* elenco[], int nprovincie); 

### Fase 2 (Intermedio - Voto 7-8): 
Il sistema deve poter cambiare la destinazione di un pacco oppure rimuovere pacchi dalla consegna perchè danneggiati o pericolosi. 
#### Suggerimento API
1. bool cambiaDestinazione(Pacco* elenco[], int id,string, vecchiaprovincia, string nuovaprovincia);
1. bool rimuoviPacco(Pacco* elenco[], int id);

### Fase 3 (Eccellenza - Voto 9-10): 
Sapendo che ogni furgone può andare in una sola destinazione e che ci sono dei limiti di spazio e peso: massimo 1500kg di merce  o massimo 200 pacchi, creare e stampare gli elenchi di spedizione della merce, escludendo i pacchi che sono stati rimossi dalla consegna.
#### Suggerimento API
1. void stampaBolleCarico(Pacco* elenco[], int nprovincie); 
