// El sensor LM35 10mv/C     y la alimentación es de 0 a 5000 mV
//anlogRea()  maneja valores entre  0 a 1023
//Por lo tanto para obtener la temperatura
// T = analogRead()*500/1023
const int sensor =0;
int temperatura;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
temperatura=(analogRead(sensor)*500)/1023;
Serial.write(temperatura);
delay(200);  

}
