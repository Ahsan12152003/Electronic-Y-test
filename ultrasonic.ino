#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG1 2
#define ECHO1 3
#define TRIG2 4
#define ECHO2 5
#define TRIG3 6
#define ECHO3 7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT);
    pinMode(ECHO2, INPUT);
    pinMode(TRIG3, OUTPUT);
    pinMode(ECHO3, INPUT);
}

long getDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    return duration * 0.034 / 2; // Convert to cm
}

void loop() {
    long distance1 = getDistance(TRIG1, ECHO1);
    long distance2 = getDistance(TRIG2, ECHO2);
    long distance3 = getDistance(TRIG3, ECHO3);
    
    Serial.print("Sensor 1: ");
    Serial.print(distance1);
    Serial.print(" cm	 Sensor 2: ");
    Serial.print(distance2);
    Serial.print(" cm	 Sensor 3: ");
    Serial.print(distance3);
    Serial.println(" cm");
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S1:");
    lcd.print(distance1);
    lcd.print("cm");
    lcd.setCursor(0, 1);
    lcd.print("S2:");
    lcd.print(distance2);
    lcd.print("cm S3:");
    lcd.print(distance3);
    lcd.print("cm");
    
    delay(500);
}