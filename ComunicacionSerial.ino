//Comunicación Serial
int LED = 13;
char data;
void setup() {
  //Estableciendo la velocidad de la comunicación
 Serial.begin(9600);
  pinMode(LED,OUTPUT);

}

void loop() {

//  digitalWrite(LED,HIGH);
  // put your main code here, to run repeatedly:
  data = Serial.read();
  switch(data)
  {
    case 'a':
    digitalWrite(LED,HIGH);
    break;
    case 'b':
    digitalWrite(LED,LOW);
    break;    
  }
}
