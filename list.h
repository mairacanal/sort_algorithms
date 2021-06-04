/*
 * @file list.h
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 100000

typedef int elem;
typedef struct {
    elem *elements;
    long tam;
} list;

void create_list(list* l);
void destroy_list(list* l);
int insert_list(list* l, elem e);
void print_list(list* l);
