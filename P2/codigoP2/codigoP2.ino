const int pinAnalog = A0;
const int bits = 4;
const int maxNum = pow(2, bits)-1;

void setup() {
  Serial.begin(9600);

  pinMode(pinAnalog, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int lectura = analogRead(pinAnalog);
  int valorDigital = map(lectura, 0, 1023, 0, maxNum);
  float amplitud = (valorDigital*5.0)/maxNum;
  
  // vincular el pin con el bit
  digitalWrite(2, bitRead(valorDigital, 0));
  digitalWrite(3, bitRead(valorDigital, 1));
  digitalWrite(4, bitRead(valorDigital, 2));
  digitalWrite(5, bitRead(valorDigital, 3));
  
  Serial.print("valor digital = ");
  Serial.print(valorDigital);
  Serial.print(", amplitud = ");
  Serial.println(amplitud);
  delay(100);
}