// // ===============================
// // L298N Motor Driver - 2WD Robot
// // ===============================

// Motor A
const int ENA = 5;   // PWM
const int IN1 = 8;
const int IN2 = 9;

// Motor B
const int ENB = 6;   // PWM
const int IN3 = 10;
const int IN4 = 11;

// // ===============================

// void setup() {
//    pinMode(13, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);

//   pinMode(ENB, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);

//   stopMotors();
//  }

// // ===============================

// void loop() {

//   // Move forward
//   forward(200);
//   delay(2000);

//   // Stop
//   stopMotors();
//   delay(1000);

//   // Move backward
//   backward(200);
//   delay(2000);

//   // Stop
//   stopMotors();
//   delay(1000);

//   // Turn left
//   left(200);
//   delay(1000);

//   // Stop
//   stopMotors();
//   delay(1000);

//   // Turn right
//   right(200);
//   delay(1000);

//   // Stop
//   stopMotors();
//   delay(3000);
// }

// // ===============================
// // Movement Functions
// // ===============================

void forward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// void backward(int speed) {
//   analogWrite(ENA, speed);
//   analogWrite(ENB, speed);

//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// void left(int speed) {
//   analogWrite(ENA, speed);
//   analogWrite(ENB, speed);

//   // Left motor backward
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);

//   // Right motor forward
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// void right(int speed) {
//   analogWrite(ENA, speed);
//   analogWrite(ENB, speed);

//   // Left motor forward
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);

//   // Right motor backward
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// void stopMotors() {
//   analogWrite(ENA, 0);
//   analogWrite(ENB, 0);

//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }

const int LDR = A0;
int flag_light = 0;
int verification_light_start(int LDR)
{
  if (LDR > 100)
    return 0;
  else
    return 1;

}
void setup() {
  Serial.begin(9600);
}

void loop() {
// int value = analogRead(LDR);

//     Serial.print("Value: ");
//     Serial.print(value);

//     Serial.print(" | Light: ");

//     if (value > 100) {
//     Serial.println("YES");
//   } else {
//     Serial.println("NO");
 // }

  if (flag_light == 0)
  {
    flag_light = verification_light_start(analogRead(LDR));
  }
  else
  {
  //   int value = analogRead(LDR);

  //   Serial.print("Value: ");
  //   Serial.print(value);

  //   Serial.print(" | Light: ");

  //   if (value > 1000) {
  //   Serial.println("YES");
  // } else {
  //   Serial.println("NO");
  // }
forward(255);

  }}
