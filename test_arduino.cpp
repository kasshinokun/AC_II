//Código exemplo para o Arduino

//Criado em 02-10-2024
//Revisão 1_02_10_2024


#include <iostream>
using namespace std;

int check_string(string str) {
   
    if str.size()%3==0 and str.size()%96==0{
        return 1;
    }
    eles{
        return 0;
    }
}
char[] convert_char_array(string str){
    
    if check_string(str)==1{
        
        char arr[str.length() + 1]; 

	       return strcpy(arr, str.c_str()); 
        
    }else{

        return char arr[0] = '\0';

    }

}
void execute_operations(string str){

    char arr[str.length() + 1];   
    if strcpy(arr,convert_char_array(str))!='\0'{
     
    }else{
        cout<<"Erro"<<endl;
    }


}

//portas
void porta_not(char a){}
void porta_and(char a,char b){}
void porta_or(char a,char b){}
void porta_xor(char a,char b){}
void porta_nand(char a,char b){}
void porta_nor(char a,char b){}
void porta_xnor(char a,char b){}

//1 lógico


//0 lógico