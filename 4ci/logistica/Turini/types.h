#ifndef TYPES_H
#define TYPES_H

#include <iostream>

using namespace std;

typedef struct pacco {
	int id;
	int peso;
	string provincia;
	struct pacco* next;
}pacco_t;

typedef struct provincie{
	string provincia;
	pacco_t* next;
}provincie_t;

const int NUMEROMASSIMOPACCHI = 200;
const int PESOMASSIMOFURGONE = 1500;

#endif
