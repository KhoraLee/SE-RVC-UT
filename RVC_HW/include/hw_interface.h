#ifndef _hw_interface_h
#define _hw_interface_h

typedef enum _CleanerCommand {
    OFF,
    ON
} CleanerCommand;

typedef enum _motorSatus {
    ENABLE,
    DISABLE
} MotorStatus;

// Sensor
int front_sensor_status(); // 전방 감지 센서
int left_sensor_status(); // 좌측 감지 센서
int right_sensor_status(); // 우측 감지 센서
int dust_sensor_status(); // 먼지 감지 센서

// Motor
void move_forward(MotorStatus status); // 전진 상태 변경
void move_backward(MotorStatus status); // 후진 상태 변경
void turn_left(); // 좌회전
void turn_right(); // 우회전

// Cleaner
void cleaner(CleanerCommand command); // 클리너 On/Off 컨트롤
void cleaner_power_up(); // 5틱간 터보 모드

#endif