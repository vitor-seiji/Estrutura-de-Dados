#include<stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *noEsq;
    struct No *noDir;
    int dado;
}No;

typedef No* Arvore;

typedef struct Fila{
    Arvore no;
    struct Fila *prox;
} Fila;

Arvore criarArvore();
Arvore adicionarDireita(Arvore, int);
Arvore adicionarEsquerda(Arvore, int);
Arvore criaNo(int);


int altura(Arvore raiz);
void preencheMatriz(Arvore raiz, int **M, int linha, int colEsq, int colDir);
void imprimeArvoreFormatada(Arvore raiz);


int main(){
    Arvore A;

    A = criarArvore();
    A = criaNo(1);
    A->noDir = criaNo(3);
    A->noEsq = criaNo(2);
    A->noEsq->noDir = criaNo(4);
    A->noEsq->noEsq = criaNo(5);
    A = adicionarDireita(A, 10);
    A = adicionarDireita(A, 11);


    imprimeArvoreFormatada(A);
    printf("\n\n");
    return 0;
}

Arvore criarArvore(){
    Arvore A;
    A = NULL;
    return A;
}

Arvore criaNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->noEsq = NULL;
    novo->noDir = NULL;
    return novo;
}

Arvore adicionarDireita(Arvore raiz, int n){  
    No *novo;
    novo = (No*)malloc(sizeof(No));
    novo->dado = n;
    novo->noDir = NULL;
    novo->noEsq = NULL; 
    if(raiz == NULL){
        raiz = novo;
    }
    else{
        No *ap = raiz;
        while(ap->noDir != NULL){
            ap = ap->noDir;
        }
        ap->noDir = novo;
    }

    return raiz;
}

Arvore adicionarEsquerda(Arvore raiz, int n){  
    No *novo;
    novo = (No*)malloc(sizeof(No));
    novo->dado = n;
    novo->noDir = NULL;
    novo->noEsq = NULL; 
    if(raiz == NULL){
        raiz = novo;
    }
    else{
        No *ap = raiz;
        while(ap->noEsq != NULL){
            ap = ap->noEsq;
        }
        ap->noEsq = novo;
    }

    return raiz;
}


// Calcula a altura da árvore
int altura(Arvore raiz){
    if(raiz == NULL) return 0;
    int he = altura(raiz->noEsq);
    int hd = altura(raiz->noDir);
    return 1 + (he > hd ? he : hd);
}

// Preenche a matriz M[linha][coluna] com os valores, centralizando cada nó
void preencheMatriz(Arvore raiz, int **M, int linha, int colEsq, int colDir){
    if(raiz == NULL) return;
    int meio = (colEsq + colDir) / 2;
    M[linha][meio] = raiz->dado;
    preencheMatriz(raiz->noEsq, M, linha + 1, colEsq, meio - 1);
    preencheMatriz(raiz->noDir, M, linha + 1, meio + 1, colDir);
}

// Imprime a árvore no formato "visual" (pai centralizado sobre os filhos)
void imprimeArvoreFormatada(Arvore raiz){
    int h = altura(raiz);
    if(h == 0){
        printf("Arvore vazia\n");
        return;
    }

    int cols = (1 << h) - 1; // 2^h - 1

    int **M = (int**) malloc(h * sizeof(int*));
    for(int i = 0; i < h; i++){
        M[i] = (int*) malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) M[i][j] = -1; // -1 = espaço vazio
    }

    preencheMatriz(raiz, M, 0, 0, cols - 1);

    int largura = 4; // espaço reservado por número (aumente se tiver 3+ dígitos)
    for(int i = 0; i < h; i++){
        for(int j = 0; j < cols; j++){
            if(M[i][j] == -1)
                printf("%*s", largura, "");
            else
                printf("%*d", largura, M[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < h; i++) free(M[i]);
    free(M);
}