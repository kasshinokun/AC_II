

long c;
byte i, j;
int l, m;
float n,o; 
long inicio, fim, tempo;
int k;
float media;

//Variavel com Variavel
void calcula_base(void);
void base_byte(void);
void base_int(void);
void base_float(void);

void calcula_soma(void);
void soma_byte(void);
void soma_int(void);
void soma_float(void);

void calcula_multi();
void multi_byte(void);
void multi_int(void);
void multi_float(void);

void calcula_or();
void or_byte(void);
void or_int(void);

//Variavel com 3
void calcula_base_2(void);
void base_byte_2(void);
void base_int_2(void);
void base_float_2(void);

void calcula_soma_2(void);
void soma_byte_2(void);
void soma_int_2(void);
void soma_float_2(void);

void calcula_multi_2();
void multi_byte_2(void);
void multi_int_2(void);
void multi_float_2(void);

void calcula_or_2();
void or_byte_2(void);
void or_int_2(void);

void setup() {
	Serial.begin(9600);
}

void loop() {
 
  //calcula_base();
  //calcula_soma();
  //calcula_multi();
  //calcula_or();
  calcula_soma_2();
  calcula_multi_2();
  calcula_or_2();
} 
//==============================================================
//=============Calculo de 10 tentativas agrupadas
//==============================================================
void calcula_base(){
  Serial.println("Apos 10 leituras");
  base_byte();
  base_int();
  base_float();
  delay(5000);
}
void calcula_soma(){
  Serial.println("Apos 10 leituras");
  soma_byte();
  soma_int();
  soma_float();
  delay(5000);
}
void calcula_multi(){
  Serial.println("Apos 10 leituras");
  multi_byte();
  multi_int();
  multi_float();
  delay(5000);
}
void calcula_or(){
  Serial.println("Apos 10 leituras");
  or_byte();
  or_int();
  delay(5000);
}
//==============================================================
//=============Calculo de 10 tentativas agrupadas com 3
//==============================================================
void calcula_base_2(){
  Serial.println("Apos 10 leituras");
  base_byte_2();
  base_int_2();
  base_float_2();
  delay(5000);
}
void calcula_soma_2(){
  Serial.println("Apos 10 leituras");
  soma_byte_2();
  soma_int_2();
  soma_float_2();
  delay(5000);
}
void calcula_multi_2(){
  Serial.println("Apos 10 leituras");
  multi_byte_2();
  multi_int_2();
  multi_float_2();
  delay(5000);
}
void calcula_or_2(){
  Serial.println("Apos 10 leituras");
  or_byte();
  or_int();
  delay(5000);
}
//==============================================================
//=============Tempo Base
//==============================================================
void base_byte(){
  i=1;
  j=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i=j;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void base_int(){
  l=1;
  m=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l=m;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void base_float(){
  n=1;
  o=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n=o;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Float: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Somas
//==============================================================
void soma_byte(){
  i=1;
  j=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i+=j;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void soma_int(){
  l=1;
  m=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l+=m;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void soma_float(){
  n=1;
  o=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n=n+o;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Float: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Multiplicação
//==============================================================
void multi_byte(){
  i=1;
  j=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i*=j;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void multi_int(){
  l=1;
  m=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l*=m;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void multi_float(){
  n=1;
  o=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n*=o;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Float: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Operação OR
//==============================================================
void or_byte(){
  i=1;
  j=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i=i|j;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void or_int(){
  l=1;
  m=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l=l|m;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Somas com 3
//==============================================================
void soma_byte_2(){
  i=1;
  j=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i+=3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void soma_int_2(){
  l=1;
  m=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l+=3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void soma_float_2(){
  n=1;
  o=3;
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n=n+3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Float: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Multiplicação com 3
//==============================================================
void multi_byte_2(){
  i=1;

  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i*=3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void multi_int_2(){
  l=1;
 
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l*=3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void multi_float_2(){
  n=1;
  
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n*=3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Float: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
//==============================================================
//=============Operação OR com 3
//==============================================================
void or_byte_2(){
  i=1;
  
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i=i|3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Byte: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}
void or_int_2(){
  l=1;
  
  media=0;
  for (k=1;k<=10;k=k+1) // apenas para realizar a medida 10 vezes
  { 
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l=l|3;
    fim=micros();
    tempo=(fim-inicio);
    //Serial.print("tempo= ");
  	//Serial.println(tempo);
    media=media+tempo;
  }
  Serial.print("\nTempo gasto media Int: ");
  Serial.print(media/10.0);
  Serial.println("ms.");
}