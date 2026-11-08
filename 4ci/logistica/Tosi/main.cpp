#include <iostream>
using namespace std;
const int N_PROVINCE=3;



struct Pacco {
    int id;
    float peso;
    string destinazione;
};
typedef struct Coda {
    Pacco info;
    Coda* next;
}Coda_t;

struct Furgone {
    int nPacchi;
    Pacco pacchi[500];
    float pesoCorrente;
    string destinazione;
};

static Coda_t* elenco[N_PROVINCE];

int ritornaIndice(string destinazione) {

    if(destinazione == "Pisa") return 0;
    if(destinazione == "Lucca") return 1;
    if(destinazione == "Firenze") return 2;
    return -1;
}

bool spedisciPacco(Pacco p) {
    int indice = ritornaIndice(p.destinazione);
    if (indice == -1) {
        cout << "Errore: Destinazione non valida!" << endl;
        return false;
    }
    Coda_t* nuovoPacco = new Coda_t;
    nuovoPacco->info = p;
    nuovoPacco->next = nullptr;

    if (elenco[indice] == nullptr) {
        elenco[indice] = nuovoPacco;
    } else {
        Coda_t* temp = elenco[indice];

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuovoPacco;
    }
    return true;
}

void printPacchi(int indice) {
    Coda_t* temp = elenco[indice];

    while (temp != nullptr) {
        cout << temp->info.destinazione << ": " << temp->info.id << " " << temp->info.peso <<"Kg"<< endl;
        temp = temp->next;
    };

};

void printAll() {
    for (int i = 0; i < N_PROVINCE; i++) {
        printPacchi(i);
        cout<<endl;
    }
}

bool checkID(int id) {
    int indice=0;
    Coda_t* temp;

    while (indice<N_PROVINCE) {
        temp=elenco[indice];

        while (temp != nullptr) {
            if (temp->info.id == id) {
                return false;
            }
            temp = temp->next;
        }
        indice++;
    }
    return true;
}

Pacco creaPacco(string destinazione, int id, float peso) {
    Pacco p;
    if (checkID(id)) {
        p.id = id;
        p.destinazione = destinazione;
        p.peso = peso;
    }
    return p;
}

bool cambiaDestinazione(int id, string nuovaprovincia) {
    int indice=0;
    Coda_t* temp;

    while (indice<N_PROVINCE) {
        temp=elenco[indice];

        while (temp != nullptr) {
            if (temp->info.id == id) {
                temp->info.destinazione = nuovaprovincia;
                return true;
            }
            temp = temp->next;

        }
        indice++;
    }
    return false;
}

bool rimuoviPacco(int id) {
    int indice = 0;
    Coda_t* temp;
    Coda_t* prev;

    while (indice < N_PROVINCE) {
        temp = elenco[indice];
        prev = nullptr;

        while (temp != nullptr) {
            if (temp->info.id == id) {

                if (prev == nullptr) {
                    elenco[indice] = temp->next;
                }
                else {
                    prev->next = temp->next;
                }

                delete temp;
                return true;
            }

            prev = temp;
            temp = temp->next;
        }
        indice++;
    }

    return false;
}



int main(){

    Pacco p=creaPacco("Lucca",110,10);
    Pacco p1=creaPacco("Firenze",101,11);
    Pacco p2=creaPacco("Firenze",111,110);
    spedisciPacco(p);
    spedisciPacco(p1);
    printAll();
    cambiaDestinazione(110, "Pisa");
    printAll();


    return 0;
}

