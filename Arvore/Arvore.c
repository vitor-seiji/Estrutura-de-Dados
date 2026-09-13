#include<stdio.h>

typedef struct No{
    struct No *noEsq;
    struct No *noDir;
    int dado;
}No;

typedef No* Arvore;

Arvore criarArvore();


int main(){
    Arvore A;

    A = criarArvore();

    printf("\n\n");
    return 0;
}

Arvore criarArvore(){
    Arvore A;
    A = NULL;
    return A;
}