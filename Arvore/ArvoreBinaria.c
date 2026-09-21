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

//Contruir Arvore
Arvore criarArvoreVazia();
Arvore construirArvore(int, Arvore, Arvore);
Arvore criaNo(int);

//Adicionar No
Arvore adicionarDireita(Arvore, int);
Arvore adicionarEsquerda(Arvore, int);

//Caminhamentos
void mostrarArvoreRED(Arvore);
void mostrarArvoreERD(Arvore);
void mostrarArvoreEDR(Arvore);

//Rotação
Arvore simplesEsquerda(Arvore);
Arvore simplesDireita(Arvore);
Arvore duplaEsquerda(Arvore);
Arvore duplaDireita(Arvore);

//Calcular propriedades
int calcularAltura(Arvore);
int calcularNos(Arvore);


//Mostrar Árvore
int altura(Arvore raiz);
void preencheMatriz(Arvore raiz, int **M, int linha, int colEsq, int colDir);
void imprimeArvoreFormatada(Arvore raiz);


int main(){
    system("cls");

    Arvore A, B, C;

    A = construirArvore(5, NULL, NULL);
    B = construirArvore(20, NULL, NULL);
    C = construirArvore(15, A, B);

    A = construirArvore(40, NULL, NULL);
    B = construirArvore(45, A, NULL);

    A = construirArvore(30, C, B);

    printf("caminhamento RED: ");
    mostrarArvoreRED(A);
    printf("\n\n");
    printf("caminhamento ERD: ");
    mostrarArvoreERD(A);
    printf("\n\n");
    printf("caminhamento EDR: ");
    mostrarArvoreEDR(A);
    printf("\n\n");
    //printf("Altura = %d\n", calcularAltura(A));
    //printf("Nos = %d\n", calcularNos(A));
    printf("Arvore original:\n\n");
    imprimeArvoreFormatada(A);

    printf("\n\n");
    printf("Simples DuplaDireita:\n\n");
    A = duplaDireita(A);
    imprimeArvoreFormatada(A);
    
    printf("\n\n");
    return 0;
}

Arvore criarArvoreVazia(){
    Arvore A;
    A = NULL;
    return A;
}

Arvore construirArvore(int n, Arvore a, Arvore b){
    Arvore novo;
    novo = malloc(sizeof(No));
    novo->dado = n;
    novo->noEsq = a;
    novo->noDir = b;
    return novo;
}

Arvore criaNo(int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->noEsq = NULL;
    novo->noDir = NULL;
    return novo;
}

int calcularAltura(Arvore raiz){
    int h;
    h = -1;
    if(raiz != NULL){
        int hd, he;
        he = 1 + calcularAltura(raiz->noEsq);
        hd = 1 + calcularAltura(raiz->noDir);
        if(he > hd){
            h = he;
        }
        else{
            h = hd;
        }
    }
    return h;
}

int calcularNos(Arvore raiz){
    int nos = 0;
    if(raiz != NULL){
        nos++;
        nos = nos + calcularNos(raiz->noEsq);
        nos = nos + calcularNos(raiz->noDir);
    }
    return nos;
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

void mostrarArvoreRED(Arvore raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        mostrarArvoreRED(raiz->noEsq);  
        mostrarArvoreRED(raiz->noDir);
    }
}

void mostrarArvoreERD(Arvore raiz){
    if(raiz != NULL){
        mostrarArvoreERD(raiz->noEsq);
        printf("%d ", raiz->dado);
        mostrarArvoreERD(raiz->noDir);
    }
}

void mostrarArvoreEDR(Arvore raiz){
    if(raiz != NULL){
        mostrarArvoreEDR(raiz->noEsq);
        mostrarArvoreEDR(raiz->noDir);
        printf("%d ", raiz->dado);
    }
}

Arvore simplesEsquerda(Arvore raiz){
    Arvore b, re;
    re = raiz;
    if(raiz != NULL){
        b = raiz->noDir;
        if(b != NULL){
            raiz->noDir = b->noEsq;
            b->noEsq = raiz;
            re = b;
        }
    }
    return re;
}

Arvore simplesDireita(Arvore raiz){
    Arvore b, re;
    re = raiz;
    if(raiz != NULL){
        b = raiz->noEsq;
        if(b != NULL){
            raiz->noEsq = b->noDir;
            b->noDir = raiz;
            re = b;
        }
    }
    return re;
}

Arvore duplaEsquerda(Arvore raiz){
    Arvore p;
    p = raiz;
    if(raiz != NULL){
        Arvore p;
        p = raiz;
        p = p->noDir;
        if(p != NULL){
            p = simplesDireita(p);
            raiz->noDir = p;
            raiz = simplesEsquerda(raiz);
        }
    }
    return raiz;
}

Arvore duplaDireita(Arvore raiz){
    Arvore p;
    p = raiz;
    if(raiz != NULL){
        Arvore p;
        p = raiz;
        p = p->noEsq;
        if(p != NULL){
            p = simplesEsquerda(p);
            raiz->noEsq = p;
            raiz =  simplesDireita(raiz);
        }
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

// Imprime a árvore no formato normal
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

    printf("\n\n");
    for(int i = 0; i < h; i++) free(M[i]);
    free(M);
}