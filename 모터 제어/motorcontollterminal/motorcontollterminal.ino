int motorPin1A = 2;   // 첫 번째 모터의 PWM 핀
int motorPin2A = 3;   // 첫 번째 모터의 디지털 핀

int motorPin1B = 5;   // 두 번째 모터의 PWM 핀
int motorPin2B = 6;   // 두 번째 모터의 디지털 핀

int motorPin1C = 9;   // 세 번째 모터의 PWM 핀
int motorPin2C = 8;   // 세 번째 모터의 디지털 핀

int motorPin1D = 12;   // 네 번째 모터의 PWM 핀
int motorPin2D = 11;   // 네 번째 모터의 디지털 핀

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
  Serial3.begin(115200);
}

void loop() {
  if (Serial3.available() > 0) {
    String command = Serial3.readStringUntil('\n');  // 시리얼로 받은 명령어 전체 읽기
    String command0 = Serial.readStringUntil('\n');  // 시리얼로 받은 명령어 전체 읽기
    char motor = command.charAt(0);  // 모터 번호를 추출 (a, b, c, d 또는 s)
    int speed = command.substring(2).toInt();  // 속도 값을 추출 (공백 이후)

    char ch = command0.charAt(0);  // 모터 번호를 추출 (a, b, c, d 또는 s)
    Serial.println("%d",ch);
    if (motor == 'a') {  // 모터 1 제어
        analogWrite(motorPin1A, speed);
        digitalWrite(motorPin2A, LOW);
    } else if (motor == 'b') {  // 모터 2 제어
        analogWrite(motorPin1B, speed);
        digitalWrite(motorPin2B, LOW);
    } else if (motor == 'c') {  // 모터 3 제어
        analogWrite(motorPin1C, speed);
        digitalWrite(motorPin2C, LOW);
    } else if (motor == 'd') {  // 모터 4 제어
        analogWrite(motorPin1D, speed);
        digitalWrite(motorPin2D, LOW);
    } else if (motor == 's') {  // 전체 모터 정지
        analogWrite(motorPin1A, 0);
        analogWrite(motorPin2A, 0);
        analogWrite(motorPin1B, 0);
        analogWrite(motorPin2B, 0);
        analogWrite(motorPin1C, 0);
        analogWrite(motorPin2C, 0);
        analogWrite(motorPin1D, 0);
        analogWrite(motorPin2D, 0);
       // Serial.println("모든 모터 정지");
    }
  }
}
