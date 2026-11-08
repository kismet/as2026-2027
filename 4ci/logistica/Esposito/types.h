#ifndef TYPES_H
#define TYPES_H
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Pacco{
	int identificativo;
	float peso;
	string destinazione;
}Pacco_t;

typedef struct Nodo{
	Pacco_t pacco;
	struct Nodo* next;
}Nodo_t;
#endif
