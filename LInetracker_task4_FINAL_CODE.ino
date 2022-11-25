
//Line Tracking IO define
#define LT_R !digitalRead(12)
#define LT_M !digitalRead(13)
#define LT_L !digitalRead(11)

#define ENA 9
#define ENB 10
#define IN1 4
#define IN2 5
#define IN3 7
#define IN4 6


#define carSpeed 110
//int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}

void left() {
  
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go left!");
}

void right() {
  
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("go right!");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}



void setup() {
  Serial.begin(9600);
  pinMode(LT_R, INPUT);
  pinMode(LT_M, INPUT);
  pinMode(LT_L, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}

void loop() {

  if (LT_M) {
    forward();
    Serial.println("forward");
  }
  else if (LT_L) {
    right();
     while (LT_L);
    Serial.println("right");
  
  }
  else if (LT_R) {
    left();
    Serial.println("Left");
     while (LT_R);
  }
  else{
      analogWrite(ENA, 50);
    analogWrite(ENB, 50);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
//stop();
  }

//Serial.print(LT_R);
//Serial.print(LT_M);
//Serial.println(LT_L);

//delay(500);


  
}
