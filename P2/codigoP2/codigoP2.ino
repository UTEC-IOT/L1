// definicion de pines para los semaforos
const int vehiculoRojo = 8;
const int vehiculoAmarillo = 9;
const int vehiculoVerde = 10;
const int personaRojo = 12;
const int personaVerde = 13;

// definicion de tiempos de espera, semaforo de vehiculos como referencia
const int tiempoRojo = 55.4*1000;
const int tiempoAmarillo = 3*1000;
const int tiempoVerde = 45.78*1000;

void setup() {
  pinMode(vehiculoRojo, OUTPUT);
  pinMode(vehiculoAmarillo, OUTPUT);
  pinMode(vehiculoVerde, OUTPUT);
  pinMode(personaRojo, OUTPUT);
  pinMode(personaVerde, OUTPUT);
}

void loop() {
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