#include <AFMotor.h>
#define R_MAX 215
#define L_MAX 255

// Motor L293D 3:M3, 4:M4
AF_DCMotor motor_L(3);
AF_DCMotor motor_R(4);

void cmd() {
  byte DataToRead[3];
  DataToRead[2] = '\n';
  Serial.readBytesUntil(char(13), DataToRead, 3);

  char direction_type = DataToRead[0]; // L R l r G B
  int i = 1;
  while (DataToRead[i] != '\n' && i < 3) i++;

  switch (direction_type) {
    case 'L':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(RELEASE);
      motor_R.run(FORWARD);
      delay(200);
      break;
    case 'R':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(FORWARD);
      motor_R.run(RELEASE);
      delay(200);
      break;
    case 'l':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(RELEASE);
      motor_R.run(FORWARD);
      delay(120);
      break;
    case 'r':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(FORWARD);
      motor_R.run(RELEASE);
      delay(120);
      break;
    case 'G':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(FORWARD);
      motor_R.run(FORWARD);
      delay(300);
      break;
    case 'B':
      motor_L.setSpeed(L_MAX);
      motor_R.setSpeed(R_MAX);
      motor_L.run(BACKWARD);
      motor_R.run(BACKWARD);
      delay(250);
    default:
      motor_L.run(RELEASE);
      motor_R.run(RELEASE);
      break;
  }
  
  // For Debugging, send string to RPi
  delay(100);
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  Serial.write("ACK\n");
}

void setup() {
  Serial.begin(9600);
  
  motor_L.setSpeed(L_MAX);
  motor_R.setSpeed(R_MAX);
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
}

void test() {
  motor_L.setSpeed(L_MAX);
  motor_R.setSpeed(R_MAX);
  motor_L.run(FORWARD);
  motor_R.run(FORWARD);
  delay(2000);
}

void loop() {
  /*while (1) {
    test();
  }*/
  cmd();
}
