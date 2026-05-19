#include<stdio.h>
#include"pilhas.h"

int main(){

    Pilha A;
    A = criarPilha();
    mostrarPilha(A);

    Pilha B;
    B = construirPilha(10);
    mostrarPilha(B);

    B = pancakeSort(B);
    mostrarPilha(B);

    return 0;
}