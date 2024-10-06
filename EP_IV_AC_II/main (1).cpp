#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para converter decimal para binário
void decimalParaBinario(int n, int bits) {
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
}

int main() {
    // Hexadecimal de 3 caracteres
    char hexNum[] = "1AF";

    // Converter o número hexadecimal para decimal (inteiro)
    int decimalValue = (int)strtol(hexNum, NULL, 16);

    // Exibir valor hexadecimal
    printf("Hexadecimal: %s\n", hexNum);

    // Converter o valor decimal para binário (12 bits, 3 dígitos hexadecimais)
    decimalParaBinario(decimalValue, 12);

    return 0;
}
