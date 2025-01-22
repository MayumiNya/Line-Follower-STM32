//3 analog sensor
int enA = PA6;//Enable1 L293 Pin enA 
int in1 = PA7; //Motor1  L293 Pin in1 
int in2 = PB0; //Motor1  L293 Pin in1 
int in3 = PB1; //Motor2  L293 Pin in1 
int in4 = PA8; //Motor2  L293 Pin in1 
int enB = PB6; //Enable2 L293 Pin enB 

void setup(){ 
  pinMode(PA2, INPUT_ANALOG); 
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA3, INPUT_ANALOG); 
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 
  pinMode(enB, OUTPUT);
  // pinMode(PC13, OUTPUT);
  digitalWrite(enA, HIGH); 
  digitalWrite(enB, HIGH); 

  // digitalWrite(PC13, HIGH);
  // delay(100);
  // digitalWrite(PC13, LOW);
  // delay(50);
  // digitalWrite(PC13, HIGH);
  // delay(100);
  // digitalWrite(PC13, LOW);
  delay(1000);
}

void loop(){  
  if((analogRead(PA2) <= 1000)&&(analogRead(PA4) <= 1000)){forward();}
  if(analogRead(PA3) >= 1300){forward();}
  if((analogRead(PA2) < 1300)&&(analogRead(PA4) > 1300)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
  if((analogRead(PA2) > 1300)&&(analogRead(PA4) < 1300)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
  if((analogRead(PA2) < 1300)&&(analogRead(PA4) < 1300)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function
}

void forward(){  //forword
	analogWrite(enA, 150);
	analogWrite(enB, 150);
  digitalWrite(in1, HIGH); //Right Motor forword Pin 
  digitalWrite(in2, LOW);  //Right Motor backword Pin 
  digitalWrite(in3, LOW);  //Left Motor backword Pin 
  digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void turnRight(){ //turnRight
	analogWrite(enA, 90);
	analogWrite(enB, 90);
  digitalWrite(in1, HIGH); //Right Motor forword Pin 
  digitalWrite(in2, LOW);  //Right Motor backword Pin 
  digitalWrite(in3, HIGH); //Left Motor backword Pin 
  digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void turnLeft(){ //turnLeft
	analogWrite(enA, 90);
	analogWrite(enB, 90);
  digitalWrite(in1, LOW);  //Right Motor forword Pin 
  digitalWrite(in2, HIGH); //Right Motor backword Pin  
  digitalWrite(in3, LOW);  //Left Motor backword Pin 
  digitalWrite(in4, HIGH); //Left Motor forword Pin 
}

void Stop(){ //stop
  digitalWrite(in1, LOW); //Right Motor forword Pin 
  digitalWrite(in2, LOW); //Right Motor backword Pin 
  digitalWrite(in3, LOW); //Left Motor backword Pin 
  digitalWrite(in4, LOW); //Left Motor forword Pin 
}
