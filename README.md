# 📍 GPS Tracking System - Embedded Systems Project

This project is a **GPS-based location tracking system** developed as part of the **CSE211s - Introduction to Embedded Systems** course at **Faculty of Engineering, Ain Shams University**.

It utilizes an **ARM Cortex-M4** based microcontroller (TM4C123 - Tiva C Series), programmed in **Embedded C** and **ARM Assembly**, and integrates a **GPS module** to capture real-time location data, which is then displayed on an LCD.

---

## 🔧 Features

- 📡 Real-time location tracking using GPS
- 🧭 Nearest location identification from registered faculty locations
- 🖥️ LCD output (4-bit mode) to display live data
- 🔊 Buzzer for alert signal
- 🔘 Switch-triggered location updates with interrupt handling
- 🔁 UART communication for GPS data transfer
- 🧠 Optimized embedded drivers (UART, LCD, GPIO)
- ⚡ Powered via USB Power Bank

---

## 🧠 Technologies & Concepts

- **Embedded C**
- **ARM Cortex-M4** (TM4C123 Tiva C)
- **UART Protocol**
- **ARM Assembly**
- **GPS Module**
- **LCD (4-bit mode)**
- **GPIO & Interrupts**
- **TTL to USB Communication**
- **PuTTY for debugging**

---

## 🧑‍💻 Team Members

- **Saeed Bayoumy Nabawy Ali** (2200950) – CSE  
- **Mohamed Hamdy Youssif Ahmed** (2200416) – CSE  
- **Ahmed Mohamed Sadek Mohamed Saif Eldin** (2200963) – ECE  
- **Mostafa Ahmed Sherif Mohammed Abd El Meguid** (2200946) – ECE  
- **Zeyad Abdallah Shaban Abdelkareem** (2200932) – CSE  
- **Mohamed Ali Mohamed Elwan** (2200942) – CSE  
- **Abdulrahman Ibrahem Mohamed Ibrahem Ahmed** (2200960) – CSE  

---

## 📸 Project Demo

- 🎥 **[Watch Demo Video](https://drive.google.com/file/d/1BkLAwDDO9d_NDtN2qRKZ0DKjd8kZuqPA/view?usp=sharing)**

---

## 🗂️ File Structure

/GPS_Tracking_System_Project_CSE211
│
├── src/
│ ├── main.c # Main application logic
│ ├── gps.c / gps.h # GPS driver
│ ├── uart.c / uart.h # UART communication
│ ├── lcd.c / lcd.h # LCD driver (4-bit mode)
│ ├── gpio.c / gpio.h # GPIO initialization
│ ├── map.h # Registered locations
│ └── microconfig.c / .h # Microcontroller config
│
├── README.md # This file
├── REPORT.pdf # Final report
└── LICENSE

---

## 🛠️ Setup Instructions

### 📦 Requirements
- Tiva C Launchpad (TM4C123GH6PM)
- GPS Module (e.g., NEO-6M)
- LCD Display (16x2)
- Buzzer & Switch
- TTL to USB Converter
- Power bank or USB power
- Keil µVision / Code Composer Studio
- PuTTY (for UART debugging)
- Git Bash

### 🔌 Hardware Connections
- UART0 ↔ GPS Module  
- PortF (PF4) ↔ External switch (interrupt)  
- Port for LCD (4-bit mode)  
- GPIO for Buzzer  
- Power via USB  

### 💻 Flashing & Running
```bash
1. Clone the repository:
git clone https://github.com/saeed174/GPS_tracking_System_Project_CSE211.git

2. Open the project in your IDE (Keil/CCS).

3. Connect the Tiva C board via USB.

4. Build and flash the project.

5. Connect GPS via UART and LCD as per the wiring.

6. Use the external switch to trigger location display
