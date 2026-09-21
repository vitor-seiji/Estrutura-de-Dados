#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct{
    int tamanho;
    char vetor[MAX];
}Lista;


void quickSort(Lista *, int, int);
int separarLista(Lista *,int, int);
void trocar(Lista *, int, int);

void quickSort(Lista *A, int inicio, int fim){
    if(inicio > fim){
        int j;
        j = separarLista(A, inicio, fim);
        quickSort(A, inicio, j-1);
        quickSort(A, j+1, fim);
    }
}

int separarLista(Lista *A, int inicio, int fim){
    int i = inicio;
    int j = fim + 1;
    while(inicio < fim){
        do{
            i =  i + 1;
        }while(A->vetor[i] < A->vetor[inicio] && i < fim);
        do{
            j = j - 1;
        }while(A->vetor[j] > A->vetor[inicio]);
        if(i < j){
            trocar(A, i ,j);
        }
    }
    trocar(A, inicio, j);
}

void trocar(Lista *A, int i, int j){
    int aux = A->vetor[i];
    A->vetor[i] = A->vetor[j];
    A->vetor[j] = aux;
}