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
void inserir(Lista*, int);
void remover(Lista *, int y);//Remove a primeira aparição de y
void removerOrdem(Lista *, int);//Remove o item de ordem k
void removerPrimeiro(Lista *);

int main(){
    Lista c;
    c = criarListaVazia();
    printf("verificar lista vazia:\n");
    if(verificarVazia(c)){
        printf("Lista vazia!\n\n");
    }

    int i;
    for(i = 1; i < 6; i++){
        inserir(&c, i);
    }
    //c = inserir(c, 10);
    printf("Lista inicial:\n");
    mostrarLista(c);
    printf("remover especifico: \n");
    remover(&c, 2);
    mostrarLista(c);
    printf("remover ordem: \n");
    removerOrdem(&c, 2);
    mostrarLista(c);
    printf("remover primeiro: \n");
    removerPrimeiro(&c);
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
        p = C.inicio; //Se a lista for vazia P = null
        do{
            printf("%d  ", p->elemento);
            p = p->next;
        }while(p != NULL);
        printf("\n\n");
    }
}

void inserir(Lista *L, int n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;
    novo->next = L->inicio;
    L->inicio = novo;
    L->tamanho++;
}

void remover(Lista *L, int y){
    if(!L->tamanho == 0){
        Celula *p = L->inicio;
        Celula *ant = L->inicio;

        while(p != NULL && p->elemento != y){
           ant = p; 
           p = p->next; 
        } 

        if(p != NULL){
            if(ant == p){
                L->inicio = p->next;
            }
            else{
                ant->next = p->next;  
            }
        }
    }
}

void removerOrdem(Lista *L, int k){
    if((k > 0 && k <= L->tamanho) && L->tamanho > 0){
        Celula *p, *ant;
        p = L->inicio;
        ant = L->inicio;
        int cont = 1;

        while(cont != k){
            p = p->next;
            if(cont != k - 1){
                ant = ant->next;
            }
            cont++;
        }

        if(cont == k){
            if(ant == p){
                L->inicio = p->next;
            }
            else{
                ant->next = p->next;
            }
        }
        
    }
}

void removerPrimeiro(Lista *L){
    if(L->tamanho > 0){
       L->inicio = L->inicio->next;
    }
}




