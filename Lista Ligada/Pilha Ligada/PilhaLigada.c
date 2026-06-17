#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"

typedef struct Celula {
    unsigned char elemento;
    struct Celula *next;
} Celula;

typedef struct{
    int tamanho;
    Celula *topo;
}Pilha; 

Bool pilhaVazia(Pilha);
Pilha newPilha();
Pilha pop(Pilha);
Pilha push(Pilha, unsigned char);
Celula* getTopo(Pilha);
void mostrarPilha(Pilha);


int main(){

    Pilha a;
    a = newPilha();

    if(pilhaVazia(a)){
        printf("vazia fi\n");
    }

    a = push(a, 'a');
    a = push(a, 'b');
    a = push(a, 'c');

    mostrarPilha(a);
    printf("oioi");
    return 0;
}

Bool pilhaVazia(Pilha A){
    Bool vazia = FALSE;
    if(A.topo == NULL){
        vazia = TRUE;
    }
    return vazia;
}

void mostrarPilha(Pilha A){
    if(A.tamanho > 0){
        Celula *p;
        p = A.topo;
        while(p != NULL){
            printf("%c\n", p->elemento);
            p = p->next;
        }
    } 
}

Celula* getTopo(Pilha A){
    Celula *p;
    p = A.topo;
    return p;
}

Pilha newPilha(){
    Pilha A;
    A.topo = NULL;
    A.tamanho = 0;
    return A;
}

Pilha pop(Pilha A){
    if(A.tamanho > 0){
        Celula *p, *aux;
        aux = A.topo;
        p = A.topo;
        p = p->next;
        A.topo = p;
        free(aux);
        A.tamanho--;
    }   
    return A;
}

Pilha push(Pilha A, unsigned char a){
    Celula *p;
    p = (Celula *)malloc(sizeof(Celula));
    p->elemento = a;
    p->next = A.topo;
    A.topo = p;
    A.tamanho++;
    return A;
}