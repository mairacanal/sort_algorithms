#include <time.h>
#include <math.h>
#include "list.h"

#define REP 10

int main(void) {
    
    list l;
    clock_t time_start;
    clock_t times_add;
    
    for (int ord = 2; pow(10, ord) <= TAM; ord++) {

        times_add = 0;

        for (int i = 0; i < REP; i++) {

            create_list(&l);
            
            for (long j = 0; j < pow(10, ord); j++) {
                insert_list(&l, rand() % TAM);
            }

            //print_list(&l);

            time_start = clock();
            //quick_sort(&l);
            //bubble_sort(&l);
            //optimized_bubble_sort(&l);   
            times_add += clock() - time_start;

            //print_list(&l);

            destroy_list(&l);
        
        }

        printf("Tamanho: %ld Tempo total: %.10f\n", (long) pow(10, ord), (times_add / (float) REP)/CLOCKS_PER_SEC);

    }
    return 0;

}
