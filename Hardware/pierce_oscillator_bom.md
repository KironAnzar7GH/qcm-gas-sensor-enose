# Pierce Oscillator Circuit Setup

To excite the QCM crystal at its resonant frequency, a standard Pierce oscillator circuit was assembled and interfaced with the STM32 microcontroller. 

## Bill of Materials (BOM)
* **QCM Crystal:** 10 MHz AT-cut quartz crystal
* **Active Element:** 74HC04 (Hex Inverter IC)
* **Feedback Resistor (R1):** 1 MΩ
* **Load Capacitors (C1, C2):** 22 pF
* **Power Supply:** 5V DC

## Architecture
The QCM crystal sits in the feedback loop of the 74HC04 inverter. The resulting analog oscillation is fed into a timer input pin on the STM32F103C8T6. The STM32 uses internal counters to measure the frequency pulses over a 1-second gate interval, establishing the baseline frequency.
