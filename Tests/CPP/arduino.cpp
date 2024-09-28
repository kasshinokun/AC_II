#include <iostream>
#include <string>
using namespace std;

class op_arduino{
  //atributos
  private:
  int x,y,op_code;

  public:
  //construtor
  op_arduino(int x,int y,int opcode){
    this->set_x(x);
    this->set_y(y);
    this->set_opcode(opcode);
  }
  //setters e getters
  void set_x(int x){
    this->x=x;
  }
  int get_x(){
    return this->x;
  }
   void set_y(int y){
    this->y=y;
  }
  int get_y(){
    return this->y;
  }
  void set_opcode(int opcode){
    this->opcode=opcode;
  }
  int get_opcode(){
    return this->opcode;
  }
  string to_String(){
    return ("%d%d%d",x,y,opcode)
  }
};
class tp_03{
  private:
  vet_op[]=new int[100];//está como int mas utilizem a string recebida fica mais prático a armazenagem
  vet_op[0]=4;//pc
  vet_op[1]=-1;//x
  vet_op[2]=-1;//y
  vet_op[3]=-1;//w

  boolean get_x(int i){
    if this->vet_op[i]!=null{
        return false;
    }
    return true;
  }
  void set_values_inside(int i,int x, int y, int opcode){
    vet_op[i]=x;//x
    vet_op[i+1]=y;//y
    vet_op[i+2]=opcode;
  }
  public:
  tp_03(op_arduino op_tp){
      for(int i=4;i<100;i++){
          if this->get_index(i)==true{
              this->set_index(i,op_tp.get_x(),op_tp.get_y(),op_tp.get_opcode());
              break;
          }
      }  
  }
  void set_index(int i,int x, int y, int opcode){
    //armazena as variaveis
    this->set_values_inside(i,x,y,opcode); //pode ser a string também
  }
  string show_index(int i){
  //exibe os valores no indice fornecido
    
  }
  
  void set_result(int x,int y,int opcode){

  }
};


int main(){


  return 0;
}
