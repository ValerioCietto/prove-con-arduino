/*************************************************************
Motor Shield 2-Channel DC Motor Demo
by Randy Sarafan

For more information see:
http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  Serial.begin(9600);
  
}

void loop(){

  if(Serial.available()){
      char msg = (char)Serial.read(); //read next character, and removes it from the queue
      char next = (char)Serial.peek(); //looks for next character, but doesn't eliminate it from the queue
      if(msg=='d'){ //the characters have been choosen randomly
          Serial.println(msg);
          goForwardA();
      }
      else if(msg=='a'){
          Serial.println(msg);
          goBackwardA();
      }
      else if(msg=='q'){
          Serial.println(msg);
          goBackwardB();
      }
      else if(msg=='e'){
          Serial.println(msg);
          goBackwardB();
      }
  }
  
}

void goForwardA(){
  //Motor A forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  delay(500);
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 0);   //Spins the motor on Channel A at full speed
  
}

void goBackwardA(){
  digitalWrite(12, LOW); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  delay(500);
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 0);   //Spins the motor on Channel A at full speed
  
}  

void goForwardB(){
  //Motor A forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel A
  analogWrite(11, 255);   //Spins the motor on Channel A at full speed
  delay(100);
  digitalWrite(13, HIGH); //Establishes forward direction of Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel A
  analogWrite(11, 0);   //Spins the motor on Channel A at full speed
  
}

void goBackwardB(){
  digitalWrite(13, LOW); //Establishes backward direction of Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel A
  analogWrite(11, 255);   //Spins the motor on Channel A at full speed
  delay(100);
  digitalWrite(13, HIGH); //Establishes backward direction of Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel A
  analogWrite(11, 0);   //Spins the motor on Channel A at full speed
  
}
