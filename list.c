/*
 * @file list.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include "list.h"

void create_list(list* l) {
    l->size = 0;
    l->elements = malloc(sizeof(elem) *  TAM);
    return;
}

void destroy_list(list* l) {
    free(l->elements);
    l->size = 0;
    return;
}

int insert_list(list* l, elem e) {
    
    if (l->size == TAM) {
        return 1; 
    }
    l->elements[l->size] = e;
    l->size++;

    return 0;

}

void print_list(list* l) {

    if (l->size == 0) printf("( )\n");
    else {

        printf("(");
        for (long i = 0; i < (l->size - 1); i++) {
            printf("%d, ", l->elements[i]);
        }
        printf("%d)\n", l->elements[l->size - 1]);
    
    }

    return;

}

