int motorPin1A = 2;   // 첫 번째 모터의 PWM 핀
int motorPin2A = 3;   // 첫 번째 모터의 디지털 핀

int motorPin1B = 5;   // 두 번째 모터의 PWM 핀
int motorPin2B = 6;   // 두 번째 모터의 디지털 핀

int motorPin1C = 9;   // 세 번째 모터의 PWM 핀
int motorPin2C = 8;   // 세 번째 모터의 디지털 핀

int motorPin1D = 12;  // 네 번째 모터의 PWM 핀
int motorPin2D = 11;  // 네 번째 모터의 디지털 핀

void setup() {
  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2B, OUTPUT);
  pinMode(motorPin1C, OUTPUT);
  pinMode(motorPin2C, OUTPUT);
  pinMode(motorPin1D, OUTPUT);
  pinMode(motorPin2D, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  // 시리얼로 받은 문자열 전체 읽기
    char direction = command.charAt(0);  // 방향 명령 (f, b, s)
    char motorID = command.charAt(1);    // 모터 ID (A, B, C, D)
    int speed = command.substring(2).toInt();  // 속도 추출

    if (direction == 'f') {  // 전진 명령어
      controlMotor(motorID, speed, LOW);
      Serial.print("모터 ");
      Serial.print(motorID);
      Serial.print(" 전진 속도: ");
      Serial.println(speed);
    } else if (direction == 'b') {  // 후진 명령어
      controlMotor(motorID, LOW, speed);
      Serial.print("모터 ");
      Serial.print(motorID);
      Serial.print(" 후진 속도: ");
      Serial.println(speed);
    } else if (direction == 's') {  // 정지 명령어
      controlMotor(motorID, 0, 0);
      Serial.print("모터 ");
      Serial.print(motorID);
      Serial.println(" 정지");
    }
  }
}

void controlMotor(char motorID, int pin1Speed, int pin2Speed) {
  switch (motorID) {
    case 'A':
      analogWrite(motorPin1A, pin1Speed);
      analogWrite(motorPin2A, pin2Speed);
      break;
    case 'B':
      analogWrite(motorPin1B, pin1Speed);
      analogWrite(motorPin2B, pin2Speed);
      break;
    case 'C':
      analogWrite(motorPin1C, pin1Speed);
      analogWrite(motorPin2C, pin2Speed);
      break;
    case 'D':
      analogWrite(motorPin1D, pin1Speed);
      analogWrite(motorPin2D, pin2Speed);
      break;
  }
}
