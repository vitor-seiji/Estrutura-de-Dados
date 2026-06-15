#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"
#define fantasma 0

typedef struct Celula {
    unsigned char elemento;
    struct Celula *next;
} Celula;

typedef Celula* Lista; 

// Protótipos corrigidos
Bool listaVazia(Lista);
Lista esvaziarLista(Lista);
Lista newLista();
void mostrarLista(Lista);
int obterTamanho(Lista );
Celula* buscarItem(Lista, unsigned char);
Lista inserirInicio(Lista, unsigned char);
Lista inserirFim(Lista, unsigned char);
Lista removerPrimeiro(Lista);
Lista removerUltimo(Lista);

int main(){
    Lista A, B;

    A = newLista(); 
    B = newLista();

    int i;
    for(i = 1; i <= 5; i++){
        A = inserirFim(A, 'a' + (i - 1)); 
        B = inserirInicio(B, 'z' - (i - 1));
    }
    
    mostrarLista(A); 
    mostrarLista(B);

    A = removerPrimeiro(A);
    A = removerUltimo(A);

    mostrarLista(A); 

    printf("Tamanho: %d", obterTamanho(A));

    return 0;
}

Lista newLista(){
    Lista L;
    L = NULL; 
    return L;
}

Lista esvaziarLista(Lista A){
    if(A != NULL){
        Celula *p, *temp;
        p = A;
        while(p != NULL){
            temp = p;
            p = p->next;
            free(temp);
        }
    }
    return A;
}
void mostrarLista(Lista L){
    Celula *p;
    p = L;
    while(p != NULL){
        printf("%c ", p->elemento);
        p = p->next;
    }
    printf("\n");
}

int obterTamanho(Lista L){
    int cont = 0;
    if(L != NULL){
        Celula *p;
        p = L;
        while(p != NULL){
            cont++;
            p = p->next;
        }
    }
    return cont;
}

Celula* buscarItem(Lista A, unsigned char a){
    Celula *p;
    if(A != NULL){
        p = A;
        while(p != NULL && p->elemento != a){
            p = p->next;
        }
    }
    return p;
}
Lista inserirInicio(Lista L, unsigned char n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;  
    novo->next = L; 
    L = novo;     
    return L;  
}

Lista inserirFim(Lista L, unsigned char n){
    Celula *novo, *p;
    p = L;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;  
    novo->next = NULL;

    if(p == NULL){
        L = novo;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = novo;
    }
    return L;
}

Lista removerPrimeiro(Lista L){
    if(L != NULL){
        Celula *aux, *p;
        p = L;
        p = p->next;
        aux = L;
        L = p;
        free(aux);
    }
    return L;
}

Lista removerUltimo(Lista L){
    if(L != NULL){
        Celula *p, *ant;
        p = L;
        if(p->next == NULL){//Caso só tenha um elemento na lista
            L = NULL;
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
    return L;
}