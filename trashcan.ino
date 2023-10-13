#include <Servo.h>

const int trigPin = 3;  // Trig pin of the ultrasonic sensor
const int echoPin = 2; // Echo pin of the ultrasonic sensor
const int servoPin = 5; // Servo control pin

Servo lidServo; // Create a Servo object

void setup() {
  Serial.begin(9600);
  lidServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert the time into distance in cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if an object is within a certain range (adjust as needed)
  if (distance < 10) { // Adjust this value to suit your setup
    openLid();
    delay(3000); // Keep the lid open for 5 seconds (adjust as needed)
    closeLid();
  }
}

void openLid() {
  lidServo.write(80); // Open the lid (adjust the angle as needed)
}

void closeLid() {
  lidServo.write(0); // Close the lid (adjust the angle as needed)
}
