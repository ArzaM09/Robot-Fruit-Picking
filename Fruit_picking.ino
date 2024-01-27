#include <Servo.h>
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
#include<TinyGPS++.h>
#include<SoftwareSerial.h>
SoftwareSerial serial_gps(11, 10);
TinyGPSPlus gps;
double latitude, longitude;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");
}

void loop() {
  // put your main code here, to run repeatedly:
   while(serial_gps.available()) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    String link = "www.google.com/maps/place/" + String(latitude,6) + "," + String(longitude,7) ;
    Serial.println(link);
    delay(1000);
  }
  if (Serial.available()>0){
    String direction = Serial.readString();
    Serial.println(direction);
    if (direction == "M"){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if(direction == "A"){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4, HIGH);
    }
    else if(direction =="L"){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4, HIGH);
    }
    else if(direction =="R"){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if(direction =="S"){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,HIGH);
    }
    else if(direction =="P"){
      servo1.write(0);
    }
    else if(direction =="Q"){
      servo1.write(90);
    }
    else if(direction =="V"){
      servo1.write(180);
    }
    else if(direction =="T"){
      servo1.write(360);
    }
    else if(direction =="U"){
      servo2.write(180);
    }
    else if(direction =="Y"){
      servo2.write(80);
    }
    else if(direction =="J"){
      servo3.write(90);
    }
    else if(direction =="K"){
      servo3.write(40);
    }
        else if(direction =="Z"){
      servo4.write(180);
    }
    else if(direction =="B"){
      servo4.write(0);
    }
  }
}
