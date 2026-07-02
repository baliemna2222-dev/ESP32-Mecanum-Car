<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:1a0b1f,50:8a2a68,100:ff4fa3&height=220&section=header&text=ESP32%20Mecanum%20Robot&fontSize=48&fontColor=ffffff&animation=fadeIn&fontAlignY=35&desc=Omnidirectional%20WiFi-Controlled%20Rover&descAlignY=55&descSize=18" width="100%"/>

<a href="https://github.com/baliemna2222-dev/ESP32-Mecanum-Robot">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=24&duration=2600&pause=900&color=FF4FA3&center=true&vCenter=true&width=700&lines=%E2%80%8AForward+%E2%80%A2+Backward+%E2%80%A2+Strafe+%E2%80%A2+Diagonal+%E2%80%A2+Rotate;%E2%80%8A360%C2%B0+Movement+with+4+Mecanum+Wheels;%E2%80%8AControlled+Live+over+WiFi+%F0%9F%93%A1;%E2%80%8ABuilt+on+ESP32+%E2%9A%A1"/>
</a>

<br/>

<img src="https://img.shields.io/badge/Platform-ESP32-FF4FA3?style=for-the-badge&logo=espressif&logoColor=white"/>
<img src="https://img.shields.io/badge/Control-WiFi-8A2A68?style=for-the-badge&logo=wifi&logoColor=white"/>
<img src="https://img.shields.io/badge/Wheels-Mecanum%20x4-1a0b1f?style=for-the-badge&logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciLz4=&logoColor=white"/>
<img src="https://img.shields.io/badge/Status-Active%20Development-ff69b4?style=for-the-badge"/>
<img src="https://img.shields.io/github/license/baliemna2222-dev/ESP32-Mecanum-Robot?style=for-the-badge&color=ff4fa3"/>

</div>

<br/>

## 🎯 About the Project

<table>
<tr>
<td width="60%" valign="top">

A collaborative build by **Emna Ben Ali** and **Mohamed Ben Ali** — an **ESP32-powered omnidirectional robot** built on **mecanum wheels**, giving it true **360° freedom of movement** — forward, backward, sideways, diagonal, and pure rotation — all without turning its chassis. Every command is sent wirelessly over **WiFi**, so the robot responds live with **zero lag control** from a browser or app interface.

No Ackermann steering. No blind spots. No wasted turning radius.
Just pure, fluid, omnidirectional motion.

</td>
<td>
<img src="assets/images/car.jpeg" width="100%"/></td>
</tr>
</table>

<div align="center">
  <video src="https://github.com/user-attachments/assets/735bc008-01eb-4c23-955c-d4ed90044f93" controls muted width="600">
    Your browser does not support the video tag.
  </video>
</div>

> 🎥 *Live demo of the WiFi controller driving the robot — forward, strafe, diagonal, and rotation in action.*

---

## ✨ Key Features

<div align="center">

| 🚀 | Feature | Description |
|:---:|:---|:---|
| 🕹️ | **True Omnidirectional Motion** | Move in any direction — including diagonally and sideways — without rotating the chassis |
| 🔄 | **In-Place Rotation** | Spin 360° on the spot using differential mecanum wheel speeds |
| 📡 | **WiFi Wireless Control** | ESP32 hosts a control interface accessible from any phone, tablet, or laptop on the network |
| ⚡ | **Real-Time Responsiveness** | Low-latency command handling for smooth, instant reactions |
| 🎨 | **Custom Control Interface** | Clean, intuitive directional UI for precision driving |
| 🔧 | **Modular Firmware** | Motor logic, WiFi server, and control parsing separated for easy expansion |

</div>

---

## 🧠 How Mecanum Motion Works

<div align="center">
<img src="https://img.shields.io/badge/-The%20Physics%20Behind%20It-1a0b1f?style=for-the-badge"/>
</div>

Each mecanum wheel has rollers angled at 45° around its circumference. By spinning all four wheels at *independent* speeds and directions, their combined force vectors let the robot glide in **any direction** without changing orientation.

```
        FRONT
   [FL]◤     ◥[FR]
     ↖ roller    roller ↗
        
   [BL]◣     ◢[BR]
     ↙ roller    roller ↘
        BACK

  Strafe Right  →  FL:+ FR:− BL:− BR:+
  Strafe Left   →  FL:− FR:+ BL:+ BR:−
  Diagonal ↗    →  FL:+ FR:0 BL:0 BR:+
  Rotate CW ⟳   →  FL:+ FR:− BL:+ BR:−
```

---

## 🛠️ Hardware Stack

<div align="center">

| Component | Purpose |
|:---|:---|
| **ESP32 Dev Board** | Main controller — runs WiFi server + motion logic |
| **4× Mecanum Wheels** | Omnidirectional locomotion |
| **4× DC Motors** | One per wheel, independently driven |
| **Motor Driver(s)** (L298N / TB6612FNG) | PWM speed + direction control per motor |
| **Power Supply / Battery Pack** | Powers motors + ESP32 logic (separate rails recommended) |
| **Chassis** | Mounts motors, wheels, battery, and electronics |

</div>

---

## 📡 System Architecture

```mermaid
flowchart LR
    A[📱 Phone / Browser<br/>Control UI] -- WiFi commands --> B[🧠 ESP32<br/>WebServer + Motion Logic]
    B --> C[⚙️ Motor Driver 1<br/>Left Wheels]
    B --> D[⚙️ Motor Driver 2<br/>Right Wheels]
    C --> E((FL Wheel))
    C --> F((BL Wheel))
    D --> G((FR Wheel))
    D --> H((BR Wheel))
```

---

## 🚀 Getting Started

### 1️⃣ Flash the Firmware
```bash
git clone https://github.com/baliemna2222-dev/ESP32-Mecanum-Robot.git
cd ESP32-Mecanum-Robot
# Open in Arduino IDE / PlatformIO
# Select board: ESP32 Dev Module
# Update your WiFi SSID + password in the config
```

### 2️⃣ Wire It Up
Connect each motor driver channel to its assigned ESP32 GPIO pins as defined in the firmware's pin config section.

### 3️⃣ Power On & Connect
The ESP32 boots and hosts a WiFi access point / joins your network. Connect from your phone or laptop to the printed IP address.

### 4️⃣ Drive!
Open the control interface in your browser and start moving — forward, strafe, diagonal, or spin in place.

---

## 🕹️ Control Interface Preview

<div align="center">

```
        ⬉   ⬆   ⬈
          ↖  |  ↗
    ⬅ ————[●]———— ➡
          ↙  |  ↘
        ⬋   ⬇   ⬊

          ⟲    ⟳
        rotate left/right
```

</div>

---

## 🗺️ Roadmap

- [x] Core mecanum drive logic
- [x] WiFi command server on ESP32
- [x] Web-based directional controller
- [ ] Speed slider / joystick-style control
- [ ] Obstacle avoidance with ultrasonic sensor
- [ ] Live camera streaming module
- [ ] Mobile app (BLE/WiFi hybrid) version
- [ ] Autonomous path-following mode

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!
Feel free to check the [issues page](../../issues) or open a pull request.

---

## 👥 Collaborators

<div align="center">

<table>
<tr>
<td align="center">
<img src="https://img.shields.io/badge/💗-Emna%20Ben%20Ali-ff4fa3?style=for-the-badge"/><br/>
<sub>Firmware · WiFi Control Logic · UI</sub>
</td>
<td align="center">
<img src="https://img.shields.io/badge/⚙️-Mohamed%20Ben%20Ali-8a2a68?style=for-the-badge"/><br/>
<sub>Hardware · Motor & Mecanum Drive System</sub>
</td>
</tr>
</table>

*A collaborative build — designed, wired, and coded together.*

</div>

---

## 🎬 Inspiration

This project was inspired by the excellent ESP32 WiFi mecanum wheel build tutorial by **Robot Lk**:

📺 [ESP32 WiFi Mecanum Wheel Robot – Full Build & Web Control Tutorial](https://www.youtube.com/watch?v=nbYb-EFjuI0)

Our implementation builds on the core concept — WiFi-driven mecanum control on an ESP32 — with our own firmware structure, wiring, and control interface.

---

<div align="center">

### 💗 Built with curiosity, ESP32s, and a lot of trial-and-error

<img src="https://img.shields.io/badge/Made%20by-Emna%20Ben%20Ali%20%26%20Mohamed%20Ben%20Ali-ff4fa3?style=for-the-badge"/>

<br/><br/>

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:ff4fa3,50:8a2a68,100:1a0b1f&height=120&section=footer" width="100%"/>

</div>
