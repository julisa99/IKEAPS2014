#include <ESP8266WiFi.h>
#include <Espalexa.h> // https://github.com/Aircoookie/Espalexa/issues/6 needs to change in line 197 in Espalexa.h 'arg(0)' to 'argName(0)'
#include <Servo.h>

static constexpr char* WIFI_SSID = "your-ssid";
static constexpr char* WIFI_PASS = "your-password";

static constexpr int SERVO_PIN = 16;    // 2 from D4 | 16 from D0
static constexpr int FEEDBACK_PIN = A0; // A0 from Magnetic Encoder

static constexpr int FEEDBACK_OFFSET = 50; // select the value until you have outsmarted your unprecise encoder
static constexpr int MAX_FEEDBACK = 1024;
static constexpr int MAX_ROTATION = 4500;
static constexpr int MAX_TURN = MAX_ROTATION / MAX_FEEDBACK;

Servo servoMotor;
Espalexa espalexa;

uint8_t oldBrightness = 0;
int currentTurn = 0;
int targetTurn = 0;
int targetPos = 0;
int pos = 0;
int oldPos = 0;

enum class Direction : int {
  forward = 1,
  backward = -1
};

void wifiSetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
}

bool isInRange(int lower, int upper, int current) {
  return lower <= current && current <= upper;
}

// check target position with offset (accurancy problem of encoder)
bool isTargetPosWithOffset(int current, int target) {
  int lower = (target + MAX_FEEDBACK - FEEDBACK_OFFSET) % MAX_FEEDBACK;
  int upper = (target + FEEDBACK_OFFSET) % MAX_FEEDBACK;
  if (lower > upper) {
    return isInRange(lower, MAX_FEEDBACK, current) || isInRange(0, upper, current);
  } else {
    return isInRange(lower, upper, current);
  }
}

void onRotate(const Direction direction) {
  while (currentTurn != targetTurn || !isTargetPosWithOffset(pos, targetPos)) {
    yield();
    if (direction == Direction::forward && currentTurn > MAX_TURN) {
      return startRotate();
    } else if (direction == Direction::backward && currentTurn < 0) {
      return startRotate();
    }
    pos = analogRead(FEEDBACK_PIN);
    if (abs(oldPos - pos) > 500) {
      currentTurn += static_cast<int>(direction);
    }
    oldPos = pos;
  }
}

void startRotate() {
  if (currentTurn * MAX_FEEDBACK + pos < targetTurn * MAX_FEEDBACK + targetPos) {
    servoMotor.writeMicroseconds(2000); // when high level is 1.5~2ms, servo rotates counter clockwise
    onRotate(Direction::forward); // open lamp
  } else {
    servoMotor.writeMicroseconds(1000); // when high level is 1~1.5ms, servo rotates clockwise
    onRotate(Direction::backward); // close lamp
  }
}

void deviceChanged(uint8_t brightness) { // brightness value between 0-255
  if (oldBrightness == brightness) {
    return;
  }
  oldBrightness = brightness;
  int targetRotation = static_cast<int>(MAX_ROTATION * (static_cast<float>(brightness) / 255.f));
  targetTurn = targetRotation / MAX_FEEDBACK;
  targetPos = targetRotation % MAX_FEEDBACK;
  pos = analogRead(FEEDBACK_PIN);
  oldPos = pos;

  servoMotor.attach(SERVO_PIN);
  startRotate();
  servoMotor.writeMicroseconds(1500); // servo will stop rotating when reaching 1.5ms
  servoMotor.detach();
}

void setup() {
  pinMode(FEEDBACK_PIN, INPUT);
  wifiSetup();
  espalexa.addDevice("star", deviceChanged);
  espalexa.begin();
}

void loop() {
  espalexa.loop();
  delay(1);
}
