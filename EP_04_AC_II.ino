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


//Variáveis Pseudo Hashmap--------------- 
const int SIZE = 16;
String keys[SIZE];
int values[SIZE];


//Adicionando valores
keys={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

values={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}

//---------------------------------------





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

//------------------------Pseudo Hashmap 
/*
https://www.arduino.cc/reference/pt/

No Tinkercad, bibliotecas mais avançadas, como uma biblioteca de hash map (tabelas de hash ou mapas associativos), não estão disponíveis diretamente, pois o simulador tem uma limitação em relação às bibliotecas externas.

A ideia de um hash map não é nativamente suportada em Arduino devido à sua memória limitada e ao foco em sistemas embarcados. No entanto, existem algumas bibliotecas que oferecem funcionalidades de mapas associativos para Arduino, mas você teria que usá-las na Arduino IDE, e não diretamente no Tinkercad.

Alternativa para simular Hash Map no Tinkercad:
Se você realmente precisa de uma estrutura similar a um hash map no Tinkercad, você pode simular isso usando arrays ou listas associativas simples em C++. Aqui está um exemplo básico de como simular um hash map usando arrays no Arduino:

Exemplo simples de um "pseudo hash map":*/

// Função para adicionar um par chave-valor
void add(String key, int value) {
  for (int i = 0; i < SIZE; i++) {
    if (keys[i] == "") { // Se o slot estiver vazio
      keys[i] = key;
      values[i] = value;
      return;
    }
  }
}

// Função para procurar o valor associado a uma chave
int get(String key) {
  for (int i = 0; i < SIZE; i++) {
    if (keys[i] == key) {
      return values[i];
    }
  }
  return -1; // Se não encontrar
}

void teste_insert_hash() {

  // Adicionando pares chave-valor
  add("A", 100);
  add("B", 200);
  add("C", 300);

  // Buscando valor pela chave
  Serial.println(get("A")); // Deve retornar 100
  Serial.println(get("B")); // Deve retornar 200
  Serial.println(get("D")); // Não encontrado, retorna -1
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
    Serial.begin(9600);

    //Iniciar LED's


    //Demais funções


}
//-------------------------Loop de processos
void loop(){
    //Roda rotina para tratar a string recebida



}



