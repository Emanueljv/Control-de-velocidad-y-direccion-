int velocidad=0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT); 
}  
void loop() {
    Serial.println("Escriba la velocidad entre -255 y 255: ");
    delay(1000);
  
    if (Serial.available() > 0) {
      delay(20);
      String bufferString = "";
      while (Serial.available() > 0) {
      bufferString += (char)Serial.read(); 
      velocidad = bufferString.toInt();
      }
      if (velocidad >= -255 && velocidad <= 255 ){
          if (velocidad >= 0){
            Serial.print("Moviendo a ");
            Serial.println(velocidad); 
            digitalWrite(9, HIGH);       
            digitalWrite(10, LOW);    
            analogWrite(5,velocidad);  //PWM
            velocidad=0;
            delay(200);
          }
          else if (velocidad < 0){
            Serial.print("Moviendo a ");
            Serial.println(velocidad); 
            velocidad = velocidad * (-1);
            digitalWrite(9, LOW);       
            digitalWrite(10, HIGH); 
            analogWrite(5,velocidad);  //PWM
            velocidad=0;
            delay(200);
          }  
    }
      else {
            Serial.println(" 'ERROR'  Ingrese una velocidad dentro del rango: ");
            velocidad=0;
            delay(1000);
             }   
    }
}
