#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef Celula * Lista;

Bool listaVazia(Lista);
Lista esvaziarLista(Lista);
Lista newLista();
void mostrarLista(Lista);
int obterTamanho(Lista );
Celula* buscarItem(Lista, int);
Lista inserirInicio(Lista, int);
Lista inserirFim(Lista, int);
Lista removerPrimeiro(Lista);
Lista removerUltimo(Lista);

int main(){


    return 0;
}