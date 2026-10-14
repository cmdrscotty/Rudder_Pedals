/*
 * Rudder Pedal System Firmware
 * Copyright (c) 2026 Kenneth "Cmdr_Scotty" Walters
 * 
 * Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International.
 * See LICENSE file in project root for full details.
 * Commercial use prohibited without prior permission.
 */


#include <Joystick.h>

// Define Analog Pins for the 49E Hall Effect Sensors
#define PIN_RUDDER_YAW A0  // Center Rudder axis (North/South swing)
#define PIN_LEFT_BRAKE A1  // Left toe brake (South only)
#define PIN_RIGHT_BRAKE A2 // Right toe brake (South only)

// TARGET CALIBRATION VALUES
// Run the code, open your Arduino Serial Monitor at 9600 baud, 
// move the pedals to their mechanical limits, and update these numbers.
const int YAW_MIN = 200;    // Raw analog reading at full Left Rudder
const int YAW_MAX = 820;    // Raw analog reading at full Right Rudder

const int L_BRAKE_REST = 512; // Raw reading when foot is OFF the left pedal
const int L_BRAKE_MAX  = 950; // Raw reading when left pedal is FULLY DEPRESSED

const int R_BRAKE_REST = 512; // Raw reading when foot is OFF the right pedal
const int R_BRAKE_MAX  = 950; // Raw reading when right pedal is FULLY DEPRESSED

// Initialize Joystick Object optimized for Joystick Gremlin
// Using generic X, Y, and Z axes to keep vJoy mapping simple and predictable
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 
  0, 0,                  // 0 buttons, 0 hat switches
  true, true, true,      // X Axis (Left Brake), Y Axis (Right Brake), Z Axis (Yaw)
  false, false, false,   // No rotational axes
  false, false,          // No native rudder or throttle
  false, false, false    // No accelerator, brake, or steering profiles
);

void setup() {
  Serial.begin(9600); // For calibration troubleshooting
  
  Joystick.begin(true); // Auto-send state updates enabled
  
  // Set consistent 10-bit output ranges for Joystick Gremlin to digest
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);
}

void loop() {
  // Read raw 10-bit inputs directly from the SS49E sensors
  int rawYaw   = analogRead(PIN_RUDDER_YAW);
  int rawLeft  = analogRead(PIN_LEFT_BRAKE);
  int rawRight = analogRead(PIN_RIGHT_BRAKE);

  // --- 1. PROCESS RUDDER/YAW (Z AXIS) ---
  int outYaw = map(rawYaw, YAW_MIN, YAW_MAX, 0, 1023);
  outYaw = constrain(outYaw, 0, 1023);

  // --- 2. PROCESS LEFT TOE BRAKE (X AXIS) ---
  int outLeft = map(rawLeft, L_BRAKE_REST, L_BRAKE_MAX, 0, 1023);
  outLeft = constrain(outLeft, 0, 1023);

  // --- 3. PROCESS RIGHT TOE BRAKE (Y AXIS) ---
  int outRight = map(rawRight, R_BRAKE_REST, R_BRAKE_MAX, 0, 1023);
  outRight = constrain(outRight, 0, 1023);

  // --- 4. UPDATE USB HID OUTPUTS ---
  Joystick.setZAxis(outYaw);   // Map Rudder to Generic Z
  Joystick.setXAxis(outLeft);  // Map Left Toe to Generic X
  Joystick.setYAxis(outRight); // Map Right Toe to Generic Y

  // --- 5. OPTIONAL CALIBRATION DEBUGGING ---
  // Uncomment the lines below to read your raw values in the Serial Monitor
  
  Serial.print("Yaw: "); Serial.print(rawYaw);
  Serial.print(" | L_Brake: "); Serial.print(rawLeft);
  Serial.print(" | R_Brake: "); Serial.println(rawRight);
  

  delay(10); // Standard 100Hz refresh rate to match USB polling comfortably
}
/*
 * Rudder Pedal System Firmware
 * Copyright (c) 2026 Kenneth "Cmdr_Scotty" Walters
 * 
 * Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International.
 * See LICENSE file in project root for full details.
 * Commercial use prohibited without prior permission.
 */


#include <Joystick.h>

// Define Analog Pins for the 49E Hall Effect Sensors
#define PIN_RUDDER_YAW A0  // Center Rudder axis (North/South swing)
#define PIN_LEFT_BRAKE A1  // Left toe brake (South only)
#define PIN_RIGHT_BRAKE A2 // Right toe brake (South only)

// TARGET CALIBRATION VALUES
// Run the code, open your Arduino Serial Monitor at 9600 baud, 
// move the pedals to their mechanical limits, and update these numbers.
const int YAW_MIN = 200;    // Raw analog reading at full Left Rudder
const int YAW_MAX = 820;    // Raw analog reading at full Right Rudder

const int L_BRAKE_REST = 512; // Raw reading when foot is OFF the left pedal
const int L_BRAKE_MAX  = 950; // Raw reading when left pedal is FULLY DEPRESSED

const int R_BRAKE_REST = 512; // Raw reading when foot is OFF the right pedal
const int R_BRAKE_MAX  = 950; // Raw reading when right pedal is FULLY DEPRESSED

// Initialize Joystick Object optimized for Joystick Gremlin
// Using generic X, Y, and Z axes to keep vJoy mapping simple and predictable
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 
  0, 0,                  // 0 buttons, 0 hat switches
  true, true, true,      // X Axis (Left Brake), Y Axis (Right Brake), Z Axis (Yaw)
  false, false, false,   // No rotational axes
  false, false,          // No native rudder or throttle
  false, false, false    // No accelerator, brake, or steering profiles
);

void setup() {
  Serial.begin(9600); // For calibration troubleshooting
  
  Joystick.begin(true); // Auto-send state updates enabled
  
  // Set consistent 10-bit output ranges for Joystick Gremlin to digest
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);
}

void loop() {
  // Read raw 10-bit inputs directly from the SS49E sensors
  int rawYaw   = analogRead(PIN_RUDDER_YAW);
  int rawLeft  = analogRead(PIN_LEFT_BRAKE);
  int rawRight = analogRead(PIN_RIGHT_BRAKE);

  // --- 1. PROCESS RUDDER/YAW (Z AXIS) ---
  int outYaw = map(rawYaw, YAW_MIN, YAW_MAX, 0, 1023);
  outYaw = constrain(outYaw, 0, 1023);

  // --- 2. PROCESS LEFT TOE BRAKE (X AXIS) ---
  int outLeft = map(rawLeft, L_BRAKE_REST, L_BRAKE_MAX, 0, 1023);
  outLeft = constrain(outLeft, 0, 1023);

  // --- 3. PROCESS RIGHT TOE BRAKE (Y AXIS) ---
  int outRight = map(rawRight, R_BRAKE_REST, R_BRAKE_MAX, 0, 1023);
  outRight = constrain(outRight, 0, 1023);

  // --- 4. UPDATE USB HID OUTPUTS ---
  Joystick.setZAxis(outYaw);   // Map Rudder to Generic Z
  Joystick.setXAxis(outLeft);  // Map Left Toe to Generic X
  Joystick.setYAxis(outRight); // Map Right Toe to Generic Y

  // --- 5. OPTIONAL CALIBRATION DEBUGGING ---
  // Uncomment the lines below to read your raw values in the Serial Monitor
  
  // Serial.print("Yaw: "); Serial.print(rawYaw);
  // Serial.print(" | L_Brake: "); Serial.print(rawLeft);
  // Serial.print(" | R_Brake: "); Serial.println(rawRight);
  

  delay(10); // Standard 100Hz refresh rate to match USB polling comfortably
}
