byte Recieve;
void setup() {
Serial.begin(115200);
  pinMode(4, OUTPUT);
//  Serial.println("DATA PACKET RECIEVED MODE PHOENIX ONLINE");
  Serial.print("AT+CIPMUX=1"+'\n'+'\r');
  Serial.print("AAT+CIPSERVER=1,80"+'\n'+'\r');
  Serial.print("AT+CIFSR"+'\n'+'\r'); 
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    Recieve = Serial.read();

    // say what you got:
//Serial.print("I received: ");
    Serial.println(Recieve, DEC);
  if(Recieve == 57)
   {
      Serial.print("AT+CIPMUX=1"+'\n'+'\r');
  Serial.print("AAT+CIPSERVER=1,80"+'\n'+'\r');
  Serial.print("AT+CIFSR"+'\n'+'\r');
    }
   if(Recieve == 49)
   {
     // Serial.println("DATA PACKET RECIEVED MODE PHOENIX ONLINE");
      digitalWrite(4, HIGH); // sets the digital pin 13 on
    }
       if(Recieve == 50)
   {
  //    Serial.println("DATA PACKET RECIEVED MODE PHOENIX ONLINE");
      digitalWrite(4, LOW); // sets the digital pin 13 on
    }
  }
 }

 void TurnOnLed()
 {
  
  }
