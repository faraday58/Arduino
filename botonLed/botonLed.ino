//LED y Boton
int LED=12;
int Boton=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(Boton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  if( digitalRead(Boton) == HIGH)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  
  

}
