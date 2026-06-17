#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef Celula * Lista;

Bool listaVazia(Lista);//Feito
Lista esvaziarLista(Lista);//Feito
Lista newLista();//Feito
void mostrarLista(Lista);//Feito
int obterTamanho(Lista);//Feito
Celula* buscarItem(Lista, int);
Lista inserirInicio(Lista, int);//Feito
Lista inserirFim(Lista, int);//Feito
Lista removerPrimeiro(Lista);//Feito
Lista removerUltimo(Lista);//Feito

int main(){

    system("cls");

    Lista A;
    Celula *teste = NULL;

    A = newLista();

    A = inserirInicio(A, 1);
    A = inserirInicio(A, 2);
    A = inserirInicio(A, 3);

    A = inserirFim(A, 1);
    A = inserirFim(A, 2);
    A = inserirFim(A, 3);
    A = inserirFim(A, 4);

    teste = buscarItem(A, 4);
    printf("%d\n", teste->elemento);

    mostrarLista(A);
    printf("%d\n", obterTamanho(A));
    A = removerPrimeiro(A);

    mostrarLista(A);

    A = removerUltimo(A);

    mostrarLista(A);

    A = esvaziarLista(A);

    printf("%d\n", obterTamanho(A));

    return 0;
}

Bool listaVazia(Lista A){
    Bool vazia;
    vazia = FALSE;
    if(A == NULL){
        vazia = TRUE;
    }
    return vazia;
}

Lista newLista(){
    Lista A;
    A = NULL;
    return A;
}

Lista esvaziarLista(Lista A){
    if(A != NULL){
        Celula *p, *aux, *temp;
        aux = A;
        if(aux->next == A){
            free(aux);
            A = NULL;
        }
        else{
            p = aux->next;
            do{
                temp = p;
                p = p->next;
                free(temp);
            }while(p != aux);
            free(aux);
            A = NULL;
        }
    }
    return A;
}

void mostrarLista(Lista A){
    if(A != NULL){
        Celula *p;
        p = A;
        do{
            printf("%d ", p->elemento);
            p = p->next;
        }while(p != A);
        printf("\n");
    }
}

int obterTamanho(Lista A){
    int cont;
    cont = 0;
    if(A != NULL){
        Celula *p;
        p = A;
        do{
            cont++;
            p = p->next;
        }while(p != A);
    }
    return cont;
}

Celula* buscarItem(Lista A, int n){
    Celula *alvo;
    alvo = NULL;
    if(A != NULL){
        Celula *p;
        p = A;
        do{
            if(p->elemento == n){
                alvo = p;
                p = A;
            }
            else{
               p = p->next; 
            }
        }while(p != A);
    }

    return alvo;
}
Lista inserirInicio(Lista A, int n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;
    if(A == NULL){
        A = novo;
        novo->next = A;
    }
    else{
        Celula *p;
        p = A;
        while(p->next != A){
            p = p->next;
        }
        novo->next = A;
        A = novo;
        p->next = A;
    }
    return A;
}

Lista inserirFim(Lista A, int n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;
    if(A == NULL){
        A = novo;
        novo->next = A;
    }
    else{
        Celula *p;
        p = A;
        while(p->next != A){
            p = p->next;
        }
        novo->next = A;
        p->next = novo;
    }
    return A;
}

Lista removerPrimeiro(Lista A){
    if(A != NULL){
        Celula *p, *aux;
        p = A;
        if(p->next == A){
            free(p);
            A = NULL;
        }
        else{
            aux = A;
            while(p->next != A){
                p = p->next;
            }
            p->next = aux->next;
            A = aux->next;
            free(aux);
        }
    }
    return A;
}

Lista removerUltimo(Lista A){
    if(A != NULL){
        Celula *p, *aux;
        p = A;
        if(p->next == A){
            free(p);
            A = NULL;
        }
        else{
            while(p->next != A){
                aux = p;
                p = p->next;
            }
            aux->next = p->next;
            free(p);
        }
    }
    return A;
}