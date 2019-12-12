//NOTA: Si se borran estos dos no jala nada no borrar UwU
double contenedorLleno;
double contenedorVacio;

double pinSensorProfundidad=23;
double SensorProfundidadValor;

int limiteContador;

int ValvulaEntrada=6;
int ValvulaSalida=11; 

int pinFoquitoRojo;

bool GallinAuto;

//MUCHAS VARIABLES PAL WIFI

//valores
//pin4 = 6 entrada
//pin5=11 valvula salida
//A0=23 sensores

void setup() {
pinMode(pinSensorProfundidad, INPUT);
pinMode(ValvulaEntrada, OUTPUT);
pinMode(ValvulaSalida, OUTPUT);
pinMode(pinFoquitoRojo, OUTPUT);
}

void loop() {
  // Es un while infinito que hace que jale bien el programa 
  SensorProfundidadValor =analogRead(pinSensorProfundidad);
  Gallina(ReciveGallinaRemota());
}

bool Purga(){
  digitalWrite(pinFoquitoRojo, HIGH); 
  int contador=0;
  while(SensorProfundidadValor>contenedorVacio){
    SensorProfundidadValor =analogRead(pinSensorProfundidad);
    if(contador==0){
        digitalWrite(ValvulaSalida, HIGH);
        }
        contador++;
        if(contador>limiteContador){
          break;
          }
    }
    digitalWrite(ValvulaEntrada, HIGH);

    delay(1000);
    digitalWrite(ValvulaEntrada, LOW);
    digitalWrite(ValvulaSalida, LOW);
    return true;
    digitalWrite(pinFoquitoRojo, LOW);  
  }

  
  bool Llena(){
    digitalWrite(pinFoquitoRojo, HIGH); 
  int contador=0;
  while(SensorProfundidadValor<contenedorLleno){
    SensorProfundidadValor =analogRead(pinSensorProfundidad);
    if(contador==0){
      digitalWrite(ValvulaEntrada, HIGH);
        }
        contador++;
        if(contador>limiteContador){
          break;
          }
    }
    digitalWrite(ValvulaEntrada, LOW);
    digitalWrite(pinFoquitoRojo, LOW); 
    }
    
    bool Gallina(int entrada){
      switch(entrada){
        case -1:
        //NO HACER NADA
        break;
        case 1:
        if(Purga()){return Llena();} 
        break;
        case 2:
        return Llena(); 
        break;
        case 3:
        GallinAuto = !GallinAuto; 
        return true;
        break;
        case 4:
        EnviaGallinaRemota(nivelSensor());//PARA EL WIFI AUN NO ESTA ESCRITO 
        break;
        }
 }
 double nivelSensor()
 {
 double resu;
 resu=(analogRead(pinSensorProfundidad)*100.00)/contenedorLleno; 
 }
 bool EnviaGallinaRemota(double entrada){
  return false;
  //HAY QUE ESCRIBIR EL METODO
  }
   int ReciveGallinaRemota(){
  return false;
  //HAY QUE ESCRIBIR EL METODO
  }
