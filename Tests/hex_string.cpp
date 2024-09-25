/*
Template Arduino

Converter Hex para String mas mantendo os mesmos caracteres

E depois aplicar split() a cada 3 caracteres da String gerada


Armazenar em um vetor de 100 posições
4 dedicadas e as 96 para as operações
Como abaixo:
Vetor={[PC][W][X][Y][[96 operações]]}


*/

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <climits>



/*
96 operações para ula:

{5c3,9d4,73b,1ec,045,559,e30,11c,94e,06c,
103,f69,a0f,fd3,b8a,43a,a47,354,aaa,130,
2f4,e01,549,c01,b14,65d,ef3,4fb,d97,43f,
3fd,07a,161,ea5,58e,187,888,d8b,80f,fd1,
e00,ed4,a9c,fcd,c3e,d47,f7a,37b,535,207,
027,cbb,18b,a8a,9b6,3c7,2ad,817,931,7ba,
f4d,d21,104,1ed,019,71e,5ce,928,40d,f0a,
6e1,6f8,91a,1dd,026,ca8,eb4,31d,b69,3dc,
7b8,40b,ae8,a7b,0c0,37b,5cb,dc2,9e9,b74,
a14,d2a,55b,1e9,1b0,6b9}

*/

void test(int n);
void int_to_bin(int n);







using namespace std;

int main () {

    int n = 70;

    test(n);

    int_to_bin(n);

    return 0;

}
void test(int n){

  cout << dec << n <<endl; //decimal
  cout << hex << n <<endl; //hex
  cout << oct << n <<endl; //octal

}
void int_to_bin(int n){

    string r;
    while(n!=0) {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    cout<<r<<endl;



}

