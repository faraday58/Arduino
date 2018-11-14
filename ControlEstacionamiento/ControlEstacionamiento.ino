//Variable para controlar Luz
int Luz=12;
int LED=13;
//Variable para captura estado de la Luz
volatile char cluz;


//Sensor de Temperatura
// 0 - 5000 mV  10 mV/C
// analogRead()  0-1023
// Temp= (5000/10)*analogRead()/1023  [C]
//float Temp=0;   //float, int 16 bits
long Temp=0 ; //long y double 32 bits
//Entrada analógica
int AnalogIn=0;

void setup() {
  // put your setup code here, to run once:  
  pinMode(Luz,OUTPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(2),Mensaje,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
     
     Temperatura();
    
}


void serialEvent(){
  // available: Verifica que existan datos en el buffer del puerto serie
  if( Serial.available() > 0 )
    {
      //read: Devuelve un byte o un Char
     cluz = Serial.read();
    //Control del encendido de la luz
      switch(cluz)
      {
        case 'e':
        digitalWrite(Luz,HIGH);
        break;
        case 'a':
        digitalWrite(Luz,LOW);
        break;
      }
      
    } 
    
  }

void Mensaje()
{
   
   digitalWrite(Luz,LOW);
   
}
  


void Temperatura()
{
     //Enviando Información de la Temperatura ambiente
     Temp= analogRead(AnalogIn)*500.0/1023.0;
      Serial.write(Temp);
    //println() es para enviar datos al monitor de Arduino
    //Serial.println(Temp);
    delay(1000); 
    
}
