#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{
    int elemento;
    Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
} Lista;