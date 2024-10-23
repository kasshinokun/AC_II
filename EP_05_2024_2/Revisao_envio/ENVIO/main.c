#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ARQUIVO BASE - REVISÃO

int main()//no registrador 100 x 10^6 instruções
{
    //Variavel de tempo
    clock_t inicio, fim, T;
    float Tempo, media=0;

    //Acumulador
    //descomente quando for rodar no registrador
    //register int c;

    //Acumulador
    //descomente quando for rodar na variavel
    int c;

    int k;//Contador

    //int qtd=100;//realizar a medida 100 vezes

    //long instruction=100000000; //10 x 10^6 ou 100 x 10^6 instruções

    //descomente quando for ponteiro op ponteiro
    //int a=5, b=3;
    //int *i=&a, *j=&b;

    //descomente quando for ponteiro op 3
    //int a=5;
    //int *i=&a;

    //descomente quando for i op j
    char i=5, j=3; //e troque os tipos a cada analise por favor
    //int i=5, j=3; //e troque os tipos a cada analise por favor
    //float i=5, j=3; //e troque os tipos a cada analise por favor

    //decomente quando for i op 3
    //char i=5; //e troque os tipos a cada analise por favor
    //int i=5; //Para Int
    //float i=5; //Para Float

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 ou 100 vezes
    {   inicio=clock(); // Marca o tempo inicial

        //decomente quando for i op j
        for (c=1;c<=10000000;c=c+1) i=j; // executa o loop 10 x 10^6 ou 100 x 10^6

        //decomente quando for i op 3
        //for (c=1;c<=100000000;c=c+1) i=i|3; // executa o loop 10 x 10^6 ou 100 x 10^6

        //decomente quando for ponteiro op ponteiro
        //for (c=1;c<=10000000;c=c+1) *i=*i | *j; // executa o loop 10 x 10^6 ou 100 x 10^6

        //decomente quando for ponteiro op 3
        //for (c=1;c<=10000000;c=c+1) *i=*i | 3; // executa o loop 10 x 10^6 ou 100 x 10^6

        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
    return 0;
}
