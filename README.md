# Ultrasonic Sensor & Servo-Controlled Lid Project

This Arduino project uses an ultrasonic sensor to detect nearby objects. When an object is within a certain distance, the program controls a servo motor to open a lid and close it after a set time.

## Components

- **Arduino Board** (e.g., Uno, Nano)
- **Ultrasonic Sensor** (HC-SR04 or compatible)
- **Servo Motor**
- Jumper wires
- Breadboard (optional)

## Circuit Connections

1. **Ultrasonic Sensor:**
   - **VCC**: Connect to 5V on the Arduino.
   - **GND**: Connect to GND on the Arduino.
   - **Trig Pin**: Connect to digital pin `3` on the Arduino.
   - **Echo Pin**: Connect to digital pin `2` on the Arduino.

2. **Servo Motor:**
   - **Control Pin**: Connect to digital pin `5` on the Arduino.
   - **Power**: Connect to 5V.
   - **GND**: Connect to GND on the Arduino.

## Code Explanation

The code is structured in two main parts:
1. **Distance Measurement**: Using the ultrasonic sensor to calculate the distance to an object.
2. **Servo Control**: Moving the servo to open or close a lid based on the distance.

### Setup
- The `setup()` function initializes the serial connection, attaches the servo, and sets the pins for the ultrasonic sensor.

### Loop
1. The `loop()` function continuously measures the distance by sending a trigger pulse and waiting for the echo pulse.
2. It converts the pulse duration into distance in centimeters.
3. If the detected distance is less than a set threshold (e.g., 10 cm), it opens the lid, waits for 3 seconds, and then closes it.

### Functions
- **`openLid()`**: Moves the servo to the specified angle to open the lid.
- **`closeLid()`**: Moves the servo to close the lid.

### Adjustments
- Modify `distance < 10` to set the trigger distance.
- Change the `delay(3000)` to adjust how long the lid stays open.
- Adjust the servo angles in `openLid()` and `closeLid()` as needed.

## Example Usage

- The program opens the lid when an object is within 10 cm, keeps it open for 3 seconds, and then closes it.

## Troubleshooting

- If the servo doesn’t move, check the connections and ensure the power supply can handle the servo motor's requirements.
- Verify the ultrasonic sensor connections if no distance is displayed in the Serial Monitor.
