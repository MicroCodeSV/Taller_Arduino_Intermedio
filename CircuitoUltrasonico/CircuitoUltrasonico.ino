/*Aprenderemos a como instalar una libreria en Arduino en este caso instalaremos la NewPing.h
 * la cual es necesaria para poder trabajar con el sensor ultrasonico HS-R04.
 * 
 * La descargaremos directamentamente del playground de Arduino
 * http://playground.arduino.cc/Code/NewPing
 */
#include <NewPing.h>
 
//Aqui se configuran los pines donde debemos conectar el sensor
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
 
//Crear el objeto de la clase NewPing
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Declaración de pines; r=Rojo, g=Verde, b=Azul)
int r=2,g=3,b=4;
 
void setup() {
//inicialización de LEDes
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

//Boudios del monitor serial 
  Serial.begin(9600);
}
 
void loop() {
delay(50); // Esperar 1 segundo entre mediciones
// Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
int uS = sonar.ping_median();
// Calcular la distancia con base en una constante
int cm = (uS / US_ROUNDTRIP_CM);
 
  //menor_a_mayor(cm);
  //mayor_a_menor(cm);
  monitorSerial(cm);
}

void menor_a_mayor(int d) {
  int Tiempo = 500;
  
  if(d < 10){
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);

  delay(Tiempo);
  }
  else if(d < 20){
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);

  delay(Tiempo); 
  }
  else {
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);

  delay(Tiempo);
  }
}

void mayor_a_menor(int dist) {
  int Tiempo = 50;
  
  if(dist > 20){
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);

  delay(Tiempo);
  }
  else if(dist > 10){
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);

  delay(Tiempo); 
  }
  else {
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);

  delay(Tiempo);
  }
}

void monitorSerial(int dist){
  // Imprimir la distancia medida a la consola serial
  Serial.print(dist);
  Serial.println("cm");
  delay(10); // Esperar 1 segundo entre mediciones

  menor_a_mayor(dist);
}

