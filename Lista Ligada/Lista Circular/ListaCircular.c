#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
} Lista;

Lista criarLista();
void mostrarLista(Lista);
Lista inserirInicio(Lista, int);
Lista inserirFim(Lista, int);

int main(){
    system("cls");

    Lista L;

    L = criarLista();

    L = inserirFim(L , 1);
    L = inserirFim(L , 2);
    L = inserirFim(L , 3);

    mostrarLista(L);

    printf("%d", L.tamanho);
    return 0;
}

Lista criarLista(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
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
        do{
            p = p->next;
        }while(p->next != L.inicio);//Percorre a lista até chegar no último

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
