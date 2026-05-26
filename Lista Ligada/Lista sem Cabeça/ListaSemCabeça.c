#include <stdio.h>
#include <stdlib.h>
#define fantasma 0

typedef struct Celula {
    int elemento;
    struct Celula *next;
} Celula;

typedef Celula* Lista; 

// Protótipos corrigidos
void newLista(Lista*);
void mostrarLista(Lista*);
int obterTamanho(Lista *);
void inserirInicio(Lista*, int);
void inserirFim(Lista *, int);
void removerPrimeiro(Lista*);
void removerUltimo(Lista *);

int main(){
    Lista A;

    newLista(&A); 

    int i;
    for(i = 1; i <= 5; i++){
        inserirFim(&A, i); 
    }
    
    mostrarLista(&A); 

    removerPrimeiro(&A);
    removerUltimo(&A);

    mostrarLista(&A); 

    printf("Tamanho: %d", obterTamanho(&A));

    return 0;
}

void newLista(Lista *L){
    *L = NULL; 
}

void mostrarLista(Lista *L){
    Celula *p;
    p = *L;
    while(p != NULL){
        printf("%d ", p->elemento);
        p = p->next;
    }
    printf("\n");
}

int obterTamanho(Lista *L){
    int cont = 0;
    if(L != NULL){
        Celula *p;
        p = *L;
        while(p != NULL){
            cont++;
            p = p->next;
        }
    }
    return cont;
}
void inserirInicio(Lista *L, int n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;  
    novo->next = *L; 
    *L = novo;       
}

void inserirFim(Lista *L, int n){
    Celula *novo, *p;
    p = *L;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;  
    novo->next = NULL;

    if(p == NULL){
        *L = novo;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = novo;
    }
}

void removerPrimeiro(Lista *L){
    if(L != NULL){
        Celula *aux, *p;
        p = *L;
        p = p->next;
        aux = *L;
        *L = p;
        free(aux);
    }
}

void removerUltimo(Lista *L){
    if(L != NULL){
        Celula *p, *ant;
        p = *L;
        if(p->next == NULL){
            *L = NULL;
        }
        else{
            while(p->next != NULL){
                ant = p;
                p = p->next;
            }
            ant->next = NULL;  
        }
        free(p);
    }
}