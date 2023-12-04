#include "hw_interface.h"

// Sensor
int front_sensor_status() { return 0; }
int left_sensor_status() { return 0; }
int right_sensor_status() { return 0;}
int dust_sensor_status() { return 0; }

// Motor
void move_forward(MotorStatus status) { }
void move_backward(MotorStatus status) { }
void turn_left() { }
void turn_right() { }

// Cleaner
void cleaner(CleanerCommand command) { } // Cleaner 의 상태를 변경
void cleaner_power_up() { } // power-up the cleaner for 5 ticks
