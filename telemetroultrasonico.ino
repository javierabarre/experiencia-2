/*
 Experiencia 2 telémetro ultrasonico conectado a una sola terminal SIG ,
 que cumple función trig y eco 
*/

int inches = 0;// se define variables tipo pulgadas enteras

int cm = 0;// se define variables de tipo cm enteras 
/*Función de Tipo Long significa que entrega valores de más decimales aumentando precisión */
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // se enciende  TRIG
  digitalWrite(triggerPin, LOW);// Se apaga  trig
  delayMicroseconds(2);// por dos segundos se apaga TRIG 
  
  digitalWrite(triggerPin, HIGH);// Enciende Trig por 10 milisegundos emite señal
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);// se apaga Trig 
  pinMode(echoPin, INPUT);// eco se enciende para recibir la señal reflejada
  
  return pulseIn(echoPin, HIGH);// retorna valores de distancia
}

void setup()
{
  Serial.begin(9600);// comunicación serial 9600  caracteres por segundo 

}

void loop()
{
  //medida en cm 
  ,m = 0.01723 * readUltrasonicDistance(7, 7);// la funcion definida anteriormete en terminal 7,7 es decir SIG
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  //MONITOR SERIE MUESTRA LA DISTANCIAS 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // ESPERA 100 MILISEGUN
}
