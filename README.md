Ragionamento prima della scrittura del codice

stampaInsieme → void
Deve visualizzare gli elementi senza restituire valori. Riceverà un Nodo_t* e scorrerà la lista fino a nullptr, stampando i valori tra parentesi graffe.

inserisciElemento → void
Deve modificare direttamente l’insieme. Prima dell’inserimento occorrerà controllare che il valore non sia già presente. L’inserimento sarà in testa, perché non serve mantenere un ordine. Il parametro sarà Nodo_t**, per poter aggiornare la testa originale.

rimuoviElemento → void
Deve cercare ed eliminare un elemento, mantenendo un puntatore al nodo corrente e uno al precedente. Se il nodo è il primo, occorrerà aggiornare la testa; altrimenti il precedente dovrà essere collegato al successivo. Infine, delete libererà il nodo. Servirà Nodo_t** perché la testa potrebbe cambiare. Un valore assente non dovrà produrre modifiche.

intersezione → Nodo_t*
Deve restituire la testa di un nuovo insieme. Scorrendo A, saranno inseriti nel risultato soltanto gli elementi presenti anche in B.

unione → Nodo_t*
Deve produrre un nuovo insieme con tutti gli elementi di A e B. Gli inserimenti passeranno da inserisciElemento, così i valori comuni non saranno duplicati.

differenza → Nodo_t*
Per ottenere A − B, saranno inseriti nel risultato soltanto gli elementi di A assenti da B. L’ordine degli operandi è importante: A − B può essere diverso da B − A.

Queste tre operazioni dovranno creare nuovi nodi, lasciando invariati gli insiemi iniziali. Il risultato partirà da nullptr e resterà tale se vuoto.

cardinalita → int
Deve restituire il numero degli elementi. Un contatore, inizialmente a zero, sarà incrementato per ogni nodo. L’assenza di duplicati garantirà che il numero dei nodi coincida con la cardinalità.

uguaglianza → bool
Deve restituire vero o falso. Prima saranno confrontate le cardinalità; se uguali, sarà verificato che ogni elemento di A appartenga a B. Il confronto non dovrà dipendere dalla posizione dei nodi: {1, 2} e {2, 1} sono uguali.

contenuto → bool
Interpretando A ⊂ B come inclusione stretta, A dovrà avere cardinalità minore di B e ogni suo elemento dovrà appartenere a B. L’uguaglianza sarà quindi esclusa.

Funzioni di supporto
appartiene restituirà un bool indicando se un valore è presente: servirà a riutilizzare la ricerca nelle altre funzioni.