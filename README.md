# Arduino Car Proximity Sensor Kit

A low-cost Arduino-based solution that retrofits older cars with modern parking-assist style distance sensors.  
The system uses ultrasonic sensors to detect nearby obstacles and provides drivers with both visual (LEDs) and audio (buzzer) alerts for safer driving.

---

## 🚗 Features
- **Ultrasonic Sensors (HC-SR04):** Detects obstacles in front of the car.
- **LED Indicators:** Green, Yellow, and Red LEDs show distance ranges.
- **Audio Alerts:** Piezo buzzer changes pitch as objects get closer.
- **Dashboard Display:** Provides clear, real-time feedback.
- **Affordable Retrofit:** Brings modern safety utilities to older cars.

---

## 🧑‍🤝‍🧑 Human-Centered Need
Many elderly drivers rely on older vehicles without modern safety systems.  
This kit provides an affordable way to upgrade those vehicles, improving awareness and reducing accidents without requiring the purchase of a new car.

---

## ⚙️ Design Overview
- **Mounting:** Sensors are placed on the front bumper (center, left, right).  
- **Processing:** Arduino calculates distances from each sensor.  
- **Output:** LEDs + buzzer provide immediate driver feedback.  
- **Power:** Runs on car’s 5V supply (optionally solar-assisted).  

**Design Sketches:**  
![Car Sensor Sketch 1](drawings.jpeg)  


---

## 🔄 System Flow
1. Sensors emit ultrasonic pulses and measure distance.  
2. Arduino identifies the nearest detected obstacle.  
3. LEDs respond:
   - 🟢 **Green** → 60–40 cm  
   - 🟡 **Yellow** → 40–15 cm  
   - 🔴 **Red** → < 15 cm  
4. Buzzer tones:
   - Low pitch = Green  
   - Medium pitch = Yellow  
   - High pitch = Red  

**Actual Breadboard with Sensors:**  
![Breadboard Sensors](sensors.jpeg)  


---

## 🛠️ Parts List
- Arduino Uno or Mega  
- 3x HC-SR04 ultrasonic distance sensors  
- 3x LED sets (Green, Yellow, Red)  
- Piezo buzzer  
- Jumper wires, resistors, breadboard or PCB  
- Adhesive/mounting materials  

---

## 📋 Installation & Usage
1. Mount sensors on the bumper (center, left, right).  
2. Route wires into the car and connect to Arduino + display unit.  
3. Power via car 5V supply.  
4. Test by walking in front of the sensors to confirm LED + buzzer response.  
5. Maintain by occasionally cleaning sensors to avoid dirt buildup.  

---

## ⚠️ Limitations
- HC-SR04 sensors have limited accuracy beyond ~2–3 meters.  
- Effectiveness depends on proper sensor mounting angles.  
- Some bumper designs may be incompatible with sensor placement.  

---

## 📚 References
- [Arduino Project Hub – HC-SR04](https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380)  
- [HC-SR04 Datasheet](https://www.digikey.com/en/products/detail/osepp-electronics-ltd/HC-SR04/11198533)  
- [Amazon – HC-SR04 Module](https://www.amazon.com/HC-SR04-Ultrasonic-Distance-Arduino-MEGA2560/dp/B08KZS3WTJ)  

---

## 👥 Authors
- David Noguera  
- Teddy Webb  
- Dakota Barnhouse  
