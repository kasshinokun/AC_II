//adaptação código Romannelli
//Aula 21-10-2024

long c;
byte i, j;
int l, m;
float n,o;
long inicio, fim, tempo;
void setup() {
    Serial.begin(9600);
}

void loop() {
    
}

void byte_test(){
    i=1;
    j=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i=j;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}
void int_test() {
    l=1;
    m=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l=m;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}
void float_test() {
    n=1;
    o=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n=o;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}
//------------------------------------------------------------------------------------------------------------------
void byte_test_2(){
    i=1;
    j=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) i=3;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}
void int_test_2() {
    l=1;
    m=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) l=3;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}
void float_test_2() {
    n=1;
    o=3;
    inicio=micros();
    for(c=0;c<1000000;c=c+1) n=3;
    fim=micros();
    tempo=(fim-inicio);
    Serial.print("tempo= ");
    Serial.println(tempo);
}