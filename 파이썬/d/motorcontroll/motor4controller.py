import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QSlider, QPushButton, QHBoxLayout
from PyQt5.QtCore import Qt
import serial

class MotorControlApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        self.serial_port = serial.Serial('COM8', 115200)  # 아두이노의 시리얼 포트 설정
        self.current_direction = None  # 현재 진행 방향을 추적

    def initUI(self):
        layout = QVBoxLayout()

        # 슬라이더를 위한 레이아웃과 라벨
        self.label = QLabel('모터 속도: 0%', self)
        layout.addWidget(self.label)

        self.slider = QSlider(Qt.Horizontal, self)
        self.slider.setRange(0, 255)  # PWM 값 범위
        self.slider.setValue(0)
        self.slider.valueChanged.connect(self.updateLabel)
        layout.addWidget(self.slider)

        # 버튼 레이아웃
        button_layout = QHBoxLayout()

        self.forward_button = QPushButton('전진', self)
        self.forward_button.clicked.connect(self.moveForward)
        button_layout.addWidget(self.forward_button)

        self.backward_button = QPushButton('후진', self)
        self.backward_button.clicked.connect(self.moveBackward)
        button_layout.addWidget(self.backward_button)

        self.stop_button = QPushButton('정지', self)
        self.stop_button.clicked.connect(self.stopMotor)
        button_layout.addWidget(self.stop_button)

        layout.addLayout(button_layout)
        self.setLayout(layout)

        self.setWindowTitle('모터 속도 제어')
        self.show()

    def updateLabel(self, value):
        self.label.setText(f'모터 속도: {value / 255 * 100:.1f}%')

    def moveForward(self):
        self.current_direction = 'f'
        speed = self.slider.value()
        command = f'f{speed}\n'
        self.serial_port.write(command.encode())  # 전진 명령어와 속도를 전송
        print(f"Forward command sent: {command.strip()}")

    def moveBackward(self):
        self.current_direction = 'b'
        speed = self.slider.value()
        command = f'b{speed}\n'
        self.serial_port.write(command.encode())  # 후진 명령어와 속도를 전송
        print(f"Backward command sent: {command.strip()}")

    def stopMotor(self):
        self.current_direction = 'f'
        speed =0
        command = f'f{speed}\n'
        self.serial_port.write(command.encode())  # 전진 명령어와 속도를 전송
        print(f"Forward command sent: {command.strip()}")

    def closeEvent(self, event):
        self.serial_port.close()  # 창을 닫을 때 시리얼 포트 닫기

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MotorControlApp()
    sys.exit(app.exec_())
