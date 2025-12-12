# Voice-Controlled-Wheelchair-Using-Arduino
A low cost assistive mobility system that moves a wheelchair based on simple voice commands received via a smartphone Bluetooth app. The Arduino processes commands like go, back, left, right, and stop and drives the motors in real time.

## 📌 Features

* Hands-free wheelchair control using voice commands
* Wireless communication via **HC-05 Bluetooth**
* Low-cost and easy-to-build prototype
* Smooth movement using **DC gear motors**
* Separate power supply for control and motor circuits
* Beginner-friendly Arduino setup

## 🧠 System Architecture

### **Block Diagram**

<img width="986" height="425" alt="Block Diagram" src="https://github.com/user-attachments/assets/30aad86f-e567-4ad4-9549-181b0565400f" />


## 🖼 Project Images


![WhatsApp Image 2025-11-21 at 20 27 39_731248eb](https://github.com/user-attachments/assets/fa1f19ae-2ff1-4392-9e9a-11f03713e105)
![WhatsApp Image 2025-11-21 at 20 27 39_614667fb](https://github.com/user-attachments/assets/762b86f8-ae0d-445a-9c98-4d100b4e6ab2)


## ⚙ Working Principle

1. User gives a voice command using a **mobile voice app**.
2. The app converts speech → text and sends the text to **HC-05 Bluetooth module**.
3. HC-05 transfers the data to **Arduino UNO**.
4. Arduino processes the command and drives the motors using **L293D motor driver**.
5. DC motors rotate accordingly:

| Command | Action        |
| ------- | ------------- |
| Go      | Move Forward  |
| Back    | Move Backward |
| Left    | Turn Left     |
| Right   | Turn Right    |
| Stop    | Stop Movement |


## 🔌 Components Used

| Component              | Purpose                         |
| ---------------------- | ------------------------------- |
| Arduino UNO            | Main controller                 |
| L293D Motor Driver     | Motor direction & speed control |
| HC-05 Bluetooth Module | Receives voice-command data     |
| DC Gear Motors         | Drives wheelchair movement      |
| 18650 Li-ion Batteries | Power supply                    |


## 📈 Future Scope

* IoT integration for remote monitoring
* Obstacle detection (Ultrasonic, IR)
* Onboard offline voice recognition
* AI-based navigation
* Health monitoring sensors
* Improved motors & battery backup
