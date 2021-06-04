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

void bubble_sortpiu(list* A, elem n){

long i, j;
elem auxiliar;
    for (i=0;i<n-1;i++){
        for(j=0;j<n-i-2;i++){
            if (A->elements[j]> A->elements[j+1]){
                auxiliar = A->elements[i];
                A->elements[i] = A->elements[i+1];
                A->elements[i+1] = auxiliar;
            }
        j = j+1;
        }
    i = i+1;
    }
}

/*
 * 
 * 
 */

void optimized_bubble_sortpiu(list* A, elem n){

long i,j,ordenado;
elem auxiliar;
    while (ordenado == 1){
        for (i=0;i<n-1;i++){
            for(j=0;j<n-i-2;i++){
                if (A->elements[j]> A->elements[j+1]){
                    ordenado = 0;
                    auxiliar = A->elements[i];
                    A->elements[i] = A->elements[i+1];
                    A->elements[i+1] = auxiliar;
                }
            j = j+1;
            }
            if (ordenado == 1){
                break;
            }
        i = i+1;
        }
    }
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
    bubble_sortpiu(l, l->size-1);
}

/*
 * 
 * 
 */

void optimized_bubble_sort(list *l){
    optimized_bubble_sortpiu(l, l->size-1);
}