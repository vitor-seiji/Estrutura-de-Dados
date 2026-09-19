#include <stdio.h>
#include<stdlib.h>

typedef struct no {
    int dado;
    struct no *esquerda;
    struct no *direita;
} No;

typedef No * Arvore;

Arvore criarArvore() {
    Arvore arvore = NULL;
    return arvore;
}

Arvore inserir(Arvore, int);
void mostraArvore(Arvore);
No* criarNo(int);

int main() {

    Arvore A = criarArvore();

    A = inserir(A, 1);
    A = inserir(A, 2);
    A = inserir(A, 8);
    A = inserir(A, 4);

    mostraArvore(A);

    return 0;
}

No* criarNo(int n){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = n;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}


Arvore inserir(Arvore A, int valor){
    if(A == NULL){
        A = criarNo(valor);
    }
    else{
         
        if (valor < A->dado) {
            A->esquerda = inserir(A->esquerda, valor);
        } else if (valor > A->dado) {
            A->direita = inserir(A->direita, valor);
        }
        
    }

    return A;
}

void mostraArvore(Arvore raiz){
    if (raiz != NULL) {
        mostraArvore(raiz->esquerda);
        printf("%d ", raiz->dado);
        mostraArvore(raiz->direita);
    }
}
