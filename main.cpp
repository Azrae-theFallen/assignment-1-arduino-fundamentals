#include <Arduino.h>

// --- Task 1 & 2: Global Variables & Hardware Configuration ---
const int ledPin = 13;       // The digital channel wired to our physical LED layout
int blinkInterval = 150;     // Pulse pacing speed in milliseconds (0.15 seconds)
int currentCount = 10;       // Tracking start threshold for our loop evaluation

// --- Task 3: Custom Modular Function with Parameter Inputs ---
// This takes a variable integer argument to decide how many pulse cycles to execute
void triggerSmartBlink(int totalBlinks) {
  int cycleCounter = 0;
  
  // Keep flashing until we hit the requested target count parameter
  while (cycleCounter < totalBlinks) {
    digitalWrite(ledPin, HIGH);   // Send 5V rail voltage (LED High State)
    delay(blinkInterval);         // Keep voltage high for interval duration
    digitalWrite(ledPin, LOW);    // Drop to 0V ground potential (LED Low State)
    delay(blinkInterval);         // Keep voltage low for interval duration
    
    cycleCounter++;               // Increment to prevent falling into an infinite loop
  }
}

void setup() {
  // Define our pin behavior channel profile
  pinMode(ledPin, OUTPUT);

  // Initialize the UART serial transceiver line at standard 9600 communication speed
  Serial.begin(9600);
  
  // Print initial program tracking data header stream
  Serial.println("==========================================");
  Serial.println("  ASSIGNMENT 1: TASK 5 SMART COUNTDOWN    ");
  Serial.println("  Author: Desmond Samson Osagyefo         ");
  Serial.println("==========================================");
  delay(1000); // Short tactical delay to stabilize console readout view
}

void loop() {
  // --- Task 4 & 5: Unified Conditional Execution Sequence ---
  while (currentCount > 0) {
    // Print the numerical evaluation index sequence to the terminal
    Serial.print("Current Countdown Level: [ ");
    Serial.print(currentCount);
    Serial.println(" ]");

    // Dynamically calculate flashing count parameters based on structural logic:
    // If current index matches high-level value (like 10), flash 3 times. 
    // Otherwise, flash rapidly twice to signal ongoing iteration.
    if (currentCount == 10) {
      triggerSmartBlink(3); 
    } else {
      triggerSmartBlink(2);
    }

    currentCount--; // Decrement structural execution value state 
    delay(400);     // Grace window pause between sequential tracking iterations
  }

  // Final Terminal Action Message triggered once evaluation bounds fall to zero
  Serial.println("\n>>> Countdown Process Completed! System Launch Cleared. <<<");
  
  // Safe execution trap to prevent loop recycle loops or continuous flashing
  while (true) {
    // Controller remains safely asleep here until physical reset execution occurs
  }
}