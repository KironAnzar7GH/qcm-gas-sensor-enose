# Low-Cost QCM Gas Sensor for Alpha-Terpinyl Acetate Detection

## 📌 Project Overview
This project details the design and fabrication of a portable, low-cost Quartz Crystal Microbalance (QCM) gas sensor system. It is specifically engineered to detect alpha-terpinyl acetate (ATA), the primary volatile aroma compound in Indian cardamom, for agricultural quality assessment. 

By integrating a 10 MHz QCM crystal coated with a custom Molecularly Imprinted Polymer (MIP) and an STM32 microcontroller, the system measures nanogram-level mass changes via resonant frequency shifts (based on the Sauerbrey equation). 

## 🛠️ Hardware & Embedded Systems
* **Microcontroller:** STM32F103C8T6 ("Blue Pill")
* **Sensor Element:** 10 MHz AT-cut Quartz Crystal with gold electrodes
* **Oscillator Circuit:** Pierce Oscillator utilizing a 74HC04 Inverter IC
* **Interfacing:** Edge-counting timer configuration on the STM32 for high-resolution frequency measurement, outputting data via UART.
* **Enclosure:** Custom gas-tight acrylic chamber with sample tray.

## 🧪 Chemical Synthesis (Sensor Coating)
To achieve specific selectivity for ATA, a Molecularly Imprinted Polymer (MIP) was synthesized and deposited onto the QCM gold electrodes. 
* **Template Molecule:** Alpha-terpinyl acetate (ATA)
* **Functional Monomer:** Methacrylic acid (MAA)
* **Cross-Linker:** Ethylene glycol dimethacrylate (EGDMA)
* **Process:** Drop-cast deposition and UV/thermal polymerization, followed by acetic acid/ethanol washing to remove the template and leave selective binding cavities.

## 📊 Performance & Results
* **Sensitivity:** Successfully established a clear, repeatable correlation between ATA concentration and frequency shift.
* **Detection Range:** Calibrated for standard ATA vapor concentrations ranging from 10 ppm to 100 ppm.
* **Detection Limit:** Achieved a lower detection limit of ~2 ppm.
* **Cost Efficiency:** The entire system was developed for under ₹2,000, offering a highly accessible alternative to expensive Gas Chromatography (GC-MS) equipment for small-scale producers.

## 📝 Reference
This project was developed as an M.Tech project in Electronics and Communication Engineering at Aliah University.
