#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial mySerial(10, 11); // RX, TX

char data;

void setup() {
 
  Serial.begin(9600);
  while (Serial) {
    ; 
  }
  
  mySerial.begin(9600);
  myservo.attach(9);
  myservo.write(90);
  delay(100);
}

void loop() { 
  if (mySerial.available()) 
  {
    data = mySerial.read();
  }
  switch(data)
  {
    case '1':myservo.write(60);
            break;
    case '2':myservo.write(120);
            break;
    default:myservo.write(90);  
  }
  delay(10);
}
