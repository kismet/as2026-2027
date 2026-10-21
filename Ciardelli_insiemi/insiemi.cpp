#include <iostream>
#include "insiemi.h"
using namespace std;

nodo_t* crea_nodo(int valore){
	
	nodo_t* nodo = new nodo_t;
	nodo->info = valore;
	nodo->next = nullptr;
	
	return nodo;
	
}


