/* exercicio HASHING */
/* Arquivo: EXPF26.c
   Autor: LISBETE MADSEN BARBOSA
   Data: 22/02/26 11:57
   Descrição - Exercício adaptado do texto sobre Hash do prof. Paulo Feofiloff
*/

#include <stdio.h> 
#define Max 47

typedef unsigned int TipoChave;

unsigned char hash1(TipoChave);
TipoChave calcularHash(TipoChave, TipoChave);

int main (){

	int j,c;
	unsigned char hC;
	TipoChave key;
	
   	TipoChave A[Max] = {17,21,19,4,26,30,20,22,23,31,
	   					16,66,33,35,54,81,60,38,42,69,
						133,109,121,55,107,82,57,34,47,44,
						148,24,11,49,12,50,75,62,74,89,
						105,108,122,61,37,63,76};
	
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
	int i;
	printf("chave	hCode\n");
	for(i = 0; i < 47; i++){
		printf("%d	%d\n", A[i], calcularHash(A[i], 0));
	}

	//c-)
	TipoChave colisao[13] = {0};
	for(i = 0; i < 47; i++){
		int coli;
		coli = calcularHash(A[i], 0);
		colisao[coli]++;
	}
	for(i = 0; i < 47; i++){
		colisao[i]--;
	}
	printf("\n\n");
	printf("chave	colisao\n");
	for(i = 0; i < 13; i++){
		printf("%d    :    %d ", i, colisao[i]);
		printf("\n");
	}

	//d-)

	return 0;
}

unsigned char hash1(TipoChave K){
	unsigned char hCode;
	int i = 0;
	hCode = calcularHash(K, i);
	return hCode;
}

TipoChave calcularHash(TipoChave K, TipoChave i){
    int chave;
    chave = (K + i) % 13;
	return chave;
}
