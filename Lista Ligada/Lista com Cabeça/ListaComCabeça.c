#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"
#define fantasma 0

typedef struct Celula{
    int elemento;
    struct Celula *next;
}Celula;

typedef struct{
    int tamanho;
    Celula *inicio;
}Lista;

Lista criarListaVazia();
Bool verificarVazia(Lista);
void mostrarLista(Lista);
void inserir(Lista*, int);
void inserirFinal(Lista *, int);
void inserirOrdem(Lista *, int, int);
void remover(Lista *, int y);//Remove a primeira aparição de y
void removerTodos(Lista*, int);//Remove todos os elementos de y
void removerOrdem(Lista *, int);//Remove o item de ordem k
void removerPrimeiro(Lista *);
void removerUltimo(Lista *);

int main(){
    Lista c;

    //Criando Lista vazia
    c = criarListaVazia();
    printf("verificar lista vazia:\n");

    if(verificarVazia(c)){
        printf("Lista vazia!\n\n");
    }

    //inserindo valores na lista
    int i;
    for(i = 1; i < 6; i++){
        inserir(&c, i);
    }
   
    printf("Lista inicial:\n");
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("inserir ordem:\n");
    inserirOrdem(&c, 2, 10);
    mostrarLista(c);
    
    printf("inserir final: \n");
    inserirFinal(&c, 2);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("remover todos: \n");
    removerTodos(&c, 2);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("remover especifico: \n");
    remover(&c, 2);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("remover ordem: \n");
    removerOrdem(&c, 2);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("remover primeiro: \n");
    removerPrimeiro(&c);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("remover ultimo: \n");
    removerUltimo(&c);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("inserir final: \n");
    inserirFinal(&c, 4);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    return 0;
}

Lista criarListaVazia(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
}

Bool verificarVazia(Lista L){
    Bool vazia = FALSE;
    if(L.tamanho == 0){
        vazia = TRUE;
    }
    return vazia;
}

void mostrarLista(Lista C){
    if(C.tamanho == 0){
        printf("Lista Vazia\n");
    }
    else{
        Celula *p;
        p = C.inicio; //Se a lista for vazia P = null
        do{
            printf("%d  ", p->elemento);
            p = p->next;
        }while(p != NULL);
        printf("\n\n");
    }
}

void inserir(Lista *L, int n){
    Celula *novo;
    novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;
    novo->next = L->inicio;
    L->inicio = novo;
    L->tamanho++;
}

void inserirFinal(Lista *L, int n){
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    novo->elemento = n;
    novo->next = NULL;

    if(L->inicio == NULL){
        L->inicio = novo;
    }
    else{
        Celula *p = L->inicio;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = novo;
    }
    L->tamanho++;
}

void inserirOrdem(Lista *L, int k, int n){
    if(k > 0 && k <= L->tamanho + 1){
        int cont;
        Celula *p = L->inicio;
        Celula *novo;
        novo = (Celula*)malloc(sizeof(Celula));
        novo->elemento = n;

        for(cont = 1; cont < k - 1; cont++){
            p = p->next;
        }
        
        novo->next = p->next;
        p->next = novo;
        L->tamanho++;
    }
}

void remover(Lista *L, int y){//Remove a primeira aparição de y
    if(!L->tamanho == 0){
        Celula *p = L->inicio;
        Celula *ant = L->inicio;

        while(p != NULL && p->elemento != y){//Varre a lista até achar o valor ou chegar no final caso não ache
           ant = p; 
           p = p->next; 
        } 

        if(p != NULL){
            if(ant == p){//Caso o valor seja o primeiro
                Celula *aux = L->inicio;
                L->inicio = p->next;
                free(aux);
            }
            else{//"Pula" o valor 
                Celula *aux = p;
                ant->next = p->next;  
                free(aux);
            }
        }
        L->tamanho--;
    }
}

void removerTodos(Lista *L, int y){//Remove todos os elementos y da Lista
    if(L->tamanho > 0){
        Celula *p, *ant;
        p = L->inicio;
        ant = NULL;
        while(p != NULL){
            if(p->elemento == y){
                Celula *aux;
                aux = p;
                if(p == L->inicio){
                    L->inicio = p->next;
                    p = L->inicio;
                }
                else{
                    ant->next = p->next;
                    p = p->next;
        
                }
                free(aux);
                L->tamanho--;
            }
            else{
                ant = p;
                p = p->next; 
            }
            
        }
    }
}

void removerOrdem(Lista *L, int k){//Remove o elemento de ordem k
    if((k > 0 && k <= L->tamanho) && L->tamanho > 0){//Verifica se a lista é vazia e se k pertence ao intervalo da lista
        Celula *p, *ant;
        p = L->inicio;
        ant = L->inicio;
        int cont = 1;

        while(cont != k){
            p = p->next;
            if(cont != k - 1){
                ant = ant->next;
            }
            cont++;
        }

        if(cont == k){
            if(ant == p){
                L->inicio = p->next;
                free(p);
            }
            else{
                ant->next = p->next;
                free(p);
            }
        }
        L->tamanho--;
    }
}

void removerPrimeiro(Lista *L){
    if(L->tamanho > 0){
       Celula *aux = L->inicio; 
       L->inicio = L->inicio->next;
       free(aux);
       L->tamanho--;
    }
}

void removerUltimo(Lista *L){
    if(L->tamanho > 0){
        Celula *p = L->inicio;
        
        if(p->next == NULL){ // Caso só tenha um elemento
            free(p);
            L->inicio = NULL;
        }
        else{
            Celula *ant = NULL;
            while(p->next != NULL){
                ant = p;
                p = p->next;
            }
            ant->next = NULL;
            free(p); // Libera o último
        }
        L->tamanho--;
    }
}



