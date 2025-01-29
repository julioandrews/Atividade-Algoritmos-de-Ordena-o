#include "read_csv.h"
#include "bubble_sort.h"
#include "quick_sort.h"
#include <time.h>

 //MODIFICAR BASEADO NA QUANTIDADE DE DADOS

int main() {

    FILE *pont = NULL;
    Recipe recipes[MAX_LINE_LENGTH];
    int recipe_count = 0;

    clock_t start, end; //para registro de tempo
    double cpu_time1, cpu_time2;


    /* BUBBLE SORT*/
    if (!open_csv(&pont, "../restaurante_pratos.csv")) { // abre e transfere os dados do arquivo
        return FAILURE;
    }
    if (!read_csv(pont, recipes, &recipe_count)) {
        return FAILURE;
    }
    fclose(pont); // fecha o arquivo, já transferimos os dados

    start = clock();
    bubbleSort(recipes, recipe_count, compareByPriority);
    end = clock();
    cpu_time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    // print_csv(recipes, &recipe_count); //printa as receitas

    /* QUICK SORT*/
    if (!open_csv(&pont, "../restaurante_pratos.csv")) { // abre e transfere os dados do arquivo
        return FAILURE;
    }
    if (!read_csv(pont, recipes, &recipe_count)) {
        return FAILURE;
    }
    fclose(pont); // fecha o arquivo, já transferimos os dados
    start = clock();
    quickSort(recipes, 0, recipe_count - 1, compareByPriority);;
    end = clock();
    cpu_time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

    // print_csv(recipes, &recipe_count); //printa as receitas

    printf("Tempo de execução BUBBLESORT: %f segundos\n", cpu_time1);
    printf("Tempo de execução QUICKSORT: %f segundos\n", cpu_time2);




    return EXIT_SUCCESS;
}