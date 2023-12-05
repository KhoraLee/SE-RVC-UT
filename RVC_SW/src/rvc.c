#include <stdio.h>

#include "rvc.h"
#include "hw_interface.h"

void waitTick(int i) { }

void rvc_main() {
    Direction dir;

    move_forward(ENABLE);
    dir = FORWARD;
    cleaner(ON);

    while(1){
        waitTick(1); // emulate 1 tick
        int obstacle = check_obstacle();
        int dust = check_dust();
        cleaner_control(dust, dir);
        motor_control(obstacle, &dir);
    }
}

int check_obstacle() {
    int result = NONE;
    if (front_sensor_status() == 1) 
        result |= FRONT;
    if (left_sensor_status() == 1) 
        result |= LEFT;
    if (right_sensor_status() == 1) 
        result |= RIGHT;
    return result;
}

int check_dust() {
    return dust_sensor_status();
}

void motor_control(int obstacle, Direction *dir) {
    int F = obstacle & FRONT;
    int L = obstacle & LEFT;
    int R = obstacle & RIGHT;
    if (F && !L && *dir == FORWARD) { // 직진중 전방 막힘. 왼쪽 회전
        move_forward(DISABLE);
        cleaner(OFF);
        turn_left(); // takes 5 ticks to finish
        cleaner(ON);
        move_forward(ENABLE);
    } else if (F && !R && L && *dir == FORWARD) { // 직진중 전방 & 왼쪽 막힘. 오른쪽 회전
        move_forward(DISABLE);
        cleaner(OFF);
        turn_right(); // takes 5 ticks to finish
        cleaner(ON);
        move_forward(ENABLE);
    } else if (F && L && R && *dir == FORWARD) { // 직진중 다 막힘. 후진
        move_forward(DISABLE);
        cleaner(OFF);
        move_backward(ENABLE);
        *dir = BACKWARD;
    } else if (!L && *dir == BACKWARD) { // 후진중 왼쪽 턴 가능
        move_backward(DISABLE);
        turn_left(); // takes 5 ticks to finish
        move_forward(ENABLE);
        cleaner(ON);  
        *dir = FORWARD;            
    } else if (L && !R && *dir == BACKWARD) { // 후진중 오른쪽 턴 가능
        move_backward(DISABLE);
        turn_right(); // takes 5 ticks to finish
        move_forward(ENABLE);
        cleaner(ON);           
        *dir = FORWARD;
    }
}

void cleaner_control(int dust, Direction dir) {
    if(dust && dir == FORWARD){
        move_forward(DISABLE);
        cleaner_power_up();
        move_forward(ENABLE);
    }
}
