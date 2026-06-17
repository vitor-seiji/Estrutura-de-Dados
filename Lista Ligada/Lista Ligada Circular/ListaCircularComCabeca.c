#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
} Lista;

Bool listaVazia(Lista);//Feito
Lista esvaziarLista(Lista);//Feito
Lista criarLista();//Feito
void mostrarLista(Lista);//Feito
Lista inserirInicio(Lista, int);//Feito
Lista inserirFim(Lista, int);//Feito
int obterTamanho(Lista );//Feito
Celula* buscarItem(Lista, int);//Feito
Lista removerPrimeiro(Lista);//Feito
Lista removerUltimo(Lista);//Feito

int main(){
    system("cls");

    Lista L;

    L = criarLista();

    L = inserirFim(L , 1);
    L = inserirFim(L , 2);
    L = inserirFim(L , 3);

    mostrarLista(L);

    L = removerPrimeiro(L);
    L = removerUltimo(L);
    printf("%d\n", obterTamanho(L));

    mostrarLista(L);

    L = esvaziarLista(L);
    
    if(listaVazia(L)){
        printf("vazia fi\n");
    }

    return 0;
}

Bool listaVazia(Lista A){
    Bool vazia = TRUE;
    if(A.tamanho > 0){
        vazia = FALSE;
    }
    return vazia;
}

int obterTamanho(Lista A){
    int cont;
    cont = A.tamanho;
    return cont;
}

Celula* buscarItem(Lista A, int n){
    Celula *p;
    if(A.tamanho > 0){
        
        p = A.inicio;
        while(p != NULL && p->elemento != n){
            p = p->next;
        }

    }
    return p;
}
Lista criarLista(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
}

Lista esvaziarLista(Lista A){
    if(A.tamanho > 0){
        Celula *p, *temp;
        p = A.inicio;
        while(A.tamanho > 0){
            temp = p;
            p = p->next;
            free(temp);
            A.tamanho--;
        }
    }
    A.tamanho = 0;
    A.inicio = NULL;
    return A;
}

void mostrarLista(Lista L){
    if(L.tamanho > 0){
        Celula *p;
        p = L.inicio;
        printf("Lista: ");
        do{
            printf("%d ", p->elemento);
            p = p->next;
        }while(p != L.inicio);
        printf("\n");
    }
}

Lista inserirInicio(Lista L, int n){
    Celula *novo;
    novo = (Celula *)malloc(sizeof(Celula));
    novo->elemento = n;
    if(L.inicio == NULL){//Se a lista for vazia a célula aponta para ela mesma
        L.inicio = novo;
        novo->next = novo;
    }
    else{
        Celula *p;
        p = L.inicio;
        
        while(p->next != L.inicio){
            p = p->next;
        }//Percorre a lista até chegar no último

        novo->next = L.inicio;
        L.inicio = novo;
        p->next = L.inicio;//Atualiza o next do último elemento
    }
    L.tamanho++;
    return L;
}

Lista inserirFim(Lista L, int n){
    Celula *novo;
    novo = (Celula *)malloc(sizeof(Celula));
    novo->elemento = n;
    if(L.inicio == NULL){
        L.inicio = novo;
        novo->next = novo;
    }
    else{
        Celula *p;
        p = L.inicio;
        do{
            p = p->next;
        }while(p->next != L.inicio);
        novo->next = p->next;
        p->next = novo;
    }
    L.tamanho++;
    return L;
}

Lista removerPrimeiro(Lista A){
    if(A.tamanho > 0){
        Celula *p, *aux;
        p = A.inicio;
        if(p->next == p){
            free(p);
            A.inicio = NULL;
        }
        else{
            while(p->next != A.inicio){
                p = p->next;
            }
            aux = A.inicio;
            A.inicio = aux->next;
            p->next = A.inicio;
            free(aux);
        }
        A.tamanho--;
    }
    return A;
}

Lista removerUltimo(Lista A){
    if(A.tamanho > 0){
        Celula *p, *aux;
        p = A.inicio;
        if(p->next == p){
            A.inicio = NULL;
            free(p);
        }
        else{
            while(p->next != A.inicio){
                aux = p;
                p = p->next;
            }
            aux->next = A.inicio;
            free(p);
        }
        A.tamanho--;
    }
    return A;
}