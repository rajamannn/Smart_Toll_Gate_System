# 🚦 Smart Toll Gate System using Arduino UNO

A simple IoT-based Smart Toll Gate Prototype built using Arduino UNO, Ultrasonic Sensor, Servo Motor, Traffic LEDs, and a Buzzer.

The system automatically detects a vehicle using an ultrasonic sensor, opens the gate, activates traffic signals, and closes the gate once the vehicle passes.

---

## 📌 Project Overview

This project simulates an automated toll gate system:

- 🚗 Detects vehicle using ultrasonic sensor  
- 🚦 Controls traffic lights (Red, Yellow, Green)  
- 🔔 Activates buzzer when vehicle is detected  
- 🚪 Opens and closes gate automatically using servo motor  
- ⏱ Uses `millis()` for non-blocking traffic light timing  

---

## 🛠 Components Used

- Arduino UNO  
- HC-SR04 Ultrasonic Sensor  
- SG90 Servo Motor  
- 3 LEDs (Red, Yellow, Green)  
- Buzzer  
- Breadboard  
- Resistors (220Ω for LEDs)  
- Jumper Wires  
- External Power Supply (if required)

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
|-----------|-------------|
| Ultrasonic TRIG | 7 |
| Ultrasonic ECHO | 6 |
| Buzzer | 9 |
| Red LED | 10 |
| Yellow LED | 11 |
| Green LED | 12 |
| Servo Motor | 5 |

---

## ⚙️ How It Works

### 1️⃣ Distance Detection
- The ultrasonic sensor measures distance.
- If a vehicle is detected within **10 cm**, the system activates.

### 2️⃣ Gate Control
- Servo rotates to **90°** → Gate opens.
- When vehicle moves away → Servo returns to **0°** → Gate closes.

### 3️⃣ Traffic Light Logic
- Red light turns ON when vehicle is detected.
- Uses `millis()` for automatic signal switching every 5 seconds:
  - Green → Yellow → Red → Green

### 4️⃣ Buzzer Alert
- Buzzer beeps continuously while vehicle is present.
- Gives a long beep when vehicle leaves.

---

## 💻 Arduino Code

Upload the provided `.ino` file to Arduino UNO using Arduino IDE.

Make sure the Servo library is included:



## ▶️ How to Run

1. Connect all components as per pin configuration.
2. Open Arduino IDE.
3. Upload the `.ino` file to Arduino UNO.
4. Open Serial Monitor (9600 baud rate).
5. Place an object within 10 cm of sensor.
6. Observe automatic gate and signal operation.

---

## 📷 Project Image

Place your image inside the repository and use:

---

## 🧠 Concepts Used

- Embedded Systems
- Ultrasonic Distance Measurement
- PWM Control (Servo Motor)
- Digital Input/Output
- Non-blocking Programming using millis()
- Real-Time Automation

---

## 🚀 Future Enhancements

- RFID-based automatic toll deduction
- LCD display for vehicle count
- IoT cloud integration (Firebase)
- Automatic number plate recognition
- Solar-powered system

---

## 🎯 Applications

- Automated Toll Booths
- Smart Parking Systems
- Industrial Entry Gates
- Railway Crossing Systems

---

## 👨‍💻 Author

**Aman Raj**  
Diploma in Electronics & Communication Engineering  
Arduino | IoT | Embedded Systems Enthusiast  

---

## 📜 License

This project is licensed under the MIT License.

---

⭐ If you like this project, give it a star on GitHub!
