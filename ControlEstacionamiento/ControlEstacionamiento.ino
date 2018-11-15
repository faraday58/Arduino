//Control de Motor
int sw1=7;
int sw2=8;
char dato;

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
bool control=true;
long Temp=0 ; //long y double 32 bits
//Entrada analógica
int AnalogIn=0;

void setup() {
  // put your setup code here, to run once:  
  pinMode(Luz,OUTPUT);
  pinMode(LED,OUTPUT);
  //Configurar Pines para control del motor
  pinMode(sw1,OUTPUT);
  pinMode(sw2,OUTPUT);
  Serial.begin(9600);
  //Interrupción en caso de entrar automóvil
   attachInterrupt(digitalPinToInterrupt(2),detenerMotor,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
     if(control == true)
     {
     Temperatura();
     }    
}


void ControlMotor()
{
  
     digitalWrite(sw1,LOW);
     digitalWrite(sw2,HIGH);
     delay(200);
     digitalWrite(sw1,LOW);
     digitalWrite(sw2,LOW);
     delay(2500);
     digitalWrite(sw1,HIGH);
     digitalWrite(sw2,LOW);
     delay(200);
     digitalWrite(sw1,LOW);
     digitalWrite(sw2,LOW);
  
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
        case 'o':
        Serial.write("Iniciando  Motor");
        control=true;
        ControlMotor();
        break;
      }
      
    } 
    
  }

void detenerMotor()
{
/*   digitalWrite(sw1,LOW);
   digitalWrite(sw2,LOW);
   delay(2000);
   */
   control = false;
    digitalWrite(Luz,HIGH);  
   
   
   
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
