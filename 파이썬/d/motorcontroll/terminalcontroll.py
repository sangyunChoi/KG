import serial

# 시리얼 포트를 설정합니다. COM 포트와 보드레이트는 환경에 맞게 변경하세요.
serial_port = serial.Serial('COM3', 115200)

def send_command(command):
    serial_port.write(f"{command}\n".encode())  # 명령어를 시리얼 포트를 통해 전송
    print(f"Command sent: {command}")

if __name__ == "__main__":
    while True:
        try:
            command = input("Enter motor command (motor controll): ")
            send_command(command)
        except KeyboardInterrupt:
            print("Exiting...")
            serial_port.close()  # 프로그램 종료 시 시리얼 포트를 닫습니다.
            break
