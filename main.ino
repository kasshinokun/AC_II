// C++ code
//Algoritmo desenvolvido por Welbert em 02-10-2024
//Adaptado para Arduino por Gabriel em 05-10-2024
//Revisao 1_05_10_2024

#include <string.h>
#include <math.h>

typedef struct {
  char key;
  int value;
}dictionary_1;

typedef struct {
  int key;
  char value;
}dictionary_2;

dictionary_1 char_to_int[]={{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},
                            {'8',8},{'9',9},{'A',10},{'a',10},{'B',11},{'b',11},{'C',12},
                            {'c',12},{'D',13},{'d',13},{'E',14},{'e',14},{'F',15},{'f',15}};

dictionary_2 int_to_char[]={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},
{7,'7'},{8,'8'},{9,'9'},{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};



bool valide_string(String str){
   bool resp=false;
   char* s = convert_char_array(str);
   if (str.length()==1){
     
   // Displaying the values stored in the array of
   // structures
     for (int i = 0; i < (sizeof(char_to_int) / sizeof(*char_to_int)); i++) {
        if (char_to_int[i].key==s[0]){
          resp=true;
          delete[] s;
          break;
        }
     }
   }
   return resp;
}


//Converte o caracter para decimal baseando-se em heexadecimal
unsigned long hex2dec(String hex)
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
//Checagem do tamanho da String
int check_string(String str) {
    if (str.length() % 3 == 0 && str.length() % 96 == 0) {
        return 1;
    } else {
        return 0;
    }
}

char* convert_char_array(String str) {
    if (check_string(str) == 1) {
        // Aloca o array na heap para evitar problemas de escopo
        char* arr= new char[str.length() + 1];
        strcpy(arr, str.c_str());
        return arr;  // Retorna o ponteiro para o array
    } else {
        return nullptr;  // Retorna nullptr se a condicao nao for atendida
    }
}

void execute_operations(String str) {
    char* arr= convert_char_array(str);
    if (arr != nullptr) {
        // Executa operacoes com o array de caracteres
        Serial.println("Array de caracteres: ");
      	Serial.print(arr);
        Serial.println ();

        delete[] arr;
        Serial.println();  
    }else{
        Serial.println("Erro: A string nao atende os condicoes.");
    }
}
//Funcoes de portas logicas (vazias por enquanto)
int porta_not(char a) {
    if (valide_string(String()+a)==1){
        return ~hex2dec(String()+a);
    }
}
int porta_not_2(char a) {
    if (valide_string(String()+a)==1){
        int x=hex2dec(String()+a);
        return (x>0|x!=0?~x+1:~x+2);
    }
}
int porta_and(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return (hex2dec(String()+a) & hex2dec(String()+b));
    }
}
int porta_or(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return (hex2dec(String()+a) | hex2dec(String()+b));
    }
}
int porta_xor(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return (hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}

int porta_nand(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return ~(hex2dec(String()+a) & hex2dec(String()+b));
    }
}
int porta_nor(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return ~(hex2dec(String()+a) | hex2dec(String()+b));
    }
}
int porta_xnor(char a, char b) {
    if (valide_string(String()+a)==1 && valide_string(String()+b)==1){
        return ~(hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}

void setup()
{
  
}

void loop()
{
  
}
