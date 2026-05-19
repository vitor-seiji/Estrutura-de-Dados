#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "Booleano.h"
#define SINAL 0
#define Fantasma 0

#define MaxPilha 201
typedef struct {
      int topo;    // topo indica o local onde se encontra o topo da pilha
      unsigned int tabela[MaxPilha];	  // os itens são colocados na pilha a partir da posição 1 
} Pilha;

Pilha criarPilha();						// criar pilha vazia
Pilha construirPilha(int);				// construir uma pilha com os números inteiros de {1..n] em ordem aleatória
void mostrarPilha(Pilha);				// mostrar o topo e o conteúdo da pilha
boolean PilhaVazia(Pilha);				// devolver TRUE se a pilha é vazia
unsigned int acessarTopo(Pilha);		// devolver o valor que está no topo da pilha
int obterTamanho(Pilha);				// devolver o tamanho da pilha
int contarPilha(Pilha, unsigned int);	// devolver a quantidade de itens da pilha até a ocorrência do valor dado.
int obterMaior(Pilha, int);
Pilha pushPilha(Pilha, unsigned int);	// colocar um item na pilha
Pilha popPilha(Pilha);					// retirar um item da pilha
Pilha inverter(Pilha,int);
Pilha pancakeSort(Pilha);


Pilha criarPilha(){
    Pilha A;
    A.topo = 0;
    return A;
}

Pilha construirPilha(int tam){
    Pilha A;
    int i;
    if(tam > MaxPilha - 1){
        tam = MaxPilha - 1;
    }
    A.topo = tam;
    for(i = 1; i <= A.topo; i++){
        A.tabela[i] = i;
    }
    int n,ult,aux,k;
	ult = A.topo;
	for(n=ult; n>0; n--){
		k = rand() % n + 1;				// gera um número na faixa de 0 até n-1
        aux=A.tabela[n]; A.tabela[n]=A.tabela[k]; A.tabela[k]=aux;	 
	}	
    return A;
}

void mostrarPilha(Pilha A){
    if(A.topo > 0){
        int i;
        for(i = A.topo; i >= 1; i--){
            printf("%d\n", A.tabela[i]);
        }
    }
    printf("\n");
}

boolean PilhaVazia(Pilha A){
    boolean vazia;
    if(A.topo == 0 ? TRUE : FALSE)
    return vazia;
}

unsigned int acessarTopo(Pilha A){
    unsigned int topo = A.tabela[A.topo];
    return topo;
}

int obterTamanho(Pilha A){
    int tam;
    tam = A.topo;
    return tam;
}

int contarPilha(Pilha A, unsigned int c){
    int i;
    int posicao = 0;
    if(A.topo > 0){
        i = 0;
        do{
            i++;
            if(A.tabela[i] == c){
                posicao = i;
            }
        }while(i < A.topo && A.tabela[i] != c);
    }
    return posicao;
}

Pilha pushPilha(Pilha A, unsigned int n){
    if(A.topo < MaxPilha - 1){
        A.topo++;
        A.tabela[A.topo] = n;
    }
    return A;
}

int obterMaior(Pilha A, int n){
    int indice = Fantasma;

    if(A.topo >= 1){
        int maior = A.tabela[1];
        int i;
        for(i = 2; i <= n; i++){
            if(A.tabela[i] > maior){
                maior = A.tabela[i];
                indice = i;
            }
        }
    }
    return indice;
}

Pilha inverter(Pilha A, int k){
    int inicio = 1;
    int fim = k;
    while(inicio < fim){
        int aux = A.tabela[inicio];
        A.tabela[inicio] = A.tabela[fim];
        A.tabela[fim] = aux;
        inicio++;
        fim--;
    }
    return A;
}

Pilha pancakeSort(Pilha A){
    if(A.topo > 1){
       for(int tam = A.topo; tam > 1; --tam){
            int maior = obterMaior(A, tam);

            // Se o maior não estiver na posição correta 
            if (maior != tam) {
                // 1. Leva o maior para o topo (índice 1)
                if (maior != 1) {
                    A = inverter(A, maior);
                }
                // 2. Leva o maior do topo para a posição final atual (tam_atual)
                A = inverter(A, tam);
            }
       }
       A = inverter(A, A.topo);
    }
    return A;
}