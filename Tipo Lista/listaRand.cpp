#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void embaralhar(unsigned int V[], int);
void separarGrupos(unsigned int V[], int Q);

#define MAX 5
#define RNG 7000

unsigned int A[MAX];

main(){
    int m,n,i,selecao,restante,resto;
	int big,cont;
	
	m = MAX; n = RNG;
	
	srand((int) time(NULL));
	printf("\n\nSelecionar %d numeros na faixa de 0 a %d\n",m,n);
	
	selecao = m;
	restante = n;
	
	cont = 0; 
	printf("\n");
	
	for (i=0;i<n;i++){
		 big = RAND_MAX*rand() + rand();
		 resto = big % restante;
		 if (resto < selecao) {
		 	printf("  %3d  ",i);
            A[cont] = i;
			cont++;
		 	selecao--;
		 	if (cont == MAX){
                cont = 0; printf("\n");
            }
		 }
		 restante--;
	}
   
 	printf("\n\nfim\n\n");

    embaralhar(A, MAX);

    for(int j = 0; j < MAX; j++){
        printf("%d ", A[j]);
    }

	printf("\n\n");

	separarGrupos(A, 4);

}

void embaralhar(unsigned int V[], int Q){	// Q é o tamanho da lista de números
//	algoritmo P de embaralhamento (Knuth)	
	int n,ult,aux,k;
	ult = Q-1;
	for(n=ult; n>0; n--){
		k = rand() % n;				// gera um número na faixa de 0 até n-1
		aux=V[n]; V[n]=V[k]; V[k]=aux;		
	}	
}

void separarGrupos(unsigned int V[], int Q){ //Q = número por grupo
	
	int i = 0;
	int j = 1; 
	int atual = 0; //ponteiro para qual da lista deve ser printado
	int total = MAX / Q; // total de grupos
	int sobras = MAX % Q; // sobrantes caso haja

	
	if(sobras != 0){ //se sobrar pessoas adiciona mais um grupo e completa com fuba
		total++;
	}
	
	for(j; j <= total; j++){
		printf("grupo %d:\n", j);

		for(i = 0; i < Q; i++){
			if(atual >= MAX){ //maior ou igual pq o array vai de 0 até max-1
				printf("fuba ");
			}
			else{
				printf("%d ", A[atual]);
				atual++;
			}
			
		}
		printf("\n\n");

	}
}