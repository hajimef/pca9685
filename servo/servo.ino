#include <Wire.h>
#include <Adafruit_PWMServoDrrv.h>

#define SERVOMIN  130
#define SERVOMAX  500
#define SERVO_FREQ 50
#define SERVO_CH_MIN 4
#define SERVO_CH_MAX 7

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  uint8_t i;

  Serial.begin(115200);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  delay(10);
  for (i = SERVO_CH_MIN; i <= SERVO_CH_MAX; i++) {
    pwm.setPWM(i, 0, (SERVOMIN + SERVOMAX) / 2);
  }
  delay(2000);
}

void loop() {
  uint8_t i;
  uint16_t pulselen;

  Serial.println("min to max");
  
  for (pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    for (i = SERVO_CH_MIN; i <= SERVO_CH_MAX; i++) {
      pwm.setPWM(i, 0, pulselen);
    }
    delay(10);
  }
  Serial.println("max to min");
  for (pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    for (i = SERVO_CH_MIN; i <= SERVO_CH_MAX; i++) {
      pwm.setPWM(i, 0, pulselen);
    }
    delay(10);
  }
}
