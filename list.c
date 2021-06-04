/*
 * @file list.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include "lista.h"

void create_list(list* l) {
    l->tam = 0;
    l->elements = malloc(sizeof(elem) *  TAM);
    return;
}

void destroy_list(list* l) {
    free(l->elements);
    l->tam = 0;
    return;
}

int insert_list(list* l, elem e) {
    
    if (l->tam == TAM) {
        return 1; 
    }
    l->elements[l->tam] = e;
    l->tam++;

    return 0;

}

void print_list(list* l) {

    if (l->tam == 0) printf("( )\n");
    else {

        printf("(");
        for (long i = 0; i < (l->tam - 1); i++) {
            printf("%d, ", l->elements[i]);
        }
        printf("%d)\n", l->elements[l->tam - 1]);
    
    }

    return;

}

