#  Temperature & Humidity Alert System

A real-time monitoring system that detects temperature and humidity levels using a DHT22 sensor and alerts users through LEDs, buzzer, and LCD display.

---

##  Features
- Real-time temperature and humidity monitoring  
- Alert system using buzzer  
- Red LED for alert condition  
- Green LED for normal condition  
- LCD display for live data and system status  
- Detects:
  - High temperature  
  - High humidity  
  - Both conditions simultaneously  

---

## 🛠️ Technologies Used
- Arduino (C/C++)
- DHT22 Sensor
- I2C LCD Display (16x2)
- Wokwi Simulator

---
##  Components Required

| Component                      | Quantity | Description                              |
|--------------------------------|----------|------------------------------------------|
| Arduino Uno                   | 1        | Main microcontroller board               |
| DHT22 Sensor                  | 1        | Measures temperature and humidity        |
| 16x2 I2C LCD Display          | 1        | Displays readings and system status      |
| Buzzer                        | 1        | Provides alert sound                     |
| Red LED                       | 1        | Indicates alert condition                |
| Green LED                     | 1        | Indicates normal condition               |
| Resistors (220Ω)              | 2        | Used with LEDs                           |
| Jumper Wires                  | As needed| Connections between components           |

---

##  Working Principle
1. The DHT22 sensor reads temperature and humidity values.
2. Data is displayed on the LCD screen.
3. If:
   - Temperature > 35°C → Temperature Alert  
   - Humidity > 80% → Humidity Alert  
   - Both exceed limits → Combined Alert  
4. Alerts are triggered using:
   - Red LED  
   - Buzzer  
5. Otherwise, system remains in normal state with Green LED ON.

---
##  Project Structure
```temperature-humidity-alert-system/
├── sketch.ino
├── diagram.json
├── libraries.txt
└── README.md
```

---
##  Simulation
[live simulation link](https://wokwi.com/projects/458753049333917697)

---
##  Output
- LCD displays temperature & humidity  
- Serial Monitor shows logs  
- LEDs and buzzer indicate system status  

---

##  Contributors
- Payal Sulaniya

---

##  Future Improvements
- Mobile notifications (IoT integration)  
- Data visualization dashboard  
- Cloud data storage  

---

## ⭐ Acknowledgement
This project was developed as a collaborative IoT-based monitoring system for learning and practical implementation of embedded systems.
