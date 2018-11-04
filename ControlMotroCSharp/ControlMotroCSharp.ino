//Control de Motor por C#
int s1=2;
int s2=3;
int pinPWM=5;
char dato;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  dato= Serial.read();
    
   if(dato == 'a')
  {
     digitalWrite(s1,LOW);
     digitalWrite(s2,HIGH);
     analogWrite(pinPWM,100);
     delay(200);
     digitalWrite(s1,LOW);
     digitalWrite(s2,LOW);
     delay(2500);
     digitalWrite(s1,HIGH);
     digitalWrite(s2,LOW);
     analogWrite(pinPWM,100);
     delay(200);     
  }
 dato='b';
     digitalWrite(s1,LOW);
     digitalWrite(s2,LOW);

}
