/*
 * @file main.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include <time.h>
#include <math.h>
#include "list.h"

#define REP 10

void random_numbers(list *l, long size, long max);
void growing_numbers(list *l, long size, long max);
void declining_numbers(list *l, long size, long max);
void analysis(void (*sort)(list *), void (*numbers)(list *, long, long));
void testing_routine(void (*sort)(list *), long size, long max);

int main(void) {
    
    printf("ORDEM ALEATÓRIA\n");
    analysis(bubble_sort, random_numbers);

    printf("ORDEM CRESCENTE\n");
    analysis(bubble_sort, growing_numbers);

    printf("ORDEM DECRESCENTE\n");
    analysis(bubble_sort, declining_numbers);

    return 0;

}

void random_numbers(list *l, long size, long max) {

    for(int i = 0; i < size; i++)
        insert_list(l, rand() % max);

}

void growing_numbers(list *l, long size, long max) {

    random_numbers(l, size, max);
    quick_sort(l);

}

void declining_numbers(list *l, long size, long max) {

    list aux;

    random_numbers(l, size, max);
    quick_sort(l);

    create_list(&aux);

    for(int i = 0; i < size; i++)
        insert_list(&aux, l->elements[size - i]);

    for(int i = 0; i < size; i++)
        l->elements[i] = aux.elements[i];

    destroy_list(&aux);

}

void analysis(void (*sort)(list *), void (*numbers)(list *, long, long)) {

    list l;
    clock_t time_start;
    clock_t time_sum;
    
    for (int ord = 3; pow(10, ord) <= TAM; ord++) {

        time_sum = 0;

        for (int i = 0; i < REP; i++) {

            create_list(&l);
            numbers(&l, pow(10, ord), TAM);

            time_start = clock();
            sort(&l);
            time_sum += clock() - time_start;

            destroy_list(&l);
        
        }

        printf("Tamanho: %ld Tempo total: %.10f\n", (long) pow(10, ord), (time_sum / (float) REP)/CLOCKS_PER_SEC);

    }

}

void testing_routine(void (*sort)(list *), long size, long max) {

    list l;

    create_list(&l);

    random_numbers(&l, size, max);
    print_list(&l);
    sort(&l);
    print_list(&l);

    destroy_list(&l);

}
