#include <AFMotor.h>

// --- CALIBRATION SETTINGS ---
#define SPEED_VAL 70       // Speed (0-255). Higher speed = faster turn.
#define TURN_90_TIME 1000    // <--- ADJUST THIS NUMBER. 
                            // Start with 850. If it turns too much, lower it.
                            // If it turns too little, increase it.

AF_DCMotor M2(2); // Left Motor
AF_DCMotor M3(3); // Right Motor

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(7); 
  setAllSpeeds(SPEED_VAL); 
  Stop();
}

void loop() {
  bluetoothControl();
}

// --- Helper Function ---
void setAllSpeeds(int s) {
  M2.setSpeed(s);
  M3.setSpeed(s);
}

void bluetoothControl() {
  if (Serial.available() > 0) {
    String value = Serial.readString();
    value.trim(); 

    if (value == "forward") {
      forward();
    } else if (value == "backward" || value == "back") {
      backward();
    } else if (value == "left" || value == "lift") { 
      turnLeft90();
    } else if (value == "right") {
      turnRight90();
    } else if (value == "stop") {
      Stop();
    }
  }
}

/****************** Motor functions *****************/
void forward() {
  setAllSpeeds(SPEED_VAL);
  M2.run(FORWARD);
  M3.run(FORWARD);
}

void backward() {
  setAllSpeeds(SPEED_VAL);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
}

// --- 90 DEGREE TURN LOGIC ---

void turnRight90() {
  setAllSpeeds(SPEED_VAL);
  
  // Pivot Turn: Left moves, Right stops
  M2.run(FORWARD); 
  M3.run(RELEASE); 
  
  delay(TURN_90_TIME); // Wait for the robot to reach 90 degrees
  
  Stop(); // Automatically stop after the time is up
}

void turnLeft90() {
  setAllSpeeds(SPEED_VAL);
  
  // Pivot Turn: Right moves, Left stops
  M2.run(RELEASE); 
  M3.run(FORWARD); 
  
  delay(TURN_90_TIME); // Wait for the robot to reach 90 degrees
  
  Stop(); // Automatically stop after the time is up
}

void Stop() {
  M2.run(RELEASE);
  M3.run(RELEASE);
}