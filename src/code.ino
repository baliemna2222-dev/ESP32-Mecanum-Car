//https://robotlk.com/
//https://www.youtube.com/@RobotLk
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