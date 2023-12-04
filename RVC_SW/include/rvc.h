#pragma once

#ifndef _rvc_h
#define _rvc_h

typedef enum _dir {
    FORWARD,
    BACKWARD,
} Direction;

typedef enum _location {
    Front = 0b0001,
    Left = 0b0010,
    Right = 0b0100,
} Location;


void rvc_main();

// Sensor
// void getSeneorData(int *F, int *L, int *R, int *Dust) { } // 센서 데이터 읽어들임
int check_obstacle(); // 장애물 감지
int check_dust(); // 먼지 탐지

// Cleaner
void cleaner_control(int dust, Direction dir);

// Motor
void motor_control(int obstacle, Direction *dir);

#endif