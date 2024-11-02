#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    clock_t inicio, fim, T;
    double Tempo, media=0;
    int c;
    int k, i=3, j=5;
    T=CLOCKS_PER_SEC;
    for (int k=1;k<=10;k=k+1)
    {   inicio=clock();
        for (c=1;c<=10000000;c=c+1)i=j;
        fim = clock();
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC);
        media=media+Tempo;
        printf("\nTempo gasto: %g ms.", Tempo);

    }
    printf("\nMedia do Tempo gasto: %g ms.", media/10);
}
