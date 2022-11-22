#include <PID_v1.h>
#include "Wire.h"
#include <MPU6050_light.h>

#define ENA 9
#define ENB 10
#define IN1 4
#define IN2 5
#define IN3 7
#define IN4 6

#define carSpeed 90


double Kp=500, Ki=300, Kd=0.01;

double Setpoint, Input, Output, Zangle, angle,ZValue;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

 MPU6050 mpu(Wire);
 unsigned long timer = 0;

void setup() {

//Serial.begin(9600);
myPID.SetMode(AUTOMATIC);
//Setpoint = 150;
Serial.begin(9600);
   Wire.begin();
 byte status = mpu.begin();
   Serial.print(F("MPU6050 status: "));
   Serial.println(status);
   while (status != 0) { } // stop everything if could not connect to MPU6050
 Serial.println(F("Calculating offsets, do not move MPU6050"));
   delay(1000);
   mpu.calcOffsets(); // gyro and accelero
   Serial.println("Done!\n");

myPID.SetOutputLimits(-255, 255);
  Zangle = mpu.getAngleZ();
  Setpoint = 0;
}
void loop() {
  // put your main code here, to run repeatedly:
  mpu.update();
  Zangle = mpu.getAngleZ();
  Serial.print(Input);
  Serial.print(" ");
  Serial.print(Setpoint);
  Serial.print(" ");
  Serial.print(Output);
  Serial.print(" ");
  Serial.print(Zangle);
  Serial.print(" ");
  Serial.print(ZValue);
  Serial.print(" ");
   Serial.print(carSpeed);
  Serial.print(" ");
 // Serial.print(Forward);
 // Serial.print(" ");
  //Serial.print(Backward);
  //Serial.print(" ");
  Serial.println();

 ZValue = map(Zangle, -180, 180, -200, 200) ;
  Input = Zangle;
//int right =  map(Output, 0, 255, 0, 200);
//int left = map(Output, -255,0,200,0);
  myPID.Compute();

     if(Output > 5)//move right

      {
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   

      }
    else if(Output<-5)//move left

   {
     analogWrite(ENA, 200);
     analogWrite(ENB, 200);
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);

 }
else

 {
     Serial.println("Forward");
     analogWrite(ENA, 200);
     analogWrite(ENB, 200);
     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);

  

  }
}
