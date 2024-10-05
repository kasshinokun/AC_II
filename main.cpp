//Algoritmo desenvolvido por Welbert em 02-10-2024
//Revisão 1_05_10_2024

//----------------------------------OBS. IMPORTANTE:-------------------------------------------------
//-------------------------Falta desenvolver armazenamento em vetor
//---------------------------------------------------------------------------------------------------


//Hashmap de funções ----->Gabriel analisando
//Fonte: https://www.geeksforgeeks.org/cpp-map-of-functions/

//Padrao
#include <iostream>
#include <cstring>  // Para usar strcpy
#include <math.h>
#include <algorithm>
#include <regex>//validar caracteres

//Hashmap de funcoes ----->Gabriel analisando
#include <bits/stdc++.h>
#include <map>
#include <string>
#include <unordered_map>
#include <memory>
#include <any>
#include <utility>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <cassert>
//#include <boost/function.hpp>//precisar adicionar ao CodeBlocks
//#include <boost/lambda/bind.hpp>//precisar adicionar ao CodeBlocks
//-----------------------------------------------------------------------------

using namespace std;
//namespace l = boost::lambda;

using namespace std;
bool valide_string(string const &s){
    return regex_match(s, regex("[a-fA-F0-9]*$"));
}
//Converte o caracter para decimal baseando-se em heexadecimal
unsigned long hex2dec(string hex)
{
    unsigned long result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;//retorna o valor
}

int check_string(string str) {
    if (str.size() % 3 == 0 && str.size() % 96 == 0) {
        return 1;
    } else {
        return 0;
    }
}

char* convert_char_array(string str) {
    if (check_string(str) == 1) {
        // Aloca o array na heap para evitar problemas de escopo
        char* arr = new char[str.length() + 1];
        strcpy(arr, str.c_str());
        return arr;  // Retorna o ponteiro para o array
    } else {
        return nullptr;  // Retorna nullptr se a condição não for atendida
    }
}

void execute_operations(string str) {
    char* arr = convert_char_array(str);
    if (arr != nullptr) {
        // Executa operações com o array de caracteres
        cout << "Array de caracteres: " << arr << endl;
        // Lembre-se de desalocar o array
        delete[] arr;
    } else {
        cout << "Erro: A string não atende às condições." << endl;
    }
}

// Funções de portas lógicas (vazias por enquanto)
int porta_not(char a) {
    if (valide_string(string()+a)==1){
        return ~hex2dec(string()+a);
    }
}
int porta_not_2(char a) {
    if (valide_string(string()+a)==1){
        int x=hex2dec(string()+a);
        return (x>0|x!=0?~x+1:~x+2);
    }
}
int porta_and(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return (hex2dec(string()+a) & hex2dec(string()+b));
    }
}
int porta_or(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return (hex2dec(string()+a) | hex2dec(string()+b));
    }
}
int porta_xor(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return (hex2dec(string()+a) ^ hex2dec(string()+b));
    }
}

int porta_nand(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return ~(hex2dec(string()+a) & hex2dec(string()+b));
    }
}
int porta_nor(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return ~(hex2dec(string()+a) | hex2dec(string()+b));
    }
}
int porta_xnor(char a, char b) {
    if (valide_string(string()+a)==1 && valide_string(string()+b)==1){
        return ~(hex2dec(string()+a) ^ hex2dec(string()+b));
    }
}

//Esta como int como preparativo para o teste 
//hashmap de funcoes similar 
//ao vetor com lambda em python        
int teste_de_validacao() {

    //teste Welbert
    string test_string = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
    execute_operations(test_string);//converte e valida para vetor de char

    //string para inteiro correto em hexadecimal depois para inteiro decimal
    cout << "\nCaracter/String para Hexadecimal\ne depois decimal teste:"<< endl;//ok
    cout << hex2dec("a") << endl;

    //Teste Regex
//----------------------------Funcionado Corretamente
    cout << "\nCaracteres validos\n0-9, a-f e A-F"<< endl;//ok
    cout << "\nCaracteres validos teste:"<< endl;//ok
    //deve printar 1 -->OK
    cout << valide_string("134")<< endl;//ok
    cout << valide_string("a34")<< endl;//ok
    cout << valide_string("A34")<< endl;//ok
    cout << valide_string("1b4")<< endl;//ok
    cout << valide_string("1B4")<< endl;//ok
    cout << valide_string("13b")<< endl;//ok
    cout << valide_string("13B")<< endl;//ok
    cout << valide_string("C3b")<< endl;//ok
    cout << valide_string("c3D")<< endl;//ok
    cout << valide_string("C3D")<< endl;//ok
    cout << valide_string("cab")<< endl;//ok
    cout << valide_string("caB")<< endl;//ok
    cout << valide_string("cAb")<< endl;//ok
    cout << valide_string("Cab")<< endl;//ok
    cout << valide_string("CAB")<< endl;//ok
    cout << "Caracteres Invalidos teste 1:"<< endl;//ok
    //deve printar 0 -->OK
    cout << valide_string("GAB")<< endl;//ok
    cout << valide_string("AgB")<< endl;//ok
    cout << valide_string("ABh")<< endl;//ok
//---------------------------Funcionado Corretamente(carece analise)
    cout << "Caracteres Invalidos teste 2:"<< endl;//ok
    //deve printar 0 -->OK
    cout << valide_string("CA!")<< endl;//ok
    cout << valide_string("C!A")<< endl;//ok
    cout << valide_string("!CA")<< endl;//ok
    cout << valide_string("CA ")<< endl;//ok
    cout << valide_string("C A")<< endl;//ok
    cout << valide_string(" CA")<< endl;//ok
//---------------------------Funcionado Corretamente(carece analise)
    //Apenas templates
    cout << "Portas Logicas teste:"<< endl;//ok
    cout << porta_not('a')<< endl;//ok
    cout << porta_and('a','b')<< endl;//ok
    cout << porta_nand('a','b')<< endl;//ok
    cout << porta_or('a','f')<< endl;//ok
    cout << porta_nor('a','f')<< endl;//ok
    cout << porta_xor('a','f')<< endl;//ok
    cout << porta_xnor('a','f')<< endl;//ok
    return 0;
}
int main() {

    teste_de_validacao()//Validacao de strings
        
    return 0;
}
