#include <iostream>
#include <cstring>  // Para usar strcpy
using namespace std;

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
    string test_string = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
    execute_operations(test_string);
    return 0;
}
