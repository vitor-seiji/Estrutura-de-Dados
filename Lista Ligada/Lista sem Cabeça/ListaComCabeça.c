#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"
#define fantasma 0

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
}Lista;

Lista criarListaVazia();
Bool verificarVazia(Lista);
void mostrarLista(Lista);
Lista inserir(Lista, int);

int main(){
    Lista c;
    c = criarListaVazia();
    int i;
    for(i = 1; i < 6; i++){
        c = inserir(c, i);
    }
    //c = inserir(c, 10);
    mostrarLista(c);

    return 0;
}

Lista criarListaVazia(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
}

Bool verificarVazia(Lista L){
    Bool vazia = FALSE;
    if(L.tamanho == 0){
        vazia = TRUE;
    }
    return vazia;
}

void mostrarLista(Lista C){
    if(C.tamanho == 0){
        printf("Lista Vazia\n");
    }
    else{
        Celula *p;
        p = C.inicio;
        do{
            printf("%d  ", p->elemento);
            p = p->next;
        }while(p != NULL);
        printf("\n");
    }
}

Lista inserir(Lista L, int n){
    Celula *novo;
    novo = malloc(sizeof(Celula));
    novo->elemento = n;
    novo->next = L.inicio;
    L.inicio = novo;
    L.tamanho++;
    return L;
}




