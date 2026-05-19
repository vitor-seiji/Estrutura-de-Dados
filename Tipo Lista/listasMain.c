#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"listas.h"

int main(){

    Lista A;
    construirListaSimples(&A, 10);
    mostrarLista(&A);
    embaralhar(&A);
    mostrarLista(&A);

    Lista B;
    construirListaAleatoriaN(&B, 10);
    mostrarLista(&B);

    Lista C;
    construirListaAleatoria(&C, 15, 10, 30);
    mostrarLista(&C);

    Lista D;
    construirListaAleatoriaSN(&D, 20, 10, 40);
    mostrarLista(&D);
    bubbleSort(&D);
    mostrarLista(&D);
    inverterLista(&D);
    mostrarLista(&D);

    return 0;
}