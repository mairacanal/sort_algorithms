/*
 * @file list.h
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10000000

typedef int elem;
typedef struct {
    elem *elements;
    long size;
} list;

void create_list(list* l);
void destroy_list(list* l);
int insert_list(list* l, elem e);
void print_list(list* l);
void bubble_sort(list* l);
void quick_sort(list* l);
void radix_sort(list* l);
void heapsort(list* l);
void optimized_bubble_sort(list *l);
