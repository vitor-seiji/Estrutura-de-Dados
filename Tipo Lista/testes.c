#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int chamada = 1;

void quickSort(int*[], int, int);
int separarLista(int*[],int, int);
void trocar(int*[], int, int);

int main(){

    system("cls");

    int lista[10] = {5, 10, 3, 2, 8, 9, 4, 7, 6, 1};

    quickSort(&lista, 0, 9);

    int i = 0;
    for(i; i < 10; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}


void quickSort(int *A[], int inicio, int fim){
    if(inicio < fim){
        printf("quick %d\n", chamada);
        chamada++;
        int j;
        int i = inicio;
        printf("lista inicial: ");
        for(i; i <= fim; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
        j = separarLista(A, inicio, fim);
        printf("j = %d\n", A[j]);
        printf("lista separada: ");
        i = inicio;
        for(i; i <= fim; i++){
            printf("%d ", A[i]);
        }
        printf("\n\n");
        quickSort(A, inicio, j-1);
        quickSort(A, j+1, fim);
    }
}

int separarLista(int *A[], int inicio, int fim){
    int i = inicio;
    int j = fim + 1;
    while(i < j){
        do{
            i =  i + 1;
        }while(A[i] < A[inicio] && i < fim);
        do{
            j = j - 1;
        }while(A[j] > A[inicio]);
        if(i < j){
            trocar(A, i ,j);
        }
    }
    trocar(A, inicio, j);
    return j;
}

void trocar(int *A[], int i, int j){
    int aux = A[i];
    A[i] = A[j];
    A[j] = aux;
}




