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

int obterTamanho(Lista);
void mostrarLista(Lista);
void trocarCelulas(Lista *, Celula *, Celula *);
Bool verificarCrescente(Lista);
Bool verificarIgual (Lista, Lista);// Verifica se as duas listas contêm os mesmos elementos, não importa a ordem. As listas não contêm duplicatas

void inserir(Lista*, int); //Insere no inicio
void inserirFinal(Lista *, int); //Insere no fim
void inserirOrdem(Lista *, int, int); //Insere em uma posição específica
void buscaInsere(Lista*, int);//Insere um elemento apenas se ele for inédito na lista

void remover(Lista *, int y);//Remove a primeira aparição de y
void removerTodos(Lista*, int);//Remove todos os elementos de y
void removerOrdem(Lista *, int);//Remove o item de ordem k
void removerPrimeiro(Lista *); //Remove o primeiro elemento
void removerUltimo(Lista *); //Remove o último elemento

int main(){

    system("cls");

    Lista c;
    Lista a; //Lista para testes com lista vazia
   

    //Criando Lista vazia
    c = criarListaVazia();
    a = criarListaVazia();
    printf("verificar lista vazia:\n");

    if(verificarVazia(c)){
        printf("Lista vazia!\n\n");
    }
    //-----------------Testando Funções de Inserção-----------------
    
    //inserir()
    int i;
    for(i = 1; i <= 10; i++){
        inserir(&c, i);
    }

    for(i = 1; i <= 2; i++){
        inserir(&a, i);
    }
   
    printf("inserir():\n");
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    printf("inserir ordem inicio:\n");
    inserirOrdem(&c, 1, 1);
    mostrarLista(c);

    printf("inserir ordem meio:\n");
    inserirOrdem(&c, 3, 7);
    mostrarLista(c);

    printf("inserir ordem fim:\n");
    inserirOrdem(&c, 13, 111);
    mostrarLista(c);
    
    printf("inserir final: \n");
    inserirFinal(&c, 2);
    mostrarLista(c);
    printf("Tamanho: %d\n\n", c.tamanho);

    mostrarLista(c);
    mostrarLista(a);

    Lista d, e;

    d = criarListaVazia();
    e = criarListaVazia();

    for(i = 1; i <= 10; i++){
        inserir(&d, i);
        inserirFinal(&e, i);
    }

    mostrarLista(d);
    mostrarLista(e);

    if(verificarIgual(d, e)){
        printf("igual");
    }
    else{
        printf("nao igual");
    }

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

Bool verificarCrescente(Lista A){
    Bool cresc = FALSE;
    if(A.tamanho > 1){
        Celula *p, *ant;
        ant = A.inicio;
        p = A.inicio;
        cresc = TRUE;
        do{
            p = p->next;
            if(p != NULL && ant->elemento > p->elemento){
                cresc = FALSE;
            }
            ant = p;
        }while(p != NULL && cresc != FALSE);
    }
    return cresc;
}

Bool verificarIgual(Lista A, Lista B){
    Bool igual = FALSE;
    if(A.tamanho == B.tamanho){
        igual = TRUE;
        Bool contem = FALSE;
        Celula *a = A.inicio, *b = B.inicio;

        while(a != NULL && igual == TRUE){
        
            while(b != NULL && contem == FALSE){
                if(a->elemento == b->elemento){
                    contem = TRUE;
                }
                b = b->next;
            }
            a = a->next;
            if(contem == FALSE){
                igual = FALSE;
            }
            contem = FALSE;
        }
    }
    return igual;
}

int obterTamanho(Lista L){
    int tam;
    tam = L.tamanho;
    return tam;
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

void inserirOrdem(Lista *L, int k, int n){//Insere n no local de ordem k
    if(k > 0 && k <= L->tamanho + 1){
        int cont = 1;
        Celula *novo, *ant, *p = L->inicio;
        ant = L->inicio;
        novo = (Celula*)malloc(sizeof(Celula));
        novo->elemento = n;

        while(cont != k){
            ant = p;
            p = p->next;
            cont++;
        }

       
        if(p == ant){//Caso a posição seja a primeira (k = 1)
            novo->next = L->inicio;
            L->inicio = novo;
        }
        else{
            novo->next = p;
            ant->next = novo;
        }
        
        L->tamanho++;
    }
}

void buscaInsere(Lista *A, int n){
    Bool existe = FALSE;
    Celula *p;
    p = A->inicio;
    while (p != NULL && p->elemento != n){
        p = p->next;
        if(p->elemento == n){
            existe = TRUE;
        }
    }
    if(p->elemento == n){
        existe = TRUE;
    }

    if(existe == FALSE){
        Celula *novo;
        novo = (Celula*)malloc(sizeof(Celula));
        novo->elemento = n;
        novo->next = A->inicio;
        A->inicio = novo;
        A->tamanho++;
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
            L->tamanho--;
        }
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
                if(p == L->inicio){//Se y for o primeiro elemento 
                    L->inicio = p->next;
                    p = L->inicio;
                }
                else{
                    ant->next = p->next;//Pula o p
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
            ant = p;
            p = p->next;
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

void trocarCelulas(Lista *L, Celula *A, Celula *B) {
    // Se as duas referências forem para a mesma célula, nenhuma troca é necessária
    if (A == B) {
        return;
    }

    // 1. Encontrar os nós anteriores a A e B
    Celula *antA = NULL, *antB = NULL;
    Celula *atual = L->inicio;

    while (atual != NULL && (antA == NULL || antB == NULL)) {
        if (atual->next == A) {
            antA = atual;
        }
        if (atual->next == B) {
            antB = atual;
        }
        atual = atual->next;
    }

    // 2. Ajustar os ponteiros de quem vem ANTES de A e B
    
    // Se A for o início da lista
    if (antA == NULL) {
        L->inicio = B;
    } else {
        antA->next = B;
    }

    // Se B for o início da lista
    if (antB == NULL) {
        L->inicio = A;
    } else {
        antB->next = A;
    }

    // 3. Ajustar os ponteiros dos PRÓPRIOS nós (A->next e B->next)
    // Precisamos de uma variável auxiliar para não perder a referência
    Celula *temp = A->next;
    A->next = B->next;
    B->next = temp;
}

