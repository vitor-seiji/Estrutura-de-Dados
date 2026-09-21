#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100

typedef struct{
    int tamanho;
    char vetor[MAX];
}Lista;

void criarLista(Lista*);//cria uma lista vazia
void construirListaSimples(Lista*, int);
void inserirLista(Lista*, int i); //insere o valor i no final da lista
void mostrarLista(Lista*);//printa a lista
void inserirPosicao(Lista*, int n, int p);//insere o valor n na posição p 
void removerPosicao(Lista*, int p);//remove o valor da posição p da lista
void removerLista(Lista*);//remove o ultimo elemento da lista
int verificarDuplicatas(Lista*);//verifica se ha duplicatas na lista
void removerElemento(Lista*, int e);//remove a primeira aparição do elemento e da lista
void embaralhar(Lista*);//embaralha a lista
void inverterLista(Lista*);//inverte a lista
void construirListaAleatoriaN(Lista*, int M); //Lista aleatória com números da faixa de 1 - m
void construirListaAleatoria(Lista*, int n, int Min, int Max); //Cria uma lista aleatória de tamanho N na faixa de Min - Max
void construirListaAleatoriaSN(Lista*, int tam, int Min, int Max); // Cria uma lista aleatória de tamanho N na faixa de Min - Max sem repetição
void bubbleSort(Lista*); //Ordena a lista em ordem crescente
void quickSort(Lista*, int, int);
int separarLista(Lista*,int, int);
void trocar(Lista*, int, int);


void criarLista(Lista *A){
    A->tamanho = 0;
}

void construirListaSimples(Lista*A, int n){
    if(n < 1 || n > MAX - 1){
        A->tamanho = MAX - 1; 
    }
    else{
        A->tamanho = n;
    }
    int i;
    for(i = 1; i <= A->tamanho; i++){
        A->vetor[i] = i;
    }
}

void inserirLista(Lista *A, int i){//insere o valor i no final da lista
    if(A->tamanho < MAX - 1){
        A->tamanho++;
        A->vetor[A->tamanho] = i;
    }
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
	if((A->tamanho > 0 && A->tamanho < MAX - 1)  && (p > 0 && p <= A->tamanho)){
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
        ult = A->tamanho;
        for(n=ult; n>0; n--){
            k = rand() % n;	
            k++;			// gera um número na faixa de 1 até n
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

void construirListaAleatoriaN(Lista*A, int M){
	int j, r, hi, lo;
	double g;
	lo = 1;
	if((M>0) && (M < MAX - 1)){
		A->tamanho = M;
        hi = M;
	}
	else{
		A->tamanho = MAX - 1;
        hi = MAX - 1;
	}
	srand((int) time(NULL));
	for(j = 1; j <= M; j++){
		g = (double)rand()/((double)RAND_MAX + 1);
		r = g*(hi-lo+1) + lo;
		A->vetor[j] = r;
	}
}

void construirListaAleatoria(Lista*A, int n, int Min, int Max){//n = tamanho da lista; Min = valor minimo; Max = valor maximo
	int j, r, hi, lo;
	double g;
	lo = Min;
	hi = Max;
	if((n>0) && (n < MAX - 1)){
		A->tamanho = n;
	}
	else{
		A->tamanho = MAX - 1;
	}
	srand((int) time(NULL));
	for(j = 1; j <= n; j++){
		g = (double)rand()/((double)RAND_MAX + 1);
		r = g*(hi-lo+1) + lo;
		A->vetor[j] = r;
	}
}

void construirListaAleatoriaSN(Lista *A, int tam, int Min, int Max) {
    int m = tam; 
    long long n = (long long)Max - Min + 1;

    // Validações
    if (m > n) m = (int)n;
    if (m >= MAX) m = MAX - 1; // Se o vetor tem tamanho MAX, o último índice é MAX-1

    int cont = 1; // <-- COMEÇA NO 1
    for (int i = Min; i <= Max && m > 0; i++) {
        
        // n nunca será 0 aqui por causa da condição i <= Max
        if ((rand() % n) < m) {
            A->vetor[cont] = i; // Grava na posição 1, depois 2...
            cont++;
            m--;
        }
        n--;
    }
    
    A->tamanho = cont - 1; // O tamanho real é o contador menos o 1 inicial
    
   int n1,ult,aux,k;
    ult = A->tamanho;
    for(n1=ult; n1>0; n1--){
        k = rand() % n1;	
        k++;			// gera um número na faixa de 1 até n
        aux=A->vetor[n1]; 
        A->vetor[n1]=A->vetor[k]; 
        A->vetor[k]=aux;		
    }
}


void bubbleSort(Lista* A) {
    if (A->tamanho > 1) {
        int aux;
        // i vai de 1 até o tamanho total
        for (int i = 1; i <= A->tamanho; i++) {
            // j deve ser reiniciado para 1 em TODA volta de i
            // O limite deve ser A->tamanho - i para que j+1 alcance o topo
            for (int j = 1; j <= A->tamanho - i; j++) {
                if (A->vetor[j] > A->vetor[j + 1]) {
                    aux = A->vetor[j];
                    A->vetor[j] = A->vetor[j + 1];
                    A->vetor[j + 1] = aux; 
                }
            }
        }
    }
}

void quickSort(Lista *A, int inicio, int fim){
    if(inicio < fim){
        int j;
        j = separarLista(A, inicio, fim);
        quickSort(A, inicio, j-1);
        quickSort(A, j+1, fim);
    }
}

int separarLista(Lista *A, int inicio, int fim){
    int i = inicio;
    int j = fim + 1;
    while(i < j){
        do{
            i =  i + 1;
        }while(A->vetor[i] < A->vetor[inicio] && i < fim);
        do{
            j = j - 1;
        }while(A->vetor[j] > A->vetor[inicio]);
        if(i < j){
            trocar(A, i ,j);
        }
    }
    trocar(A, inicio, j);
    return j;
}

void trocar(Lista *A, int i, int j){
    int aux = A->vetor[i];
    A->vetor[i] = A->vetor[j];
    A->vetor[j] = aux;
}
