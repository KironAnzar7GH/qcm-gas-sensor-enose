/*
 * STM32F103C8T6 (Blue Pill) QCM Frequency Counter
 * Project: QCM-Based Gas Sensor for Alpha-Terpinyl Acetate Detection
 * 
 * Description: 
 * This firmware reads the oscillating frequency from a Pierce oscillator 
 * (driven by a 10 MHz QCM crystal). It utilizes STM32 hardware timers in 
 * external clock mode to accurately count high-frequency edge pulses over 
 * a 1-second gate interval, outputting the data via UART for data logging.
 */

#include <Arduino.h>

// Define the 1-second gate interval (1000 milliseconds)
#define GATE_INTERVAL 1000 

// Initialize Hardware Timer 2 for external edge counting
HardwareTimer *FreqTimer = new HardwareTimer(TIM2);
uint32_t lastTime = 0;

void setup() {
  // Initialize Serial Communication for PC Data Logging
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }

  // Format headers for PLX-DAQ or standard serial logging
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Frequency(Hz)");

  // Configure TIM2 Channel 1 (Pin PA0) as External Clock Input
  // This allows the hardware to count the 10 MHz pulses without CPU overhead
  FreqTimer->setMode(1, TIMER_INPUT_FREQ_DUTY_MEASUREMENT, PA0);
  FreqTimer->setCount(0);
  FreqTimer->resume();
  
  lastTime = millis();
}

void loop() {
  uint32_t currentTime = millis();
  
  // Trigger exactly every 1 second (Gate Interval)
  if (currentTime - lastTime >= GATE_INTERVAL) {
    // Pause the timer to safely read the hardware counter register
    FreqTimer->pause();
    
    // Fetch the total pulses counted in the last second (which equals Frequency in Hz)
    uint32_t currentFrequency = FreqTimer->getCount();
    
    // Reset the hardware counter for the next second and resume
    FreqTimer->setCount(0);
    FreqTimer->resume();
    
    // Log the data via UART
    Serial.print("DATA,TIME,");
    Serial.println(currentFrequency);
    
    // Update the timing variable
    lastTime = currentTime;
  }
}
