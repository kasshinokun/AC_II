//Esboço desenvolvido por Gabriel em Parceria com Welbert

//Revisão 1_07_10_2024

//Modelo usado para apresentar 
//ao Professor de Arquitetura 
//de Computadores II
//no dia 07/10/2024


//Bibliotecas default
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
const int NUM_STRINGS = 98;
const int STR_SIZE = 3;
char vetor[NUM_STRINGS][STR_SIZE + 1];  // Vetor de 96 strings, cada uma com 3 caracteres (mais 1 para o terminador '\0')


// Defina os pinos para os LEDs
int ledMSB = 13; // Bit mais significativo
int led2 = 12;
int led3 = 11;
int ledLSB = 10; // Bit menos significativo

//--------------------->Assinaturas(Prototypes) 
//--------------------->das funçoes presentes
//--------------------->no código
bool check_string(String str);
char set_operacoes(char &operate);
void executa_exercicio(String str);
void decToHexa (int decimalnum);
unsigned long hex2dec(String hex);

// Funções de portas lógicas (vazias por enquanto)
int porta_not(char a);
int porta_not_2(char a);
int porta_and(char a, char b);
int porta_or(char a, char b);
int porta_xor(char a, char b);
int porta_nand(char a, char b);
int porta_nor(char a, char b);
int porta_xnor(char a, char b);
              
//---------------------------->Configuração Arduino
void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  
  
  // Configura os pinos dos LEDs como saídas
  pinMode(ledMSB, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledLSB, OUTPUT);

  //Espera das portas
  Serial.setTimeout(10);
  // Mensagem inicial
  Serial.println("Por favor insira a String para que possa ler por gentileza:");
  
}
//---------------------------->Loop de Eventos Arduino
void loop() {
  
  
  // Verifica se há dados disponíveis na comunicação serial
  if (Serial.available() > 0) {
    // Lê a String recebida
    String receivedString = Serial.readString();
    receivedString.trim();
    Serial.println("Muito obrigado, eu li:");
    Serial.println(receivedString);
    
    //Prepara a String;
    String send_str="xxxxxx"+receivedString;
    
    //Envia ao procedimento
    executa_exercicio(send_str);
  }    
}


//---------------------------->Funções implementadas Arduino
bool check_string(String str) {
    if (str.length() % STR_SIZE == 0 && str.length() % NUM_STRINGS == 0) {
        return true;
    } else {
        return false;
    }
}

char set_operacoes(char &operate){
  //Aqui executa a operação
  
  //retorna o resultado
  return operate;

}void executa_exercicio(String str){
  
    //Valida se str.length %3 ou str.length %96
    if( check_string(str)==true){
        // Divide a string em blocos de 3 caracteres e armazena no vetor
        for (int i = 0; i < NUM_STRINGS; i++) {
            str.substring(i * STR_SIZE, (i * STR_SIZE) + STR_SIZE).toCharArray(vetor[i], STR_SIZE + 1);
        }

        // Exibe as 96 strings no monitor serial e processa cada uma delas
        for (int i = 2; i < NUM_STRINGS; i++) {
            
            //PC precisa contar
          
          
            //Serial.print("String [");
            //Serial.print("PC");
            Serial.print("[");
            Serial.print(vetor[0]);
			Serial.println("]");
            
            //executa a operação
            
            
            strcpy(vetor[1], vetor[i]);
            // Aqui processamos o caractere de cada solução 
            //string no LED
            // Exemplo de processamento de um caractere da string
            //Enviar enderço
            exibe_no_led(vetor[i][2]); 
            
            //Serial.print("String [");
            //Serial.print("XYS");
            Serial.print("[");
            Serial.print(vetor[1]);
            Serial.println("]");
          
            //Serial.print("String [");
            //Serial.print(i,HEX);
            Serial.print("[");
            Serial.print(vetor[i]);
            Serial.print("]|");
            
             
            
            //Restante do vetor
            for (int j=i+1;j<NUM_STRINGS;j++){
                Serial.print(vetor[j]);
            	Serial.print("|");
            }
            delay(5000);
            Serial.println();

            
        }
    }
}
void teste_exercicio(String str){//Teste preliminar
  
  	//Valida se str.length %3 ou str.length %96
    if( check_string(str)==true){
    	
        String start_String="xxx"+str; 

            
      	int size_v=start_String.length();
      
        //Tamanho do vetor(com 1 char extra  para o final null)
		int str_len = size_v + 1; 
        
        //Prepara o vetor de char(o buffer) 
		char vet[str_len];
      	
        //Copia para o vetor 
		start_String.toCharArray(vet, str_len);
      
        Serial.println("String preparada:");  	
        Serial.println(vet);
        
      	Serial.println("Vetor preparado:");  
        Serial.println(vet);
      
        
        
     	for (int i=5,k=4;i<str_len;i+=4,k++){
      		
            Serial.println("Vetor preparado:");  
        	decToHexa(k);
          	vet[2]=vet[i];
            vet[3]=vet[i+1];
            vet[4]=vet[i+2];
          
            //Exibição da base
            Serial.print(vet[0]);
            Serial.print(vet[1]);
            Serial.print(vet[2]);
            
          
            //Restante do vetor
            for (int j=i;j<str_len;j++){
                Serial.print(vet[j]);
            //PC X Y W 4-99

            }/*
            Serial.println();
          	Serial.println(vet);*/
        	delay(1000);
        }
        
    }
}
void exibe_no_led (char receivedChar){   
    // Converte o caractere para seu valor hexadecimal correspondente
    byte hexValue = 0;
    
    // Se for um número (0-9)
    if (receivedChar >= '0' && receivedChar <= '9') {
      hexValue = receivedChar - '0'; // Converte o caractere numérico para o valor correspondente
    }
    // Se for uma letra (A-F ou a-f)
    else if ((receivedChar >= 'A' && receivedChar <= 'F') || (receivedChar >= 'a' && receivedChar <= 'f')) {
      hexValue = (receivedChar & 0xDF) - 'A' + 10; // Converte o caractere de A-F (ou a-f) para o valor hexadecimal correspondente
    } else {
      Serial.println("Caractere inválido. Digite um valor hexadecimal (0-9, A-F).");
      return;
    }
    
    // Exibe o valor hexadecimal correspondente nos LEDs (apenas os 4 bits mais baixos)
    displayHexOnLeds(hexValue);
    
    // Mostra o valor hexadecimal no monitor serial
    //Serial.print("Caractere recebido: ");
    //Serial.print(receivedChar);
    //Serial.print(" (0x");
    //Serial.print(hexValue, HEX);
    //Serial.println(")");
  
}

void displayHexOnLeds(byte value) {
  // Liga ou desliga os LEDs de acordo com o valor binário dos 4 bits mais baixos do valor hexadecimal
  digitalWrite(ledMSB, value & 0x08 ? HIGH : LOW); // Bit 3 (MSB)
  digitalWrite(led2,   value & 0x04 ? HIGH : LOW); // Bit 2
  digitalWrite(led3,   value & 0x02 ? HIGH : LOW); // Bit 1
  digitalWrite(ledLSB, value & 0x01 ? HIGH : LOW); // Bit 0 (LSB)
}
void decToHexa (int num) {
  Serial.print(num, HEX);
}
//Converte o caracter para decimal baseando-se em long heexadecimal
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
// Funções de portas lógicas (vazias por enquanto)
//Codigo proveniente de EP 03 e C++ Porta NOT
int porta_not(char a) {
    if (isHexadecimalDigit(a)){
        return ~hex2dec(String()+a);
    }
}
//Codigo proveniente de EP 03 e C++ Porta NOT V2
int porta_not_2(char a) {
    if (isHexadecimalDigit(a)){
        int x=hex2dec(String()+a);
        return (x>0|x!=0?~x+1:~x+2);
    }
}
//Codigo proveniente de EP 03 e C++ Porta AND
int porta_and(char a, char b) {
    if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return (hex2dec(String()+a) & hex2dec(String()+b));
    }
}
//Codigo proveniente de EP 03 e C++ Porta OR
int porta_or(char a, char b) {
    if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return (hex2dec(String()+a) | hex2dec(String()+b));
    }
}
//Codigo proveniente de EP 03 e C++ Porta XOR
int porta_xor(char a, char b) {
    if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return (hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}
//Codigo proveniente de EP 03 e C++ Porta NAND
int porta_nand(char a, char b) {
   if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return ~(hex2dec(String()+a) & hex2dec(String()+b));
    }
}
//Codigo proveniente de EP 03 e C++ Porta NOR
int porta_nor(char a, char b) {
    if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return ~(hex2dec(String()+a) | hex2dec(String()+b));
    }
}
//Codigo proveniente de EP 03 e C++ Porta XNOR
int porta_xnor(char a, char b) {
   if (isHexadecimalDigit(a) && isHexadecimalDigit(b)){
        return ~(hex2dec(String()+a) ^ hex2dec(String()+b));
    }
}
