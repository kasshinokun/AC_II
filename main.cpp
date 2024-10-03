//Algoritmo desenvolvido por Welbert em 02-10-2024
//Revisão 1_03_10_2024

#include <iostream>
#include <cstring>  // Para usar strcpy
#include <math.h>
#include <algorithm>
#include <regex>//validar caracteres

using namespace std;
bool valide_string(string const &s){
    return regex_match(s, regex("[^g-zG-Z]*$"));
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
void porta_not(char a) {}
void porta_and(char a, char b) {}
void porta_or(char a, char b) {}
void porta_xor(char a, char b) {}
void porta_nand(char a, char b) {}
void porta_nor(char a, char b) {}
void porta_xnor(char a, char b) {}

int main() {

    //teste Welbert
    string test_string = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
    execute_operations(test_string);//converte e valida para vetor de char

    //string para inteiro correto em hexadecimal depois para inteiro decimal
    cout << hex2dec("a") << endl;

    //Teste Regex
//----------------------------Funcionado Corretamente
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
    cout << valide_string("GAB")<< endl;//ok
    cout << valide_string("AgB")<< endl;//ok
    cout << valide_string("ABh")<< endl;//ok
//---------------------------Formular regex para esta parte
    cout << valide_string("CA!")<< endl;//erro
    cout << valide_string("C!A")<< endl;//erro
    cout << valide_string("!CA")<< endl;//erro
    cout << valide_string("CA ")<< endl;//erro
    cout << valide_string("C A")<< endl;//erro
    cout << valide_string(" CA")<< endl;//erro
    return 0;
}
