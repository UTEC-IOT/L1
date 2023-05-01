// definicion de pines para los semaforos
const int vehiculoRojo = 8;
const int vehiculoAmarillo = 9;
const int vehiculoVerde = 10;
const int personaRojo = 12;
const int personaVerde = 13;
const int flag = 2;

float tiempoRojo = 0;
float tiempoAmarillo = 0;
float tiempoVerde = 0;

void setup() {
  pinMode(vehiculoRojo, OUTPUT);
  pinMode(vehiculoAmarillo, OUTPUT);
  pinMode(vehiculoVerde, OUTPUT);
  pinMode(personaRojo, OUTPUT);
  pinMode(personaVerde, OUTPUT);
  pinMode(flag, INPUT);
}

void loop() {
  int dr = digitalRead(flag);
  Serial.println(dr);
  if (dr == 1) {
	tiempoRojo = 500;
	tiempoAmarillo = 0;
	tiempoVerde = 500;
  } else {
    	tiempoRojo = 55.4*1000;
	tiempoAmarillo = 3*1000;
	tiempoVerde = 45.78*1000;
  }

  // luz de vehiculo en rojo, luz de persona en verde
  digitalWrite(vehiculoAmarillo, LOW); 
  digitalWrite(vehiculoRojo, HIGH);
  digitalWrite(personaRojo, LOW);
  digitalWrite(personaVerde, HIGH); 
  delay(tiempoRojo);
  // luz de vehiculo en verde, luz de persona en rojo
  digitalWrite(vehiculoVerde, HIGH); 
  digitalWrite(vehiculoRojo, LOW);
  digitalWrite(personaRojo, HIGH);
  digitalWrite(personaVerde, LOW); 
  delay(tiempoVerde);
  // luz de vehiculo en amarillo, luz de persona en rojo
  digitalWrite(vehiculoVerde, LOW); 
  digitalWrite(vehiculoAmarillo, HIGH);
  delay(tiempoAmarillo);
}