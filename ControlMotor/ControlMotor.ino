//Declaración de puertos
int s1=2;
int s2=3;
int pinPWM=5;
int boton=8;




void setup() {
  // put your setup code here, to run once:
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(boton,INPUT);

}

void loop() {

  bool boton_alto=digitalRead(boton);
     digitalWrite(s1,LOW);
     digitalWrite(s2,LOW);

  if(boton_alto == HIGH)
  {
     digitalWrite(s1,LOW);
     digitalWrite(s2,HIGH);
     analogWrite(pinPWM,100);
     delay(500);
     digitalWrite(s1,LOW);
     digitalWrite(s2,LOW);
     delay(2500);
     digitalWrite(s1,HIGH);
     digitalWrite(s2,LOW);
     analogWrite(pinPWM,100);
     delay(500);     
  }

  

}
