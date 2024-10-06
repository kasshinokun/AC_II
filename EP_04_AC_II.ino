//Exercício Prático 4 de Arquitetura de Computadores II 
//Criado em 05-10-2024
//Revisão 1_05_10_2024
//-------------------------Bibliotecas necessárias




//-------------------------Validação do Char Recebido 
bool validate_char(char a){
    return isHexadecimalDigit(a);
}

//-------------------------Split da String em array de Char





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



