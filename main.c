/*
 * @file main.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include <time.h>
#include <math.h>
#include "list.h"

#define REP 10

#define BUBBLE_SIZE 100000
#define OP_BUBBLE_SIZE 100000000
#define QUICK_SIZE 100000000
#define RADIX_SIZE 100000000
#define HEAP_SIZE 100000

void random_numbers(list *l, long size, long max);
void growing_numbers(list *l, long size, long max);
void declining_numbers(list *l, long size, long max);
void analysis(void (*sort)(list *), void (*numbers)(list *, long, long), long max);
void testing_routine(void (*sort)(list *), long size, long max);

int main(void) {
    
    printf("BUBBLE SORT\n");
    printf("ORDEM ALEATÓRIA\n");
    analysis(bubble_sort, random_numbers, BUBBLE_SIZE);

    printf("ORDEM CRESCENTE\n");
    analysis(bubble_sort, growing_numbers, BUBBLE_SIZE);

    printf("ORDEM DECRESCENTE\n");
    analysis(bubble_sort, declining_numbers, BUBBLE_SIZE);

    printf("BUBBLE SORT APRIMORADO\n");
    printf("ORDEM ALEATÓRIA\n");
    analysis(optimized_bubble_sort, random_numbers, OP_BUBBLE_SIZE);

    printf("ORDEM CRESCENTE\n");
    analysis(optimized_bubble_sort, growing_numbers, OP_BUBBLE_SIZE);

    printf("ORDEM DECRESCENTE\n");
    analysis(optimized_bubble_sort, declining_numbers, OP_BUBBLE_SIZE);

    printf("QUICK SORT\n");
    printf("ORDEM ALEATÓRIA\n");
    analysis(quick_sort, random_numbers, QUICK_SIZE);

    printf("ORDEM CRESCENTE\n");
    analysis(quick_sort, growing_numbers, QUICK_SIZE);

    printf("ORDEM DECRESCENTE\n");
    analysis(quick_sort, declining_numbers, QUICK_SIZE);

    printf("RADIX SORT\n");
    printf("ORDEM ALEATÓRIA\n");
    analysis(radix_sort, random_numbers, RADIX_SIZE);

    printf("ORDEM CRESCENTE\n");
    analysis(radix_sort, growing_numbers, RADIX_SIZE);

    printf("ORDEM DECRESCENTE\n");
    analysis(radix_sort, declining_numbers, RADIX_SIZE);

    printf("HEAP SORT\n");
    printf("ORDEM ALEATÓRIA\n");
    analysis(heapsort, random_numbers, HEAP_SIZE);

    printf("ORDEM CRESCENTE\n");
    analysis(heapsort, growing_numbers, HEAP_SIZE);

    printf("ORDEM DECRESCENTE\n");
    analysis(heapsort, declining_numbers, HEAP_SIZE);

    return 0;

}


/*
 * Insert random numbers on list 
 */

void random_numbers(list *l, long size, long max) {

    for(int i = 0; i < size; i++)
        insert_list(l, rand() % max);

}


/* Insert growing numbers on list 
 */

void growing_numbers(list *l, long size, long max) {

    random_numbers(l, size, max);
    quick_sort(l);

}

/* Insert declining numbers on list 
 */

void declining_numbers(list *l, long size, long max) {

    list aux;

    random_numbers(l, size, max);
    quick_sort(l);

    create_list(&aux, size);

    for(int i = 0; i < size; i++)
        insert_list(&aux, l->elements[size - i]);

    for(int i = 0; i < size; i++)
        l->elements[i] = aux.elements[i];

    destroy_list(&aux);
}

/* 
 *  Analyze the execution time by at least 10 times according to the algorithm and sorting 
 */

void analysis(void (*sort)(list *), void (*numbers)(list *, long, long), long max) {

    list l;
    clock_t time_start;
    clock_t time_sum;
    
    for (int ord = 3; pow(10, ord) <= max; ord++) {

        time_sum = 0;

        for (int i = 0; i < REP; i++) {

            create_list(&l, max);
            numbers(&l, pow(10, ord), max);

            time_start = clock();
            sort(&l);
            time_sum += clock() - time_start;

            destroy_list(&l);
        
        }

        printf("Tamanho: %ld Tempo total: %.10f\n", (long) pow(10, ord), (time_sum / (float) REP)/CLOCKS_PER_SEC);

    }

}

/* Algorithm to test the subfunctions to be compiled in the main
 */

void testing_routine(void (*sort)(list *), long size, long max) {

    list l;

    create_list(&l, max);

    random_numbers(&l, size, max);
    print_list(&l);
    sort(&l);
    print_list(&l);

    destroy_list(&l);

}
