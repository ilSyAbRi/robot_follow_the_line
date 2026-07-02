// ======================================
// SIMPLE LINE FOLLOWER
// ======================================

// ---------- MOTOR PINS ----------
const int ENA = 5;
const int IN1 = 2;
const int IN2 = 3;

const int ENB = 6;
const int IN3 = 4;
const int IN4 = 7;

// ---------- SENSOR PINS ----------
const int S2 = A5;   // Left sensor
const int S3 = A0;   // Right sensor

// ---------- SETTINGS ----------
const int THRESHOLD = 50;

const int FORWARD_SPEED = 255;
const int TURN_SPEED = 150;
const int STOP_SPEED = 0;

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

void forward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, FORWARD_SPEED);
    analogWrite(ENB, FORWARD_SPEED);
}

void turnLeft()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, STOP_SPEED);
    analogWrite(ENB, TURN_SPEED);
}

void turnRight()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, TURN_SPEED);
    analogWrite(ENB, STOP_SPEED);
}

// ======================================

void loop()
{
    int left = analogRead(S2);
    int right = analogRead(S3);

    Serial.print(left);
    Serial.print("  ");
    Serial.println(right);

    // Both sensors on white
    if (left < THRESHOLD && right < THRESHOLD)
    {
        Serial.println("both white go forward");
        forward();
    }

    // Left sensor on black
    else if (left < THRESHOLD && right > THRESHOLD)
    {
        Serial.println("it s right GO right");
        turnRight();      // Swap with turnLeft() if needed
    }

    // Right sensor on black
    else if (right < THRESHOLD && left > THRESHOLD)
    {
        Serial.println("it s left GO LEFTH");
        turnLeft();       // Swap with turnRight() if needed
    }

    // Both sensors on black
    else
    {
        Serial.println("BOTH BLACK go forward ");
        forward();
    }

}
