#ifndef _READ_CSV
#define _READ_CSV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define MAX_LINE_LENGTH 3000  //MODIFICAR BASEADO NA QUANTIDADE DE DADOS

typedef struct {
    int priority;
    int time;
    char name[100];
} Recipe;


int open_csv(FILE **pont, const char *file_name) {
    *pont = fopen(file_name, "r");
    if (*pont == NULL) {
        perror("Error opening file");
        return FAILURE;
    }
    return SUCCESS;
}

int read_csv(FILE *pont, Recipe recipes[], int *count) {
    if (pont == NULL) {
        fprintf(stderr, "File pointer is NULL. Make sure the file is opened.\n");
        return FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    *count = 0;

    fgets(line, sizeof(line), pont); // pula a primeira linha

    while (fgets(line, sizeof(line), pont)) {

        line[strcspn(line, "\n")] = '\0'; // pula newlines

        char *token = strtok(line, ",");
        if (token == NULL) continue; // pula espaços vazios/com erro
        recipes[*count].priority = atoi(token); // atribui a prioridade

        token = strtok(NULL, ",");
        if (token == NULL) continue; // pula espaços vazios/com erro
        recipes[*count].time = atoi(token);// atribui o tempo

        token = strtok(NULL, ",");
        if (token == NULL) continue; // pula espaços vazios/com erro
        strcpy(recipes[*count].name, token); // atribui o nome

        (*count)++; // incrementa o contador de receitas
    }

    return SUCCESS;
}

void print_csv(Recipe recipes[], int *recipe_count) {
    printf("\nReceitas ordenadas por prioridade com BUBBLE-SORT:\n");
    for (int i = 0; i < *recipe_count; i++) {
        printf("%d: Prioridade = %d, Tempo = %d, Nome = %s\n",
               i + 1, recipes[i].priority, recipes[i].time, recipes[i].name);
    }
}

#endif