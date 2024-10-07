

//fusão dos códigos para Welbert e os demais que puderem 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NUM_STRINGS = 98;
const int STR_SIZE = 3;
char vetor[NUM_STRINGS][STR_SIZE + 1];  // Vetor de 96 strings, cada uma com 3 caracteres (mais 1 para o terminador '\0')


// Defina os pinos para os LEDs
int ledMSB = 13; // Bit mais significativo
int led2 = 12;
int led3 = 11;
int ledLSB = 10; // Bit menos significativo

// Variáveis
byte X = 0;       // Entrada X (4 bits)
byte Y = 0;       // Entrada Y (4 bits)
byte S = 0;       // Instrução (4 bits)
byte W = 0;       // Resultado (4 bits)



//prototypes(assinaturas)
bool check_string(String str);
char set_operacoes(char &operate);
void executa_exercicio(String str);
void exibe_no_led(char receivedChar);
byte executaInstrucoes(byte X, byte Y, byte S);
byte hexToByte(char hexChar);
void displayHexOnLeds(byte value);
void send_to_execute(String input);





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
bool check_string(String str) {
    if (str.length() % STR_SIZE == 0 && str.length() % NUM_STRINGS == 0) {
        return true;
    } else {
        return false;
    }
}

char set_operacoes(char &operate){
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
          
          
            Serial.print("String [");
            Serial.print("PC");
            Serial.print("]: [");
            Serial.print(vetor[0]);
			Serial.println("]");
            
            //executa a operação
            
            
            strcpy(vetor[1], vetor[i]);
          
            Serial.print("String [");
            Serial.print("XYS");
            Serial.print("]: [");
            Serial.print(vetor[1]);
            Serial.println("]");
          
            Serial.print("String [");
            Serial.print(i);
            Serial.print("]: [");
            Serial.print(vetor[i]);
            Serial.print("]|");
            
            // Aqui processamos o caractere de cada solução 
            //string no LED
            // Exemplo de processamento de um caractere da string
            exibe_no_led(vetor[i][2]);  
            
            //Restante do vetor
            for (int j=i+1;j<NUM_STRINGS;j++){
                Serial.print(vetor[j]);
            	Serial.print("|");
            }
            Serial.println();

            
        }
    }
}
void teste_exercicio(String str){
  
  
  
  
  
  
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
    Serial.print("Caractere recebido: ");
    Serial.print(receivedChar);
    Serial.print(" (0x");
    Serial.print(hexValue, HEX);
    Serial.println(")");
  
}


// Função para converter caractere hexadecimal em byte
byte hexToByte(char hexChar) {
  if (hexChar >= '0' && hexChar <= '9') return hexChar - '0';
  else if (hexChar >= 'A' && hexChar <= 'F') return hexChar - 'A' + 10;
  else if (hexChar >= 'a' && hexChar <= 'f') return hexChar - 'a' + 10;
  return 0;
}

// Função que executa as instruções da ULA
byte executaInstrucoes(byte X, byte Y, byte S) {
  switch (S) {
    case 0x0: return 1;            // Lógico umL
    case 0x1: return X | (~Y);     // A+B'
    case 0x2: return X;            // A copiaA
    case 0x3: return ~X ^ ~Y;      // A'⊕B'
    case 0x4: return ~(X & Y);     // (A.B)'
    case 0x5: return ~X;           // A'
    case 0x6: return X & (~Y);     // A.B'
    case 0x7: return ~X | ~Y;      // A' + B'
    case 0x8: return X ^ Y;        // A⊕B
    case 0x9: return 0;            // Lógico zeroL
    case 0xA: return Y;            // B copiaB
    case 0xB: return X & Y;        // A.B
    case 0xC: return ~Y;           // B'
    case 0xD: return ~(~X & Y);    // (A'.B)'
    case 0xE: return X | Y;        // A+B
    case 0xF: return ~X & Y;       // A'.B
    default: return 0;
  }
}


versão 2
// Função para exibir o valor W nos LEDs
void displayOnLeds(byte value) {
  digitalWrite(ledMSB, value & 0x08 ? HIGH : LOW);  // F3
  digitalWrite(led2,   value & 0x04 ? HIGH : LOW);  // F2
  digitalWrite(led3,   value & 0x02 ? HIGH : LOW);  // F1
  digitalWrite(ledLSB, value & 0x01 ? HIGH : LOW);  // F0
}



//versão 1
void displayHexOnLeds_1(byte value) {
  // Liga ou desliga os LEDs de acordo com o valor binário dos 4 bits mais baixos do valor hexadecimal
  digitalWrite(ledMSB, value & 0x08 ? HIGH : LOW); // Bit 3 (MSB)
  digitalWrite(led2,   value & 0x04 ? HIGH : LOW); // Bit 2
  digitalWrite(led3,   value & 0x02 ? HIGH : LOW); // Bit 1
  digitalWrite(ledLSB, value & 0x01 ? HIGH : LOW); // Bit 0 (LSB)
}



void send_to_execute(String input){

   input.trim();

   if (input.length() == 3) {
      X = hexToByte(input.charAt(0));
      Y = hexToByte(input.charAt(1));
      S = hexToByte(input.charAt(2));
      
      // Executa a operação da ULA
      W = executaInstrucoes(X, Y, S);
      
      // Exibe o resultado nos LEDs
      displayOnLeds(W);
      
      // Exibe no monitor serial
      Serial.print("Resultado W: 0x");
      Serial.println(W, HEX);
    } else {
      Serial.println("Entrada inválida! Insira 3 caracteres.");
    }
  }
}