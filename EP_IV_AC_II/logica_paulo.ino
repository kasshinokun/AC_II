// Definição dos pinos dos LEDs
const int ledPins[] = {10, 11, 12, 13};

// Definição da memória com 100 posições
byte memoria[100] = {0};

// Registradores
#define PC memoria[0]
#define W memoria[1]
#define X memoria[2]
#define Y memoria[3]

// Configuração inicial
void setup() {
  // Inicializar comunicação serial
  Serial.begin(9600);
  
  // Inicializar LEDs
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Exemplo de instrução na memória (posição 4)
  //memoria[4] = 0xC6B; // Exemplo de carga de instrução
  PC = 4; // Apontar para a primeira instrução
}

void loop() {
  // Verifica se há dados recebidos via serial
  if (Serial.available() > 0) {
    
    String input = Serial.readStringUntil('\n'); // Ler o comando (X, Y, S)
    if (input.length() == 3) {
      // Parse dos valores X, Y e S em hexadecimal
      X = hexToDec(input.charAt(0));
      Y = hexToDec(input.charAt(1));
      byte S = hexToDec(input.charAt(2));

      // Executar a operação com base na instrução
      executarInstrucao(S);

      // Atualizar LEDs com base no valor de W
      atualizarLeds(W);

      // Atualizar a memória e incrementar o PC
      memoria[1] = W; // Atualizar W
      PC++; // Apontar para a próxima instrução
    }
  }
}

// Função que converte char hexadecimal para decimal
byte hexToDec(char hex) {
  if (hex >= '0' && hex <= '9') {
    return hex - '0';
  } else if (hex >= 'A' && hex <= 'F') {
    return hex - 'A' + 10;
  }
  return 0;
}

// Função que executa a instrução com base no valor de S
void executarInstrucao(byte S) {
  switch (S) {
    case 0x0:
      W = 1; // Lógico 1
      break;
    case 0x1:
      W = X | (~Y); // X + Y'
      break;
    case 0x2:
      W = X; // X
      break;
    case 0x3:
      W = (~X) ^ (~Y); // X' ⊕ Y'
      break;
    case 0x4:
      W = ~(X & Y); // (X.Y)'
      break;
    case 0x5:
      W = ~X; // X'
      break;
    case 0x6:
      W = X & (~Y); // X.Y'
      break;
    case 0x7:
      W = (~X) | (~Y); // X' + Y'
      break;
    case 0x8:
      W = X ^ Y; // X ⊕ Y
      break;
    case 0x9:
      W = 0; // 0 Lógico
      break;
    case 0xA:
      W = Y; // Y
      break;
    case 0xB:
      W = X & Y; // X.Y
      break;
    case 0xC:
      W = ~Y; // Y'
      break;
    case 0xD:
      W = ~((~X) & Y); // (X'.B)'
      break;
    case 0xE:
      W = X | Y; // X + B
      break;
    case 0xF:
      W = (~X) & Y; // X'.B
      break;
    default:
      W = 0; // Operação padrão
      break;
  }
}


// Função para atualizar LEDs com base no valor de W
void atualizarLeds(byte resultado) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], bitRead(resultado, i));
  }
}