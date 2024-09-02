int motorPin1A = 2;   // 첫 번째 모터의 PWM 핀
int motorPin2A = 3;  // 첫 번째 모터의 디지털 핀

int motorPin1B = 5;   // 두 번째 모터의 PWM 핀
int motorPin2B = 6;  // 두 번째 모터의 디지털 핀

int motorPin1C = 8;   // 세 번째 모터의 PWM 핀
int motorPin2C = 9;  // 세 번째 모터의 디지털 핀

int motorPin1D = 11;  // 네 번째 모터의 PWM 핀
int motorPin2D = 12;  // 네 번째 모터의 디지털 핀

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
    if (command.startsWith("f")) {  // 전진 명령어
      int speed = command.substring(1).toInt();  // 명령어 뒤의 숫자를 속도로 추출

      analogWrite(motorPin1A, speed);
      digitalWrite(motorPin2A, LOW);
      
      analogWrite(motorPin1B, speed);
      digitalWrite(motorPin2B, LOW);
      
      analogWrite(motorPin2C, speed);
      digitalWrite(motorPin1C, LOW);
      
      analogWrite(motorPin2D, speed);
      digitalWrite(motorPin1D, LOW);
      
      Serial.print("모터 네 개 전진 속도: ");
      Serial.println(speed);
    }
    
    if (command.startsWith("b")) {  // 후진 명령어
      int speed = command.substring(1).toInt();  // 명령어 뒤의 숫자를 속도로 추출
      
      analogWrite(motorPin2A, speed);
      digitalWrite(motorPin1A, LOW);
      
      analogWrite(motorPin2B, speed);
      digitalWrite(motorPin1B, LOW);
      
      analogWrite(motorPin1C, speed);
      digitalWrite(motorPin2C, LOW);
      
      analogWrite(motorPin1D, speed);
      digitalWrite(motorPin2D, LOW);
      
      Serial.print("모터 네 개 후진 속도: ");
      Serial.println(speed);
    }
    if (command == "s") {  // 정지 명령어
      analogWrite(motorPin2A, 0);
      analogWrite(motorPin2B, 0);
      analogWrite(motorPin1C, 0);
      analogWrite(motorPin1D, 0);

      Serial.println("모터 네 개 정지");
    }
  }
}
