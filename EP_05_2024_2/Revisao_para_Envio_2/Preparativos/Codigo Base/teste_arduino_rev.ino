//Base Gabriel 23-10-2024
long c;
byte i, j;
long inicio, fim, tempo,base;
void setup() {
    Serial.begin(9600);
}

void loop() {
    for(int p=0;p<10;p++){
        i=1;
        j=3;
        inicio=micros();
        for(c=0;c<1000000;c=c+1)
        {
            i=j;
        }
        fim=micros();
        tempo=(fim-inicio);
        base=base+tempo;
        Serial.print("tempo= ");
        Serial.println(tempo);
    }
  	Serial.print("tempo medio= ");
    Serial.println(base/10);
    base=0;
}
