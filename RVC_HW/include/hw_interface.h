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
int front_sensor_status();
int left_sensor_status();
int right_sensor_status();
int dust_sensor_status();

// Motor
void move_forward(MotorStatus status);
void move_backward(MotorStatus status);
void turn_left();
void turn_right();

// Cleaner
void cleaner(CleanerCommand command);
void cleaner_power_up();

#endif