#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"

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

void mostrarLista(Lista);//Feito
void criarLista(Lista *);//Feito
void inserirInicio(Lista *, int);//Feito
void inserirFim(Lista *, int);//Feito
Bool listaVazia(Lista);//Feito
void esvaziarLista(Lista *);//Feito
void mostrarLista(Lista);//Feito
int obterTamanho(Lista);//Feito
Celula* buscarItem(Lista, int);//Feito
void removerPrimeiro(Lista *);//Feito
void removerUltimo(Lista *);//Feito

int main(){
    Lista A;
    criarLista(&A);
    int i;
    for(i = 1; i <= 10; i++){
        inserirFim(&A, i);
    }
    mostrarLista(A);

    removerPrimeiro(&A);

    mostrarLista(A);

    Celula *p;
    p = buscarItem(A, 5);
    printf("%d | %d", p->elemento, p->next->elemento);

    return 0;
}

void mostrarLista(Lista L){
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
        printf("lista vazia\n");
    }
}

void criarLista(Lista *L){
    L->tamanho = 0;
    L->inicio = NULL;
    L->fim = NULL;
}

void esvaziarLista(Lista *A){
    if(A->tamanho > 0){
        Celula *inicio, *fim, *aux;
        inicio = A->inicio;
        fim = A->fim;
        if(inicio == fim){
            free(inicio);
            A->inicio = NULL;
            A->fim = NULL;
        }
        else{
            while(inicio != fim){
                aux = inicio;
                inicio = inicio->next;
                free(aux);
                aux = fim;
                fim = fim->ant;
                free(aux);
            }
            aux = inicio;
            free(aux);
            A->inicio = NULL;
            A->fim = NULL;
        }
        A->tamanho = 0;
    }
}

Celula* buscarItem(Lista A, int n){
    Celula *p;
    p = NULL;
    if(A.tamanho > 0){

        Celula *inicio, *fim;
        Bool achou = FALSE;
        inicio = A.inicio;
        fim = A.fim;

        do{
            if(inicio->elemento == n){
                p = inicio;
                achou = TRUE;
            }
            if(fim->elemento == n){
                p = fim;
                achou = TRUE;
            }
            inicio = inicio->next;
            fim = fim->ant;
        }while(inicio != fim && achou == FALSE);

        if(inicio->elemento == n){
            p = inicio;
        }
    }
    return p;
}


Bool listaVazia(Lista A){
    Bool vazia = FALSE;
    if(A.tamanho == 0){
        vazia = TRUE;
    }
    return vazia;
}

int obterTamanho(Lista A){
    return A.tamanho;
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
    L->tamanho++;
}

void removerPrimeiro(Lista *A){
    if(A->tamanho > 0){
        Celula *p, *aux;
        if(A->inicio == A->fim){//Só possui um elemento
            p = A->inicio;
            free(p);
            A->inicio = NULL;
            A->fim = NULL;
            A->tamanho = 0;
        }
        else{
            p = A->inicio;
            aux = A->inicio;
            p = p->next;
            p->ant = NULL;
            A->inicio = p;
            free(aux);
            A->tamanho--;
        }
    }
}

void removerUltimo(Lista *A){
    if(A->tamanho > 0){
        Celula *p, *aux;
        if(A->inicio == A->fim){
            p = A->inicio;
            free(p);
            A->inicio = NULL;
            A->fim = NULL;
            A->tamanho = 0;
        }
        else{
            p = A->fim;
            aux = p->ant;
            aux->next = NULL;
            A->fim = aux;
            free(p);
            A->tamanho--;
        }
    }
}
