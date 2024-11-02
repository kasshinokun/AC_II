//Base Gabriel 23-10-2024
long c;
int i,j;

long inicio, fim, tempo,base;
void setup() {
    Serial.begin(9600);
    
}

void loop() {
    for(int p=0;p<10;p++){
        
        
        inicio=micros();
        for(c=0;c<1000000;c=c+1)
        { 
        //----Atribuição
           i=j;
        //----Soma       
           //i=i+j; 
           //i=i+3;
        //----Multiplicação    
           //i=i*j; 
           //i=i*3;
        //----OR    
           //i=i|j; 
           //i=i|3;
        }
        fim=micros();
        tempo=(fim-inicio);
        base=base+tempo;
        
        Serial.print("tempo ");
        Serial.print(p+1);
        Serial.print("= ");
        Serial.println(tempo);    
    }
  	Serial.print("tempo medio= ");
    Serial.println(base/10);
    base=0;
}