#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{
    int elemento;
    struct Celula *next;
    struct Celula *ant;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
    Celula *fim;
} Lista;

void mostrar(Lista);
void criarLista(Lista *);
void inserirInicio(Lista *, int);
void inserirFim(Lista *, int);

int main(){
    Lista A;
    criarLista(&A);
    int i;
    for(i = 1; i <= 10; i++){
        inserirFim(&A, i);
    }
    mostrar(A);

    return 0;
}

void mostrar(Lista L){
    if(L.inicio != NULL){
        Celula *p;
        p = L.inicio;
        do{
            printf("%d ", p->elemento);
            p = p->next;
        }while(p != NULL);
        printf("\n\n");
    }
    else{
        printf("lista vazia\n\n");
    }
}
void criarLista(Lista *L){
    L->tamanho = 0;
    L->inicio = NULL;
    L->fim = NULL;
}

void inserirInicio(Lista *L, int y){
    Celula *novo, *p;
    p = L->inicio;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = y;
    novo->next = NULL;
    novo->ant = NULL;
    if(L->inicio == NULL){
        L->inicio = novo;
        L->fim = novo;
    }
    else{
        novo->next = L->inicio;   // O próximo do novo nó aponta para o antigo início
        L->inicio->ant = novo;   // O antigo início aponta de volta para o novo nó
        L->inicio = novo;
    }
    L->tamanho++;
}

void inserirFim(Lista *L, int y){
    Celula *novo, *p;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = y;
    novo->next = NULL;
    novo->ant = NULL;
    if(L->inicio == NULL){
        L->inicio = novo;
        L->fim = novo;
    }
    else{
        novo->ant = L->fim;
        L->fim->next = novo;
        L->fim = novo;

    }
}

