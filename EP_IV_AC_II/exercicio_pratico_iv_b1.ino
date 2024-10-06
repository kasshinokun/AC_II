





#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Defina os pinos para os LEDs
int ledMSB = 13; // Bit mais significativo
int led2 = 12;
int led3 = 11;
int ledLSB = 10; // Bit menos significativo

char* convert_char_array(String& str) {
    if (check_string(str) == 1) {
        // Aloca o array na heap para evitar problemas de escopo
        char* arr= new char[str.length() + 1];
        strcpy(arr, str.c_str());
        return arr;  // Retorna o ponteiro para o array
    } else {
        return nullptr;  // Retorna nullptr se a condicao nao for atendida
    }
}
void exibe_no_led(char& char receivedChar){
  
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
}

void displayHexOnLeds(byte value) {
  // Liga ou desliga os LEDs de acordo com o valor binário dos 4 bits mais baixos do valor hexadecimal
  digitalWrite(ledMSB, value & 0x08 ? HIGH : LOW); // Bit 3 (MSB)
  digitalWrite(led2,   value & 0x04 ? HIGH : LOW); // Bit 2
  digitalWrite(led3,   value & 0x02 ? HIGH : LOW); // Bit 1
  digitalWrite(ledLSB, value & 0x01 ? HIGH : LOW); // Bit 0 (LSB)
}

bool check_string(String& str) {
    if (str.length() % 3 == 0 && str.length() % 96 == 0) {
        return true;
    } else {
        return false;
    }
}

void executa_exercicio(String& str){
    
    //Valida se str.length %3 ou str.length %96
    if check_string(str)==true{

      //Converte char[]

      char* base[]={'s','s','s','s'};
      //==========={[PC] [X] [Y] [S]}
      char* vet[]=strcat(base,convert_char_array(str));
      
      int k=4;//
      
      for (int i=4; i<100;i+=4){
          
          //preparação base
          vet[0]=k;//PC

          vet[1]=vet[i+1];//X

          vet[2]=vet[i+2];//Y
          
          vet[3]=set_operacoes(vet[i+3]);//Envia W para obter Solucao
          
          //Exibe nos leds
          exibe_no_led(vet[3]);

          int j=i;//
          
          //Exibição da base
          Serial.print(vet[0]);
          Serial.print(vet[1]);
          Serial.print(vet[2]);
          Serial.print(vet[3]);
          
          //Restante do vetor
          for (;j<100;j++){
              Serial.print(vet[j]);
          //PC X Y W 4-99
              
          }
          Serial.println();
          k++;
      }

    }  
    //else{Serial.println("String Invalida");}
    
}
// Função para converter decimal para binário
String decimalParaBinario(int n, int bits) {
    // Array para armazenar os bits binários
    char binario[bits + 1];
    binario[bits] = '\0'; // Terminador de string

    // Preenche o array de trás para frente com os bits
    for (int i = bits - 1; i >= 0; i--) {
        binario[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }

    // Exibir valor binário
    printf("Binário: %s\n", binario);
    return binario;
}

void start_test() {
    // Hexadecimal de 3 caracteres
    char hexNum[] = "1AF";

    // Converter o número hexadecimal para decimal (inteiro)
    int decimalValue = (int)strtol(hexNum, NULL, 16);

    // Exibir valor hexadecimal
    printf("Hexadecimal: %s\n", hexNum);

    // Converter o valor decimal para binário (12 bits, 3 dígitos hexadecimais)
    printf("Resultado: %s\n",decimalParaBinario(decimalValue, 12));

    
}

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Configura os pinos dos LEDs como saídas
  pinMode(ledMSB, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledLSB, OUTPUT);

  // Mensagem inicial
  Serial.println("Digite um valor hexadecimal (0-9, A-F) para exibir nos LEDs.");
}
void loop() {
  // Verifica se há dados disponíveis na comunicação serial
  if (Serial.available() > 0) {
    // Lê o caractere recebido
    String receivedString = Serial.read();

    executa_exercicio(receivedString);
  }
}

