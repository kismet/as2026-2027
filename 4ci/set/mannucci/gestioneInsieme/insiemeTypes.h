
#ifndef INSIEMETYPES_H
#define INSIEMETYPES_H

// Il mio insieme sarà di numeri interi
typedef struct Insieme {
    int info;

    struct Insieme *next;
} Insieme_t;

#endif