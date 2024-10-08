#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
