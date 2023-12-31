/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_HW_INTERFACE_H
#define _MOCK_HW_INTERFACE_H

#include "unity.h"
#include "hw_interface.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void mock_hw_interface_Init(void);
void mock_hw_interface_Destroy(void);
void mock_hw_interface_Verify(void);




#define front_sensor_status_ExpectAndReturn(cmock_retval) front_sensor_status_CMockExpectAndReturn(__LINE__, cmock_retval)
void front_sensor_status_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define left_sensor_status_ExpectAndReturn(cmock_retval) left_sensor_status_CMockExpectAndReturn(__LINE__, cmock_retval)
void left_sensor_status_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define right_sensor_status_ExpectAndReturn(cmock_retval) right_sensor_status_CMockExpectAndReturn(__LINE__, cmock_retval)
void right_sensor_status_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define dust_sensor_status_ExpectAndReturn(cmock_retval) dust_sensor_status_CMockExpectAndReturn(__LINE__, cmock_retval)
void dust_sensor_status_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define move_forward_Expect(status) move_forward_CMockExpect(__LINE__, status)
void move_forward_CMockExpect(UNITY_LINE_TYPE cmock_line, MotorStatus status);
#define move_backward_Expect(status) move_backward_CMockExpect(__LINE__, status)
void move_backward_CMockExpect(UNITY_LINE_TYPE cmock_line, MotorStatus status);
#define turn_left_Expect() turn_left_CMockExpect(__LINE__)
void turn_left_CMockExpect(UNITY_LINE_TYPE cmock_line);
#define turn_right_Expect() turn_right_CMockExpect(__LINE__)
void turn_right_CMockExpect(UNITY_LINE_TYPE cmock_line);
#define cleaner_Expect(command) cleaner_CMockExpect(__LINE__, command)
void cleaner_CMockExpect(UNITY_LINE_TYPE cmock_line, CleanerCommand command);
#define cleaner_power_up_Expect() cleaner_power_up_CMockExpect(__LINE__)
void cleaner_power_up_CMockExpect(UNITY_LINE_TYPE cmock_line);

#ifdef __cplusplus
}
#endif

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
