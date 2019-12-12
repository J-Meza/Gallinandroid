#include <SoftwareSerial.h>

#define DEBUG true

SoftwareSerial modulo(2, 3); // Pin 2 receptor, Pin 3 transmisor
String message;

bool GallinaBandera;

void setup()
{
  Serial.begin(115200);
  modulo.begin(115200); // velocidad de transmisión podria ser diferente aunque genralmente es la que usa el el modulo modulo

  pinMode(10, OUTPUT); //configuramos los pines como salidas
  digitalWrite(10, LOW);

  pinMode(11, OUTPUT); //configuramos los pines como salidas
  digitalWrite(11, LOW);

  pinMode(12, OUTPUT); //configuramos los pines como salidas
  digitalWrite(12, LOW);

  pinMode(13, OUTPUT); //configuramos los pines como salidas
  digitalWrite(13, LOW);
  //delay(4000);
  String response;
 response= sendData("AT+RST\r\n", 2000, DEBUG); // resetea el  modulo
 if(response=="\r\nERROR"){    Serial.print("Method failure");}
   delay(2000);
  response=sendData("AT+CWMODE=3\r\n", 2000, DEBUG); // configure el modulo con AP y Estación al mismo tiempo
   delay(100);
  response=sendData("AT+CWJAP=\"HITOMI-MEZA\",\"12345678\"\r\n", 1000, DEBUG); // cambiar estos datos por los de tu red
  delay(8000);
  response=sendData("AT+CIPMUX=1\r\n", 2000, DEBUG); // Configura multiples coneciones
  delay(2000);
  response=sendData("\r\n", 2000, DEBUG); // Inicializa el servidor web
  delay(500);
  response=sendData("AT+CIPSERVER=1,80\r\n", 2000, DEBUG); // Inicializa el servidor web
}

void loop()
{
  if (Serial.available() > 0)
  {
    message = Recieve();
    sendData(message + "\r\n", 10000, DEBUG);
  }
  /*if (modulo.available())
    Serial.write(modulo.read());*/
  if (modulo.available()) {
    GetComand();
  }
}
bool GetComand()
{
delay(1000); //Espera un segundo para leer todos los datos del puerto serie
int connectionId = modulo.read()-48; 
         modulo.find("CMD+"); // avanza el cursor a "sal="
     int pinNumber = (modulo.read()-48)*10; // conseguir primer número, si el pin es 13, entonces el primer número es 1, entonces se multiplican para obtener 10
     pinNumber += (modulo.read()-48); // consegue el segundo número, si el número de pin es 13, entonces el segundo número es 3, a continuación, le añade al primero
     if( pinNumber == 10){
      digitalWrite(pinNumber, !digitalRead(pinNumber));
      delay(10000);
     }
     digitalWrite(pinNumber, !digitalRead(pinNumber));    
  }
String Recieve()
{
  String localMensaje = "";
  localMensaje += Serial.readString();
  //Serial.write("hello");
  char writen[localMensaje.length()];
  localMensaje.toCharArray(writen, localMensaje.length());
  //Serial.write(writen);
  return localMensaje;
}
String Recieve2()
{
  String cadena = "";
  long int time = millis();

  while ( (time + 10000) > millis())
    while (modulo.available())
    {

      // Muestra los Datos de salida del modulo por el seguimiento de la serie
      char c = modulo.read(); //Lee el proximo caracter
      cadena += c;
      if (c == '\0') 
      {
        break;
        break;
      }
    }

  if (true)
  {
    Serial.print(cadena);
  }
}
String sendData(String command, const int timeout, boolean debug)
{
  String cadena = "";

  modulo.print(command); // enviar el carácter leído al modulo

  long int time = millis();

  while ( (time + timeout) > millis())
    //{
    while (modulo.available())
    {

      // Muestra los Datos de salida del modulo por el seguimiento de la serie
      char c = modulo.read(); //Lee el proximo caracter
      //        Serial.print(modulo.read);
      cadena += c;
      if (c == '\0') {
        break;
      }
      // if(c == '\r'){break;}

    }

  if (true)
  {
    Serial.print(cadena);
  }

  return cadena;
}
