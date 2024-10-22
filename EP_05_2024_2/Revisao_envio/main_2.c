#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variavel op Variavel

void calcula_base(void);
void calcula_soma(void);
void calcula_or(void);
void calcula_multi(void);

void base_char(void);
void soma_char(void);
void or_char(void);
void multi_char(void);

void base_int(void);
void soma_int(void);
void or_int(void);
void multi_int(void);

void base_float(void);
void soma_float(void);
void multi_float(void);

//Variavel op 3
void calcula_base_3(void);
void calcula_soma_3(void);
void calcula_or_3(void);
void calcula_multi_3(void);

void base_char_3(void);
void soma_char_3(void);
void or_char_3(void);
void multi_char_3(void);

void base_int_3(void);
void soma_int_3(void);
void or_int_3(void);
void multi_int_3(void);

void base_float_3(void);
void soma_float_3(void);
void multi_float_3(void);

//ponteiros
void usa_ponteiro(void);
void base_int_4(void);
void soma_int_2(void);
void or_int_2(void);
void multi_int_2(void);
void soma_int_4(void);
void or_int_4(void);
void multi_int_4(void);

int main()
{

    printf("Tempo Base\n");
    calcula_base();
    printf("\nTempo Soma\n");
    calcula_soma();
    printf("\nTempo OR\n");
    calcula_or();
    printf("\nTempo Multi\n");
    calcula_multi();
    printf("\n");
    printf("Tempo Base+3\n");
    calcula_base_3();
    printf("\nTempo Soma+3\n");
    calcula_soma_3();
    printf("\nTempo OR+3\n");
    calcula_or_3();
    printf("\nTempo Multi+3\n");
    calcula_multi_3();
    printf("\n");
    usa_ponteiro();
    return 0;

}
//Variavel com Variavel===================================================================================================================

void calcula_base(){
    printf("\nCHAR\n");
    base_char();
    printf("\nInt\n");
    base_int();
    printf("\nFloat\n");
    base_float();

}

void calcula_soma(){

    printf("\nCHAR\n");
    soma_char();
    printf("\nInt\n");
    soma_int();
    printf("\nFloat\n");
    soma_float();

}

void calcula_or(){

    printf("\nCHAR\n");
    or_char();
    printf("\nInt\n");
    or_int();

}

void calcula_multi(){

    printf("\nCHAR\n");
    multi_char();
    printf("\nInt\n");
    multi_int();
    printf("\nFloat\n");
    multi_float();

}


void base_char()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_char()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void or_char()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i|j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_char()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void base_int()
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
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_int()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void or_int()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i|j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_int()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void base_float()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_float()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_float()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

//Variavel com 3==========================================================================================================================
void calcula_base_3(){
    printf("\nCHAR\n");
    base_char();
    printf("\nInt\n");
    base_int();
    printf("\nFloat\n");
    base_float();

}

void calcula_soma_3(){

    printf("\nCHAR\n");
    soma_char();
    printf("\nInt\n");
    soma_int();
    printf("\nFloat\n");
    soma_float();

}

void calcula_or_3(){

    printf("\nCHAR\n");
    or_char();
    printf("\nInt\n");
    or_int();

}

void calcula_multi_3(){

    printf("\nCHAR\n");
    multi_char();
    printf("\nInt\n");
    multi_int();
    printf("\nFloat\n");
    multi_float();

}


void base_char_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_char_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void or_char_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i|3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_char_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;

    char i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void base_int_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_int_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void or_int_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i|3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_int_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k, i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void base_float_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_float_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i+3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void multi_float_3()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c;
    int k;
    float i=5;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=i*3; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

//Usando ponteiros==========================================================================================================================
void usa_ponteiro(){

    printf("\nTempo base com ponteiro:\n");
    base_int_4();
    printf("\n\nSoma com ponteiro:\n");
    soma_int_4();
    printf("\n\nOR com ponteiro:\n");
    or_int_4();
    printf("\n\nMulti com ponteiro:\n");
    multi_int_4();
    printf("\n\nSoma com ponteiro+3:\n");
    soma_int_2();
    printf("\n\nOR com ponteiro+3:\n");
    or_int_2();
    printf("\n\nMulti com ponteiro+3:\n");
    multi_int_2();
    printf("\n\nHello World\n");

}
void base_int_4()
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k,d;

    int a=5;
    int b=3;

    int *i;
    int *j;

    i=&a;
    j=&b;

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=10000000;c=c+1)i=j; // executa o loop
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}



void soma_int_4(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k,d;

    int a=5;
    int b=3;

    int *i;
    int *j;

    i=&a;
    j=&b;

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            d=*i+*j;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void or_int_4(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k,d;

    int a=5;
    int b=3;

    int *i;
    int *j;

    i=&a;
    j=&b;

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            d=*i|*j;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void multi_int_4(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k;

    int a=5;
    int b=3;

    int *i;
    int *j;

    i=&a;
    j=&b;

    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            *i *=*j;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void soma_int_2(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k;

    int a=5;


    int *i;


    i=&a;


    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            *i +=3;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void or_int_2(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k;

    int a=5;


    int *i;


    i=&a;


    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            *i =*i|3;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}

void multi_int_2(){
    clock_t inicio, fim, T;
    float Tempo, media=0;
    int c,k;

    int a=5;


    int *i;


    i=&a;


    T=CLOCKS_PER_SEC;

    for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
    {   inicio=clock(); // Marca o tempo inicial

        for (c=1;c<=10000000;c=c+1){

            *i *=3;

        }
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
//==============================================================================================================

//revisao 1_21_10_2024

void base_int_5() //no registrador 100 x 10^6 instruções
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    register int c;//rodando no registrador
    int k;
    int qtd=100;//realizar a medida 100 vezes
    long instruction=100000000; //10 x 10^6 ou 100 x 10^6 instruções
    int i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=qtd;k=k+1) // apenas para realizar a medida 10 ou 100 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=instruction;c=c+1)i=j; // executa o loop 10 x 10^6 ou 100 x 10^6
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_int_5() //no registrador 100 x 10^6 instruções
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    register int c;//rodando no registrador
    int k;
    int qtd=100;//realizar a medida 100 vezes
    long instruction=100000000; //10 x 10^6 ou 100 x 10^6 instruções
    int i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=qtd;k=k+1) // apenas para realizar a medida 10 ou 100 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=instruction;c=c+1)i=i+j; // executa o loop 10 x 10^6 ou 100 x 10^6
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}
void soma_int_5() //no registrador 100 x 10^6 instruções
{
    clock_t inicio, fim, T;
    float Tempo, media=0;
    register int c;//rodando no registrador
    int k;
    int qtd=100;//realizar a medida 100 vezes
    long instruction=100000000; //10 x 10^6 ou 100 x 10^6 instruções
    int i=5, j=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=qtd;k=k+1) // apenas para realizar a medida 10 ou 100 vezes
    {   inicio=clock(); // Marca o tempo inicial
        for (c=1;c<=instruction;c=c+1)i=i|j; // executa o loop 10 x 10^6 ou 100 x 10^6
        fim = clock(); //Marca o tempo final
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC); //Calcula tempo final - tempo inicial
        //printf("\nTempo : %g ms.", Tempo);
        media=media+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", media/10);
}