/*
 * @file list.c
 * @authors Guilherme Mafra (Nº USP: 11272015) and Maíra Canal (Nº USP: 11819403)
 */

#include "list.h"

// PRIVATE FUNCTION *************************************************************

/*
 *  Performs an exchange of two values in the vector between two indexes
 */

void swap(elem* vec, long idx1, long idx2) {

    elem aux;

    aux = vec[idx1];
    vec[idx1] = vec[idx2];
    vec[idx2] = aux;

}

/*
 * Partitions the vector through the pivot
 * @return pivot
 */

long partition(list *l, long begin, long end) {
    
    long pivot = l->elements[end];
    long i = begin - 1;

    for(long j = begin; j < end; j++) {
        if (l->elements[j] < pivot) {
            i++;
            swap(l->elements, i, j);
        }
    }

    swap(l->elements, i + 1, end);
    return i + 1;

}

/*   
 * Generates a random index between the values of the list vector 
 * and partitions the vector through this exchange.
 */

long random_partition(list *l, long begin, long end) {

    long k; 

    k = begin + rand() % (end - begin + 1);

    swap(l->elements, k, end);
    return partition(l, begin, end);

}

/*   
 * Divides the vector into two and applies the recursive quick sort to each
 */

void recursive_quick_sort(list *l, long begin, long end) {
    long pivot;

    if (begin < end) {
        pivot = random_partition(l, begin, end);
        recursive_quick_sort(l, begin, pivot - 1);
        recursive_quick_sort(l, pivot + 1, end);
    }
}

/* Finds the largest element of a vector */

long max_element(list* l) {

    long max = 0;

    for (long i = 0; i < l->size; i++) {
        if(l->elements[i] > max)
            max = l->elements[i];
    }

    return max;
}

/* Counting sort subfunction of Radix Sort */

void radix_counting_sort(list *l, long position) {

    int k = 10;
    long *count = (long *) calloc(k, sizeof(long));
    long *final = (long *) calloc(l->size, sizeof(long));
    long key;

    for(int i = 0; i < l->size; i++) {
        key = l->elements[i]/position;
        key = key % k;
        count[key]++;
    }

    for(int i = 1; i < k; i++) 
        count[i] += count[i - 1];

    for(int i = (l->size - 1); i >= 0; i--) {
        key = l->elements[i]/position;
        key = key % k;
        count[key]--;
        final[count[key]] = l->elements[i];
    }

    for(int i = 0; i < l->size; i++) 
        l->elements[i] = final[i];

    free(count);
    free(final);

}

/* Orders the Heap */

void Heapify(list* l, long size, elem e) {

    long bigger = e;
    long left = ( 2 * e ) + 1;
    long right  = ( 2 * e ) + 2;

    if (( left < size ) && ( l->elements[left] > l->elements[bigger] ))  bigger = left;
     
    if (( right < size ) && ( l->elements[right] > l->elements[bigger] ))  bigger = right;

    if (bigger != e) {
        swap(l->elements, bigger, e);
        Heapify (l, size, bigger);
    }

}

// END PRIVATE FUNCTIONS ********************************************************

/* Allocates space for list creation of a max size */

void create_list(list* l, long max) {
    l->size = 0;
    l->max_size = max;
    l->elements = malloc(sizeof(elem) *  max);
    return;
}

/* Free all allocated memory */

void destroy_list(list* l) {
    free(l->elements);
    l->size = 0;
    return;
}

/*  Insertion of the value and for the lease l->size */

int insert_list(list* l, elem e) {
    
    if (l->size == l->max_size) {
        return 1; 
    }
    l->elements[l->size] = e;
    l->size++;

    return 0;

}

/*  Printing vector going from 0 up to its size */

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



/* Bubble Sort function */

void bubble_sort(list *l) {

    for (long i = 0; i < l->size - 1; i++) 
        for(long j = 0; j < l->size - i - 1; j++)
            if (l->elements[j] > l->elements[j+1])
                swap(l->elements, j, j + 1);

    return;
}

/*   
 *   Bubble sort with the swapped condition that undos 
 *   the looping of "i" if an exchange not for held
 */

void optimized_bubble_sort(list *l) {

    int swapped = 1;

    for (long i = 0; i < l->size - 1; i++) {
        for(long j = 0; j < l->size - i - 1; j++) {
            if (l->elements[j] > l->elements[j+1]) {
                swapped = 0;
                swap(l->elements, j, j + 1);
            }
        }
        if (swapped) break;
        swapped = 1;
    }

    return;

}

/*   
 *   Quick sort function call with the index defined
 *   by the size of the main 
 */

void quick_sort(list *l) {
    recursive_quick_sort(l, 0, l->size - 1);
}

/* Radix Sort function */

void radix_sort(list* l) {

    long max = max_element(l);
    long position = 1;
    
    while (max/position > 0) {
        
        radix_counting_sort(l, position);
        position *= 10;

    }

}


/* Heapsort function */

void heapsort(list* l) {

    for (long i = ( l->size/2 - 1 ); i >= 0; i--)
        Heapify( l, l->size, i);

    for (long i = l->size-1; i >= 1; i--) {
        swap(l->elements, 0, i);
        Heapify(l, i, 0);
    }

}

/* Insertion Sort function */

void insertion_sort(list* l) {

    long j;
    elem key;

    for (long i = 1; i < l->size; i++) {
        key = l->elements[i];
        for (j = i - 1; j >= 0 && l->elements[j] > key; j--) 
            l->elements[j + 1] = l->elements[j];
        l->elements[j + 1] = key;
    }

}

/* Selection Sort function */

void selection_sort(list* l) {
    
    long key;

    for(long i = 0; i < l->size; i++) {
        key = i;
        for (long j = i + 1; j < l->size; j++) {
            if (l->elements[j] < l->elements[key])
                key = j;
        }
        swap(l->elements, i, key);
    }

}

/* Shell Sort function */

void shell_sort(list* l) {

    long i, j;
    long h = 1;
    elem key;

    while (h < l->size)
        h = 3 * h + 1;

    for (; h > 0; h = h/3) {
        for (i = h; i < l->size; i++) {
            key = l->elements[i];
            for (j = i - h; j >= 0 && l->elements[j] > key; j-=h) 
                l->elements[j + h] = l->elements[j];
            l->elements[j + h] = key;
        }
    }

}

void counting_sort(list *l) {

    long max = max_element(l);
    long *count = (long *) calloc(max + 1, sizeof(long));
    long *final = (long *) calloc(l->size, sizeof(long));
    long key;

    for(long i = 0; i < l->size; i++)
        count[l->elements[i]]++;

    for(long i = 1; i <= max; i++) 
        count[i] += count[i - 1];

    for(long i = (l->size - 1); i >= 0; i--) {
        key = l->elements[i];
        count[key]--;
        final[count[key]] = l->elements[i];
    }

    for(long i = 0; i < l->size; i++) 
        l->elements[i] = final[i];

    free(count);
    free(final);

}
