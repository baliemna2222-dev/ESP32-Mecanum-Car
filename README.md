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

An **ESP32-powered mecanum car** developed collaboratively by **Emna Ben Ali** and **Mohamed Ben Ali**.

This project demonstrates how mecanum wheels enable smooth **360° omnidirectional movement**, allowing the car to move forward, backward, sideways, diagonally, and rotate in place without changing its orientation.

The car is controlled wirelessly over **WiFi**, providing responsive real-time control through a web interface. Built using embedded systems, robotics, and wireless communication, it serves as a practical platform for learning and experimentation.

</td>
<td>
<img src="assets/images/car.jpeg" width="100%"/>
</td>
</tr>
</table>

<div align="center">

<video src="https://github.com/user-attachments/assets/735bc008-01eb-4c23-955c-d4ed90044f93" controls muted width="600"></video>

</div>

> 🎥 Live demo showing forward, strafe, diagonal, and rotation control.

---

## 🎯 Objectives

- Design a 4-wheel mecanum chassis for full omnidirectional motion
- Implement independent PWM control for each motor using ESP32
- Develop an ESP32 web server for real-time wireless control
- Create a responsive browser-based control interface

---

## ✨ Key Features

| 🚀 | Feature | Description |
|:--:|:--------|:------------|
| 🕹️ | Omnidirectional Movement | Move in any direction without chassis rotation |
| 🔄 | In-place Rotation | Rotate 360° on the spot |
| 📡 | WiFi Control | Control the robot from any device on the same network |
| ⚡ | Real-Time Response | Low-latency command execution |
| 🎨 | Web Interface | Simple and intuitive directional control |
| 🔧 | Modular Code | Separated motor, WiFi, and control logic |

---

## 🧠 How It Works

The robot uses an ESP32 to receive movement commands over WiFi from a web interface.

Each command is translated into motor signals using PWM control. By adjusting the speed and direction of the four mecanum wheels independently, the robot can move in any direction or rotate in place.

The ESP32 continuously listens for incoming commands and updates motor outputs in real time for smooth control.

---

## 🔧 Build Process (Electronics & Wiring)

This section explains how the mechanical and electronic parts of the robot are connected, from motors to ESP32 control.

<div align="center">
<img src="assets/images/car_microcontroller.jpeg" width="70%"/>
</div>

> 🖼️ *Overview of the electronics layout — ESP32, motor drivers, and wiring connections.*

## ⚙️ Motor Driver Setup (Dual H-Bridge)

The robot uses **two H-bridge drivers** to control four DC motors:

- Left side motors → H-Bridge 1
- Right side motors → H-Bridge 2

Each motor is controlled using:
- Digital pins → direction
- PWM signal → speed

This setup ensures stable current handling and simplifies wiring for the mecanum system.

<div align="center">
<img src="assets/images/pont-h.webp" width="70%"/>
</div>

> 🖼️ *Dual H-bridge motor driver .*

### 🧠 H-Bridge Working Principle

| IN1 | IN2 | Motor Direction |
|-----|-----|----------------|
| 1   | 0   | Forward        |
| 0   | 1   | Backward       |
| 0   | 0   | Stop           |
| 1   | 1   | Brake          |

<div align="center">
<img src="assets/images/h-bridge-elctronic.png" width="70%"/>
</div>

### 🔌 2. ESP32 to Dual Motor Driver Wiring

The ESP32 controls **two H-bridge motor drivers**, each responsible for two motors (left and right sides).  
Each motor uses **two GPIO pins** for direction control, while speed is managed using PWM.

### 🚗 Motor Mapping

| Wheel | ESP32 Pins | Motor Driver |
|------|------------|--------------|
| Back Left (BL) | GPIO 12, GPIO 13 | H-Bridge 1 (IN1 / IN2) |
| Front Left (FL) | GPIO 14, GPIO 27 | H-Bridge 1 (IN3 / IN4) |
| Front Right (FR) | GPIO 2, GPIO 0 | H-Bridge 2 (IN1 / IN2) |
| Back Right (BR) | GPIO 16, GPIO 4 | H-Bridge 2 (IN3 / IN4) |

---

## 🔌 Electronics

<div align="center">

| Component | Role |
|:---|:---|
| **ESP32 Dev Board** | Main controller — WiFi server + motor logic |
| **2× H-Bridge Motor Drivers** | Independent direction + PWM speed control per side |
| **4× DC Motors** | One per mecanum wheel |
| **Battery Pack** | Powers motors and ESP32, separate rails recommended |
| **Jumper Wires / Connectors** | GPIO-to-driver and driver-to-motor wiring |

</div>

<div align="center">
<img src="assets/images/car.jpeg" width="70%"/>
</div>

> 🖼️ *All electronic components after wiring.*

---

## 🧩 How Mecanum Wheels Work (Mechanically)
 
Each mecanum wheel has small **rollers** around its rim, angled at **45°**. These rollers spin freely on their own, separate from the wheel's rotation.
 
When the wheel spins, the angled rollers push the force in two directions at once — partly forward, partly sideways.
 
<div align="center">
<img src="assets/images/mecanum_wheel_architecture.jpg" width="70%"/>
</div>
> 🖼️ *how Mecanum Wheels are connected to the robot.*
 
**The four wheels work as a team.** They're mounted so each wheel's rollers angle opposite to its diagonal partner. By spinning each wheel at a different speed and direction, the robot can move any way — forward, sideways, diagonal, or spin in place — with no steering parts at all.
 
| Motion | FL | FR | BL | BR |
|:---|:---:|:---:|:---:|:---:|
| Forward | + | + | + | + |
| Backward | − | − | − | − |
| Strafe Right | + | − | − | + |
| Strafe Left | − | + | + | − |
| Diagonal ↗ | + | 0 | 0 | + |
| Diagonal ↖ | 0 | + | + | 0 |
| Rotate CW | + | − | + | − |
| Rotate CCW | − | + | − | + |
 
*(+ = spins forward, − = spins backward, 0 = stays still)*
 to see more :
📺 [The Simple Mechanics of Mecanum Wheels](https://www.youtube.com/watch?v=0k-Ey9bS9lE)

<div align="center">
<img src="assets/images/mecanum_wheel_controll.jpeg" width="70%"/>
</div>
> 🖼️ *Caption of the Wheels control from what we understand from the video .*

## 🕹️ Control Interface
 
The robot is controlled through a **web page hosted directly on the ESP32** — no app install needed. The ESP32 runs its own WiFi access point (`MecanumCar`), and any phone or laptop that connects to it can open the control page straight from a browser.
 
**How it works:**
- The ESP32 serves an HTML/CSS/JS control panel with a dark glassmorphism UI
- 8 directional buttons (forward, backward, strafe, diagonals) plus rotate left/right and stop
- Buttons are **hold-to-move**: pressing sends the move command, releasing sends stop — works with mouse and touch, so it's fully usable on mobile
- A live **speed slider** (0–100%) adjusts PWM output in real time via a `/speed` endpoint
- Each button press hits a lightweight `/cmd?move=...` endpoint, which the ESP32 maps directly to motor logic — keeping the interface fast and the firmware simple
<details>
<summary><b>📄 View Control Interface Code (HTML / CSS / JS)</b></summary>
```html
<html>
<head>
<meta charset="UTF-8">
<title>Mecanum Car Control</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
 
<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family:Arial, sans-serif;
}
 
body{
    background:linear-gradient(135deg,#0f172a,#1e293b);
    color:white;
    text-align:center;
    min-height:100vh;
    display:flex;
    justify-content:center;
    align-items:center;
}
 
.container{
    background:rgba(255,255,255,0.08);
    backdrop-filter:blur(12px);
    padding:25px;
    border-radius:20px;
    box-shadow:0 0 20px rgba(0,0,0,0.4);
}
 
h2{
    margin-bottom:20px;
}
 
.row{
    display:flex;
    justify-content:center;
    gap:12px;
    margin:12px 0;
}
 
button{
    width:90px;
    height:70px;
    border:none;
    border-radius:15px;
    font-size:18px;
    font-weight:bold;
    color:white;
    cursor:pointer;
    transition:0.2s;
}
 
button:hover{
    transform:scale(1.08);
}
 
button:active{
    transform:scale(0.95);
}
 
.move{
    background:#2563eb;
}
 
.side{
    background:#7c3aed;
}
 
.rotate{
    background:#f59e0b;
}
 
.diagonal{
    background:#10b981;
}
 
.stop{
    background:#ef4444;
    width:200px;
    height:70px;
    margin-top:15px;
}
</style>
<script>
function sendCommand(cmd) {
    fetch("/" + cmd);
}
 
function updateSpeed(speed) {
    document.getElementById("speedValue").innerText = speed;
    fetch("/speed?value=" + speed);
}
</script>
<script>
function sendCmd(cmd){
  fetch(`/cmd?move=${cmd}`);
}
 
function hold(btn,cmd){
  btn.addEventListener('mousedown',()=>sendCmd(cmd));
  btn.addEventListener('mouseup',()=>sendCmd('S'));
 
  btn.addEventListener('touchstart',()=>sendCmd(cmd));
  btn.addEventListener('touchend',()=>sendCmd('S'));
}
 
window.onload=()=>{
  ['F','B','SL','SR','RL','RR','FL','FR','BL','BR'].forEach(id=>{
    hold(document.getElementById(id),id);
  });
}
</script>
 
</head>
 
<body>
 
<div class="container">
 
<h2>🚗 Mecanum Robot Controller</h2>
 
<div class="row">
    <button id="FL" class="diagonal">↖</button>
    <button id="F" class="move">↑</button>
    <button id="FR" class="diagonal">↗</button>
</div>
 
<div class="row">
    <button id="SL" class="side">←</button>
    <button id="RL" class="rotate">⟲</button>
    <button id="RR" class="rotate">⟳</button>
    <button id="SR" class="side">→</button>
</div>
 
<div class="row">
    <button id="BL" class="diagonal">↙</button>
    <button id="B" class="move">↓</button>
    <button id="BR" class="diagonal">↘</button>
</div>
 
<button class="stop" onclick="sendCmd('S')">
    STOP
</button>
<div style="margin-top:20px;">
    <label style="color:white;font-size:18px;">
        Speed: <span id="speedValue">100</span>%
    </label>
    <br><br>
    <input
        type="range"
        min="0"
        max="100"
        value="100"
        id="speedSlider"
        style="width:250px;"
        oninput="updateSpeed(this.value)">
</div>
</div>
 
</body>
</html>
```
 
</details>
<details>
<summary><b>📄 View Full Firmware Code (ESP32 + Motor Control + Web Server)</b></summary>
```cpp
//https://robotlk.com/
//https://www.youtube.com/watch?v=nbYb-EFjuI0&t=2s
#include <WiFi.h>
#include <WebServer.h>
 
const char* ssid = "MecanumCar";
const char* password = "12345678";
int speedPercent = 100;
 
WebServer server(80);
 
// Motor pins
int IN1 = 12, IN2 = 13;   // back Left
int IN3 = 14, IN4 = 27;   // Front left
int IN5 = 2, IN6 = 0;   // front right
int IN7 = 16, IN8 = 4;   // Back Right
 
void setup() {
  Serial.begin(115200);
 
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);
 
  WiFi.softAP(ssid, password);
  Serial.println(WiFi.softAPIP());
 
  server.on("/", handleRoot);
  server.on("/cmd", handleCommand);
  server.begin();
  server.on("/speed", handleSpeed);
}
 
void loop() {
  server.handleClient();
}
 
// ===== HTML PAGE =====
void handleRoot() {
  String html = R"rawliteral(
  <html>
<head>
<meta charset="UTF-8">
<title>Mecanum Car Control</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
 
<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family:Arial, sans-serif;
}
 
body{
    background:linear-gradient(135deg,#0f172a,#1e293b);
    color:white;
    text-align:center;
    min-height:100vh;
    display:flex;
    justify-content:center;
    align-items:center;
}
 
.container{
    background:rgba(255,255,255,0.08);
    backdrop-filter:blur(12px);
    padding:25px;
    border-radius:20px;
    box-shadow:0 0 20px rgba(0,0,0,0.4);
}
 
h2{
    margin-bottom:20px;
}
 
.row{
    display:flex;
    justify-content:center;
    gap:12px;
    margin:12px 0;
}
 
button{
    width:90px;
    height:70px;
    border:none;
    border-radius:15px;
    font-size:18px;
    font-weight:bold;
    color:white;
    cursor:pointer;
    transition:0.2s;
}
 
button:hover{
    transform:scale(1.08);
}
 
button:active{
    transform:scale(0.95);
}
 
.move{
    background:#2563eb;
}
 
.side{
    background:#7c3aed;
}
 
.rotate{
    background:#f59e0b;
}
 
.diagonal{
    background:#10b981;
}
 
.stop{
    background:#ef4444;
    width:200px;
    height:70px;
    margin-top:15px;
}
</style>
<script>
function sendCommand(cmd) {
    fetch("/" + cmd);
}
 
function updateSpeed(speed) {
    document.getElementById("speedValue").innerText = speed;
    fetch("/speed?value=" + speed);
}
</script>
<script>
function sendCmd(cmd){
  fetch(`/cmd?move=${cmd}`);
}
 
function hold(btn,cmd){
  btn.addEventListener('mousedown',()=>sendCmd(cmd));
  btn.addEventListener('mouseup',()=>sendCmd('S'));
 
  btn.addEventListener('touchstart',()=>sendCmd(cmd));
  btn.addEventListener('touchend',()=>sendCmd('S'));
}
 
window.onload=()=>{
  ['F','B','SL','SR','RL','RR','FL','FR','BL','BR'].forEach(id=>{
    hold(document.getElementById(id),id);
  });
}
</script>
 
</head>
 
<body>
 
<div class="container">
 
<h2>🚗 Mecanum Robot Controller</h2>
 
<div class="row">
    <button id="FL" class="diagonal">↖</button>
    <button id="F" class="move">↑</button>
    <button id="FR" class="diagonal">↗</button>
</div>
 
<div class="row">
    <button id="SL" class="side">←</button>
    <button id="RL" class="rotate">⟲</button>
    <button id="RR" class="rotate">⟳</button>
    <button id="SR" class="side">→</button>
</div>
 
<div class="row">
    <button id="BL" class="diagonal">↙</button>
    <button id="B" class="move">↓</button>
    <button id="BR" class="diagonal">↘</button>
</div>
 
<button class="stop" onclick="sendCmd('S')">
    STOP
</button>
<div style="margin-top:20px;">
    <label style="color:white;font-size:18px;">
        Speed: <span id="speedValue">100</span>%
    </label>
    <br><br>
    <input
        type="range"
        min="0"
        max="100"
        value="100"
        id="speedSlider"
        style="width:250px;"
        oninput="updateSpeed(this.value)">
</div>
</div>
 
</body>
</html>
  )rawliteral";
  server.send(200, "text/html", html);
}
 
// ===== Handle Commands =====
void handleCommand() {
  String move = server.arg("move");
  if (move == "F") forward();
  else if (move == "B") backward();
  else if (move == "SL") strafeLeft();
  else if (move == "SR") strafeRight();
  else if (move == "RL") rotateLeft();
  else if (move == "RR") rotateRight();
  else if (move == "FL") forwardLeft();
  else if (move == "FR") forwardRight();
  else if (move == "BL") backLeft();
  else if (move == "BR") backRight();
  else stopCar();
 
  server.send(200, "text/plain", "OK");
}
 
// ===== Motor Control Logic =====
int getPWM() {
  return map(speedPercent, 0, 100, 0, 255);
}
 
void stopCar() {
  analogWrite(IN1,0); analogWrite(IN2,0);
  analogWrite(IN3,0); analogWrite(IN4,0);
  analogWrite(IN5,0); analogWrite(IN6,0);
  analogWrite(IN7,0); analogWrite(IN8,0);
}
 
void forward() {
  int s = getPWM();
  analogWrite(IN1,s); analogWrite(IN2,0);
  analogWrite(IN3,s); analogWrite(IN4,0);
  analogWrite(IN5,s); analogWrite(IN6,0);
  analogWrite(IN7,s); analogWrite(IN8,0);
}
 
void backward() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,s);
  analogWrite(IN3,0); analogWrite(IN4,s);
  analogWrite(IN5,0); analogWrite(IN6,s);
  analogWrite(IN7,0); analogWrite(IN8,s);
}
 
void strafeRight() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,s);
  analogWrite(IN3,s); analogWrite(IN4,0);
  analogWrite(IN5,0); analogWrite(IN6,s);
  analogWrite(IN7,s); analogWrite(IN8,0);
}
 
void strafeLeft() {
  int s = getPWM();
  analogWrite(IN1,s); analogWrite(IN2,0);
  analogWrite(IN3,0); analogWrite(IN4,s);
  analogWrite(IN5,s); analogWrite(IN6,0);
  analogWrite(IN7,0); analogWrite(IN8,s);
}
 
void rotateRight() {
  int s = getPWM();
  analogWrite(IN1,s); analogWrite(IN2,0);
  analogWrite(IN3,s); analogWrite(IN4,0);
  analogWrite(IN5,0); analogWrite(IN6,s);
  analogWrite(IN7,0); analogWrite(IN8,s);
}
 
void rotateLeft() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,s);
  analogWrite(IN3,0); analogWrite(IN4,s);
  analogWrite(IN5,s); analogWrite(IN6,0);
  analogWrite(IN7,s); analogWrite(IN8,0);
}
 
void forwardLeft() {
  int s = getPWM();
  analogWrite(IN1,s); analogWrite(IN2,0);
  analogWrite(IN3,0); analogWrite(IN4,0);
  analogWrite(IN5,s); analogWrite(IN6,0);
  analogWrite(IN7,0); analogWrite(IN8,0);
}
 
void forwardRight() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,0);
  analogWrite(IN3,s); analogWrite(IN4,0);
  analogWrite(IN5,0); analogWrite(IN6,0);
  analogWrite(IN7,s); analogWrite(IN8,0);
}
 
void backLeft() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,0);
  analogWrite(IN3,0); analogWrite(IN4,s);
  analogWrite(IN5,0); analogWrite(IN6,0);
  analogWrite(IN7,0); analogWrite(IN8,s);
}
 
void backRight() {
  int s = getPWM();
  analogWrite(IN1,0); analogWrite(IN2,s);
  analogWrite(IN3,0); analogWrite(IN4,0);
  analogWrite(IN5,0); analogWrite(IN6,s);
  analogWrite(IN7,0); analogWrite(IN8,0);
}
void handleSpeed() {
    if (server.hasArg("value")) {
        speedPercent = server.arg("value").toInt();
        Serial.println("Speed: " + String(speedPercent));
    }
    server.send(200, "text/plain", "OK");
}
```
 
</details>

> 🖼️ *Chassis and mecanum wheel assembly.* after that
