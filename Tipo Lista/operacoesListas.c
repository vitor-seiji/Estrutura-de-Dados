#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100

typedef struct{
    int tamanho;
    char vetor[MAX];
}Lista;

void criarLista(Lista *A);//cria uma lista vazia
void inserirLista(Lista *A, int i); //insere o valor i no final da lista
void mostrarLista(Lista *A);//printa a lista
void inserirPosicao(Lista *A, int n, int p);//insere o valor n na posição p 
void removerPosicao(Lista *A, int p);//remove o valor da posição p da lista
void removerLista(Lista *A);//remove o ultimo elemento da lista
int verificarDuplicatas(Lista *A);//verifica se ha duplicatas na lista
void removerElemento(Lista *A, int e);//remove o elemento e da lista
void embaralhar(Lista*);//embaralha a lista
void inverterLista(Lista*);//inverte a lista

int main(){
    int i = 1;
    Lista A;
    criarLista(&A);
    for(i; i <= 25; i++){
        inserirLista(&A, i);
    }
    
    embaralhar(&A);

    mostrarLista(&A);

    inverterLista(&A);

    mostrarLista(&A);

    printf("\n\n Copias: %d\n", verificarDuplicatas(&A));

}

void criarLista(Lista *A){
    A->tamanho = 0;
}

void inserirLista(Lista *A, int i){//insere o valor i no final da lista
    A->tamanho++;
    A->vetor[A->tamanho] = i;
}

void removerLista(Lista *A){//remove o ultimo da lista
    if(A->tamanho > 0){
        A->tamanho--;
    }
}

void mostrarLista(Lista *A){//imprime toda a lista
	int i;
    if(A->tamanho > 0){
        for(i = 1; i <= A->tamanho; i++){
        printf("  %3d  ", A->vetor[i]);
        }
        printf("\n\n");
    }
    
}

void inserirPosicao(Lista *A, int n, int p){ // n = numero a ser colocado p = posição a ser ocupada
	int i;
	if(A->tamanho > 0 && (p > 0 && p <= A->tamanho)){
        A->tamanho++;
        for(i = A->tamanho; i > p; i--){
            A->vetor[i] = A->vetor[i - 1];
        }
        A->vetor[p] = n;
    }
}

void removerPosicao(Lista *A, int p){//remove o elemento na posição p
    int i;
    if(A->tamanho > 0 && (p > 0 && p <= A->tamanho)){
        for(i = p; i < A->tamanho; i++){
        A->vetor[i] = A->vetor[i + 1];
        }
        A->tamanho--;
    }
}

void removerElemento(Lista *A, int e)//e = elemento a ser removido
{
    if(A->tamanho> 0){
        int i = 0;
        do{
            i++;
            if(A->vetor[i] == e){
                removerPosicao(A, i);
            }
        }while(A->vetor[i] != e && i <= A->tamanho);
    }
}

int verificarDuplicatas(Lista *A){
    int total = 0;
    if(A->tamanho > 1){
    
        int total = 0;
        int i = 1;
        int j = 1;
        int copia[MAX];

        for(j; j <= A->tamanho; j++){
            copia[j] = 0;
        } 

        for(i = 1; i <= A->tamanho; i++){
            if(copia[i] == 0){
                int p = i;
                copia[i] = 1; //marca o original
                do{
                    p++;
                    if(A->vetor[i] == A->vetor[p]){
                        total++;
                        copia[p] = 1;//marca a duplicata
                    }
                }while(p <= A->tamanho); //percorre tudo
            }
        }
    }
    

    return total;
}

void embaralhar(Lista* A){
    if(A->tamanho > 1){
        int n,ult,aux,k;
        ult = A->tamanho-1;
        for(n=ult; n>0; n--){
            k = rand() % n;				// gera um número na faixa de 0 até n-1
            aux=A->vetor[n]; 
            A->vetor[n]=A->vetor[k]; 
            A->vetor[k]=aux;		
        }
    }
}

void inverterLista(Lista* A){
    if(A->tamanho > 1){
        int inicio = 1, fim = A->tamanho, aux;
        do{
            aux = A->vetor[inicio];
            A->vetor[inicio] = A->vetor[fim];
            A->vetor[fim] = aux;
            inicio++;
            fim--;
        }while(inicio < fim);
    }
}