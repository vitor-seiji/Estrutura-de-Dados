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

Bool listaVazia(Lista);//Feito
Lista esvaziarLista(Lista);//Feito
Lista criarLista();//Feito
void mostrarLista(Lista);//Feito
int obterTamanho(Lista);//Feito
Celula* buscarItem(Lista, int);//Feito
Lista inserirInicio(Lista, int);//Feito
Lista inserirFim(Lista, int);//Feito
Lista removerPrimeiro(Lista);//Feito
Lista removerUltimo(Lista);//Feito

int main(){

    system("cls");

    Lista A;

    A = criarLista();

    A = inserirInicio(A, 10);
    A = inserirInicio(A, 20);
    A = inserirInicio(A, 30);
    A = inserirInicio(A, 40);
    
    A = inserirFim(A, 10);
    A = inserirFim(A, 20);
    A = inserirFim(A, 30);
    A = inserirFim(A, 40);

    printf("Tamanho: %d\n", obterTamanho(A));


    mostrarLista(A);

    Celula *p;

    p = buscarItem(A, 20);

    printf("p: %d", p->elemento);

    return 0;
    
}


Lista criarLista(){
    Lista A;
    A.tamanho = 0;
    A.inicio = NULL;
    A.fim = NULL;

    return A;
}

void mostrarLista(Lista A){
    if(A.tamanho > 0){
        Celula *p;
        p = A.inicio;
        do{
            printf("%d ", p->elemento);
            p = p->next;
        }while(p != A.inicio);
        printf("\n");
    }
}

Bool listaVazia(Lista A){
    return A.tamanho == 0;
}

int obterTamanho(Lista A){
    return A.tamanho;
}

Lista esvaziarLista(Lista A) {
    if (A.tamanho > 0) {
        Celula *atual = A.inicio;
        Celula *proximo;
        int limite = A.tamanho;

        for (int i = 0; i < limite; i++) {
            proximo = atual->next;
            free(atual);
            atual = proximo;
        }
    }
    
    A.inicio = NULL;
    A.fim = NULL;
    A.tamanho = 0;
    
    return A;
}

Celula* buscarItem(Lista A, int n) {
    Celula *p = NULL;
    
    if (A.tamanho > 0) {
        Celula *atual = A.inicio;
        
        do {
            if (atual->elemento == n) {
                p = atual;
            }
            atual = atual->next;
            
        } while (atual != A.inicio && p == NULL);
    }
    
    return p;
}

Lista inserirInicio(Lista A, int n){
    Celula *novo;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->elemento = n;

    if(A.tamanho == 0){
        novo->next = novo;
        novo->ant = novo;
        A.inicio = novo;
        A.fim = novo;
    }
    else{
        novo->next = A.inicio;
        novo->ant = A.inicio->ant;
        A.inicio->ant = novo;
        A.fim->next = novo;
        A.inicio = novo;
    }
    A.tamanho++;

    return A;
}

Lista inserirFim(Lista A, int n){
    Celula *novo;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->elemento = n;

    if(A.tamanho == 0){
        novo->next = novo;
        novo->ant = novo;
        A.inicio = novo;
        A.fim = novo;
    }
    else{
        novo->next = A.fim->next;
        novo->ant = A.fim;
        A.fim->next = novo;
        A.fim = novo;
        A.inicio->ant = A.fim;
    }
    A.tamanho++;

    return A;
}

Lista removerPrimeiro(Lista A){
    if(A.tamanho > 0){
        Celula *p, *aux;
        p = A.inicio;
        if(p == A.fim){
            A.fim = NULL;
            A.inicio = NULL;
            aux = p;
        }
        else{
            aux = A.inicio;
            p = p->next;
            A.fim->next = p;
            p->ant = A.fim;
            A.inicio = p;
        }
        free(aux);
        A.tamanho--;
    }
    return A;
}

Lista removerUltimo(Lista A){
    if(A.tamanho > 0){
        Celula *p, *aux;
        p = A.fim;
        if(p == A.inicio){
            A.fim = NULL;
            A.inicio = NULL;
            aux = p;
        }
        else{
            aux = A.fim;
            p = p->ant;
            p->next = A.inicio;
            A.inicio->ant = p;
            A.fim = p;
        }
        free(aux);
        A.tamanho--;
    }
    return A;
}