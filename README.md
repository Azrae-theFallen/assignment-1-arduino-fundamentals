# Assignment 1: Arduino Fundamentals — Smart Countdown System

## 👤 Author Metrics
* **Full Name:** Desmond Samson Osagyefo
* Index Number:2526401441
* **Course:** Programming C++ for Engineers Using Arduino
* **Institution:** Ghana Communication Technology University (GCTU)
* **Environment:** VS Code, PlatformIO Ecosystem, Wokwi Hardware Simulator

---

## 💻 System Source Code (`src/main.cpp`)

```cpp
#include <Arduino.h>

// Function declaration accepting parameter bounds
void blinkLED(int blinkCount, int delayTime) {
  for (int i = 0; i < blinkCount; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // Send 5V Rail (LED ON)
    delay(delayTime);                // Hold State
    digitalWrite(LED_BUILTIN, LOW);  // Send 0V Ground (LED OFF)
    delay(delayTime);                // Hold State
  }
}

void setup() {
  // Initialize built-in hardware channel macro mapping to Digital Pin 13
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Pattern 1: Critical Status Alert / High-Frequency Strobe
  blinkLED(5, 100);
  delay(2000); // 2-Second State Transition Pause
  
  // Pattern 2: Safe Steady-State Heartbeat Pulse
```
Core Concepts & Operational Engineering Questions

Q1: What is the architectural purpose of #include <Arduino.h>? Why choose it, and what happens if omitted?
Purpose & Choice: In a modern IDE workspace like PlatformIO, files compile as native C++ scripts (.cpp) rather than hidden .ino templates. The Arduino.h header must be explicitly imported to map the core Arduino hardware framework.

Omission Impact: Without this header file declaration, the compiler has no reference lookup definitions for structural commands like digitalWrite, pinMode, or delay, causing compilation failure immediately at the pre-processing phase.

Q2: What are parameters? Why structure code into parameterized functions instead of duplicates?
Definition: Parameters are variable slots declared inside a function's signature that accept data arguments passed by the calling code execution logic.

Structural Value: Instead of hardcoding static execution lines or copy-pasting duplicate conditional structures over and over, parameters allow a single code block to behave dynamically. This eliminates redundancy, reduces flash memory overhead, and allows edits to be performed in one single spot.

Q3: What happens if an incorrect pin macro is declared during hardware initialization?
Impact: If an incorrect or non-existent hardware register channel is assigned, the microcontroller compiles and executes the firmware instructions blindly, but the target hardware layout (the LED) remains entirely non-functional.

🚀 Future Technical Improvements & Iterative Roadmaps
Non-Blocking Delay Architectures (millis() Integration): Replace the standard blocking delay() statements with hardware clock evaluations using millis(). This allows the processor to read auxiliary sensors or register user inputs simultaneously without causing timing freezes.

Dynamic Parameter Upgrades via Serial Telemetry: Update the function framework to read parameters dynamically through live inputs in the Serial Monitor (Serial.read()), allowing a user to change blink speeds on the fly.
  blinkLED(3, 500);
  delay(4000); // 4-Second Idle Loop Window Delay
}
