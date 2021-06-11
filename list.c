/*
 * @file list.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include "list.h"

// PRIVATE FUNCTION *************************************************************

/*
 * 
 * 
 */

long partition(list *l, long begin, long end) {
    
    long pivot = l->elements[end];
    long i = begin - 1;
    elem aux;

    for(long j = begin; j < end; j++) {
        
        if (l->elements[j] < pivot) {

            i++;

            aux = l->elements[i];
            l->elements[i] = l->elements[j];
            l->elements[j] = aux;

        }

    }

    aux = l->elements[i + 1];
    l->elements[i + 1] = l->elements[end];
    l->elements[end] = aux;

    return i + 1;

}

/*
 * 
 * 
 */

long random_partition(list *l, long begin, long end) {

    long k; 
    elem aux;

    k = begin + rand() % (end - begin + 1);

    aux = l->elements[end];
    l->elements[end] = l->elements[k];
    l->elements[k] = aux;
    
    return partition(l, begin, end);

}

/*
 * 
 * 
 */

void recursive_quick_sort(list *l, long begin, long end) {
    long pivot;

    if (begin < end) {
        pivot = random_partition(l, begin, end);
        recursive_quick_sort(l, begin, pivot - 1);
        recursive_quick_sort(l, pivot + 1, end);
    }
}

// END PRIVATE FUNCTIONS ********************************************************

/*
 * 
 * 
 */

void create_list(list* l) {
    l->size = 0;
    l->elements = malloc(sizeof(elem) *  TAM);
    return;
}

/*
 * 
 * 
 */

void destroy_list(list* l) {
    free(l->elements);
    l->size = 0;
    return;
}

/*
 * 
 * 
 */

int insert_list(list* l, elem e) {
    
    if (l->size == TAM) {
        return 1; 
    }
    l->elements[l->size] = e;
    l->size++;

    return 0;

}

/*
 * 
 * 
 */

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

/*
 * 
 * 
 */

void quick_sort(list *l) {
    recursive_quick_sort(l, 0, l->size - 1);
}

/*
 * 
 * 
 */

void bubble_sort(list *l){
    elem aux;

    for (long i = 0; i < l->size - 1; i++) {
        for(long j = 0; j < l->size - i - 1; j++){
            if (l->elements[j] > l->elements[j+1]){
                aux = l->elements[j];
                l->elements[j] = l->elements[j+1];
                l->elements[j+1] = aux;
            }
        }
    }

    return;
}

/*
 * 
 * 
 */

void optimized_bubble_sort(list *l){

    int swapped = 1;
    elem aux;

    for (long i = 0; i < l->size - 1; i++) {
        for(long j = 0; j < l->size - i - 1; j++) {
            if (l->elements[j] > l->elements[j+1]) {

                swapped = 0;

                aux = l->elements[j];
                l->elements[j] = l->elements[j+1];
                l->elements[j+1] = aux;

            }
        }
        if (swapped) break;
        swapped = 1;
    }

    return;

}
