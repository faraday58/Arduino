//Lectura de temperatura puerto serial
int AnalogIn=0;
long val= 0;
long op1;
long Temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(AnalogIn);
  Serial.println(val);
  op1=val*500;  
  Serial.println(op1);
  Temp=op1/1023;
  Serial.println("Temperatura: ");
  Serial.println(Temp);
  delay(1000);
  

}
