// ======================================
// SIMPLE LINE FOLLOWER
// ======================================

// -------- MOTOR PINS --------
const int ENA = 5;
const int IN1 = 2;
const int IN2 = 3;

const int ENB = 6;
const int IN3 = 4;
const int IN4 = 7;

// -------- SENSOR PINS --------
const int S2 = A0;  
const int S3 = A1;

// -------- SETTINGS --------
const int THRESHOLD = 500;

const int BASE_SPEED = 150;
const int CORRECTION = 40;

// ======================================

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    Serial.begin(9600);

    // Motors always move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// ======================================

void loop()
{
    int leftValue  = analogRead(S2);
    int rightValue = analogRead(S3);

    bool leftBlack  = leftValue < THRESHOLD;
    bool rightBlack = rightValue < THRESHOLD;

    // Default speed
    int leftMotor  = BASE_SPEED;
    int rightMotor = BASE_SPEED;

    // -----------------------------
    // Normal state
    // Both sensors see white
    // -----------------------------
    if (!leftBlack && !rightBlack)
    {
        // Keep going
    }

    // -----------------------------
    // Robot moved left
    // S2 sees black
    // Turn right a little
    // -----------------------------
    else if (leftBlack && !rightBlack)
    {
        leftMotor  += CORRECTION;
        rightMotor -= CORRECTION;
    }

    // -----------------------------
    // Robot moved right
    // S3 sees black
    // Turn left a little
    // -----------------------------
    else if (!leftBlack && rightBlack)
    {
        leftMotor  -= CORRECTION;
        rightMotor += CORRECTION;
    }

    // -----------------------------
    // Both black
    // Ignore for now
    // -----------------------------
    else
    {
        // We'll use this later for intersections.
    }

    // Send speeds to motors
    analogWrite(ENA, leftMotor);
    analogWrite(ENB, rightMotor);

    // Debug
    Serial.print("S2: ");
    Serial.print(leftValue);

    Serial.print("   S3: ");
    Serial.println(rightValue);

    delay(5);
}
