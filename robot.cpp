// ======================================
// SIMPLE LINE FOLLOWER
// ======================================

// ---------- MOTOR PINS ----------
const int ENA =6;
const int IN1 = 7;
const int IN2 = 2;

const int ENB = 5;
const int IN3 = 3;
const int IN4 = 4;

// ---------- SENSOR PINS ----------
const int SR = A5;   // Left sensor
const int SL = A2;   // Right sensor
const int SF1 = A4;
const int SF2 = A3;





// ======================================

void setup()
{
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    Serial.begin(9600);
}

// ======================================

void forward(int speed)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}
void stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, 0);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, 0);

}

void turnLeft(int speed)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

void turnRight(int speed)
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

// ===
//===================================

void loop()
{
    int left = analogRead(SL);
    int right = analogRead(SR);
    int front1 = analogRead(SF1);
    int front2 = analogRead(SF2);
    if ((front1 < 50 || front2 < 50) && left < 50 && right > 50)
    {
        turnRight(150);
    }
    if ((front1 > 50 || front2 > 50) && left < 50 && right < 50)
    {
        forward(150);
    }
    if ((front1 < 50 || front2 < 50) && left > 50 && right < 50 )
    {
        turnLeft(150);
    }


}
