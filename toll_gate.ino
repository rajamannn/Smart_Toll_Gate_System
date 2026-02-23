#include <Servo.h>

#define trigPin 7
#define echoPin 6
#define buzzer 9
#define red 10
#define yellow 11
#define green 12
#define servoPin 5

Servo gateServo;
unsigned long previousMillis = 0; // Timer for traffic lights
const long lightInterval = 5000;  // 5 sec per light

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

    gateServo.attach(servoPin);
    gateServo.write(0);  // Gate starts closed

    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;

    // Measure distance using Ultrasonic Sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
    distance = duration * 0.034 / 2; // Convert time to distance

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If an object is detected (within 10 cm)
    if (distance < 10) {  
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);

        // Open the gate
        gateServo.write(90); // Gate opens

        // Beep while the object is present
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(500);

    } else if (digitalRead(red) == HIGH) {
        // When object moves away, beep once and close the gate
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);

        gateServo.write(0); // Close the gate
    }

    // 🚦 Traffic light system using millis() instead of delay()
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= lightInterval) {
        previousMillis = currentMillis; // Reset timer

        // Change lights
        if (digitalRead(green) == HIGH) {
            digitalWrite(green, LOW);
            digitalWrite(yellow, HIGH);
        } else if (digitalRead(yellow) == HIGH) {
            digitalWrite(yellow, LOW);
            digitalWrite(red, HIGH);
        } else {
            digitalWrite(red, LOW);
            digitalWrite(green, HIGH);
        }
    }
}
