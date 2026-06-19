/* exercicio HASHING */
/* Arquivo: EXPF26.c
   Autor: Vitor Seiji Colombo Nishida
   Data: 22/02/26 11:57
   Descrição - Exercício adaptado do texto sobre Hash do prof. Paulo Feofiloff
*/

#include <stdio.h> 
#include "Booleano.h"
#define Max 47

#define fantasma -1

typedef unsigned int TipoChave;

//Protótipos
TipoChave hash1(TipoChave);
TipoChave calcularHash(TipoChave);

TipoChave A[Max] = {17,21,19,4,26,30,20,22,23,31,
	   					16,66,33,35,54,81,60,38,42,69,
						133,109,121,55,107,82,57,34,47,44,
						148,24,11,49,12,50,75,62,74,89,
						105,108,122,61,37,63,76};

TipoChave B[Max];

int main (){
	int i, j, c;  /* CORREÇÃO: Todas as declarações no início */
	TipoChave hC;
	TipoChave key;

	/* Inicializar B com fantasma */
	for(i = 0; i < 47; i++){
		B[i] = fantasma;
	}

	//a-)
	printf("\nLista A\n");
	c=0;
   	for (j=0; j<Max; j++){
		key = A[j];
		printf(" %4d ",key); c++;
		if(c==10) {
			printf("\n"); c = 0; 
		}	
	}
    printf("\n");

    printf("\n fim\n\n");
	
	//b-)
	
	printf("chave	hCode\n");
	for(i = 0; i < 47; i++){
		printf("%d	%d\n", A[i], calcularHash(A[i]));
	}

	//c-)
	TipoChave colisao[13] = {0};
	for(i = 0; i < 47; i++){
		int resto;
		resto = calcularHash(A[i]);
		colisao[resto]++;
	}
	for(i = 0; i < 13; i++){
		if(colisao[i] > 0){
			colisao[i]--;
		}
	}
	printf("\n\n");
	printf("chave	colisao\n");
	for(i = 0; i < 13; i++){
		printf("%d    :    %d ", i, colisao[i]);
		printf("\n");
	}
	printf("\n\n");
	//d-)

	for(i = 0; i < 47; i++){
		hC = hash1(A[i]);
		B[hC] = A[i];
	}
	printf("chave	hCode\n");
	for(i = 0; i < 47; i++){
		printf("%d	%d\n", i, B[i]);
	}
	return 0;
}

TipoChave hash1(TipoChave K){
    TipoChave hCode = K % 13;  // Calcula hash inicial 
    int tentativas = 0;
    
    while(B[hCode] != (TipoChave)fantasma && tentativas < Max){
        hCode = (hCode + 1) % Max;  // Incrementa circularmente o índice 
        tentativas++;
    }
    
    return hCode;
}

TipoChave calcularHash(TipoChave K){
    return K % 13;
}