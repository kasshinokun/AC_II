//Exercício Prático 4 de Arquitetura de Computadores II 
//Criado em 05-10-2024
//Revisão 1_06_10_2024

/*

Lógica desenvolvida por Welbert 

Adaptada ao código inicial feito por Gabriel 

*/

//-------------------------Bibliotecas necessárias
#include <iostream>  // Usada para entrada e saída de dados (como cin e cout)
#include <string>    // Proporciona funcionalidades para manipulação de strings, como substr, length, etc.


using namespace std;

//-------------------------Validação do Char Recebido 
bool validate_char(char a){
    return isHexadecimalDigit(a);
}

//-------------------------Split da String em array de Char

/*
O que procuramos é uma forma de dividir uma string em partes de três caracteres e adicionar uma contrabarra (\) entre essas partes para facilitar a manipulação posterior.

A solução inicial envolve criar duas strings: uma que vai receber a string original, e outra que vai acumular as partes divididas da string (com a contrabarra). A cada três caracteres, a função pega uma substring e adiciona essa substring à segunda string, junto com a contrabarra.

Se a string original for "abcdefghijklmnopqrstuvwxyz1234567890", a saída seria:


String formatada: abc\def\ghi\jkl\mno\pqr\stu\vwx\yz1\234\567\890

Isso divide a string em blocos de 3 caracteres, adiciona uma contrabarra após cada bloco, e mantém o resto da string (se houver) no final.Essa abordagem resolve o problema de separar e formatar a string sem muita complicação!

Definimos uma string original e chamamos a função splitString para formatá-la.
*/

//Preparação da String 
string splitString(const string& input) {
    string result = "";  // String vazia para acumular o resultado
    int length = input.length();  // Tamanho da string original

    // Itera sobre a string a cada 3 caracteres
    for (int i = 2; i < length; i += 3) {
        // Pega uma substring de 3 caracteres
        string substring = input.substr(i - 2, 3);

        // Adiciona a substring ao resultado e depois uma contrabarra
        result += substring + "\\";
    }

    // Se a string não for múltiplo de 3, adiciona os caracteres restantes
    int remaining = length % 3;
    if (remaining > 0) {
        result += input.substr(length - remaining);
    }

    return result;//retorna a string formatada

}


//Teste de string
int leitura_string_teste() {
    // String original
    string originalString = "abcdefghijklmnopqrstuvwxyz1234567890";

    // Chama a função para dividir a string
    string formattedString = splitString(originalString);

    // Imprime o resultado
    cout << "String formatada: " << formattedString << endl;

    return 0;
}



//-------------------------Portas lógicas 
//Funcoes de portas logicas
int porta_not(char a) {
    if (validate_char(a)==true){
        return ~hex2dec(String()+a);
    }
}
int porta_not_2(char a) {
    if (validate_char(a)==true){
        int x=hex2dec(String()+a);
        return (x>0|x!=0?~x+1:~x+2);
    }
}
int porta_and(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return (hex2dec(String()+a) & hex2dec(String()+b));
    }
}
int porta_or(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return (hex2dec(String()+a) | hex2dec(String()+b));
    }
}
int porta_xor(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return (hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}

int porta_nand(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return ~(hex2dec(String()+a) & hex2dec(String()+b));
    }
}
int porta_nor(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return ~(hex2dec(String()+a) | hex2dec(String()+b));
    }
}
int porta_xnor(char a, char b) {
    if (validate_char(a)==true && validate_char(b)==true){
        return ~(hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}


//-------------------------MUX da ULA






//-------------------------Prototypes das funções e procedimentos do código 








//-------------------------Configuração da simulação 
void setup(){
    //Iniciar o Serial


    //Iniciar LED's


    //Demais funções


}
//-------------------------Loop de processos
void loop(){
    //Roda rotina para tratar a string recebida



}



