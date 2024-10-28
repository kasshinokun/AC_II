#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ARQUIVO BASE - REVISÃO Parte 2

int main()//na variavel 1 x 10^6 instruções
{
    //Variavel de tempo
    clock_t inicio, fim, T;
    float Tempo, media=0;

    //Acumulador
    //Usando variavel
    int c;

    int k;//Contador

    int i=5;//Int

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        //decomente quando for i op j
        for (c=1;c<=1000000;c=c+1) i=i*3; // executa o loop 1 x 10^6

        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
    return 0;
}
