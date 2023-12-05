#include "unity.h"
#include "rvc.h"
#include "mock_hw_interface.h"

void setUp(void) { }
void tearDown(void) { }

void test_check_obstacle_withNoObstacle() {
    front_sensor_status_ExpectAndReturn(0);
    left_sensor_status_ExpectAndReturn(0);
    right_sensor_status_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL(check_obstacle(), NONE);
}

void test_check_obstacle_withFrontObstacle() {
    front_sensor_status_ExpectAndReturn(1);
    left_sensor_status_ExpectAndReturn(0);
    right_sensor_status_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL(check_obstacle(), FRONT);
}

void test_check_obstacle_withLeftObstacle() {
    front_sensor_status_ExpectAndReturn(0);
    left_sensor_status_ExpectAndReturn(1);
    right_sensor_status_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL(check_obstacle(), LEFT);
}

void test_check_obstacle_withRightObstacle() {
    front_sensor_status_ExpectAndReturn(0);
    left_sensor_status_ExpectAndReturn(0);
    right_sensor_status_ExpectAndReturn(1);
    TEST_ASSERT_EQUAL(check_obstacle(), RIGHT);
}

void test_check_obstacle_withFrontLeftObstacle() {
    front_sensor_status_ExpectAndReturn(1);
    left_sensor_status_ExpectAndReturn(1);
    right_sensor_status_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL(check_obstacle(), FRONT | LEFT);
}

void test_check_obstacle_withFrontRightObstacle() {
    front_sensor_status_ExpectAndReturn(1);
    left_sensor_status_ExpectAndReturn(0);
    right_sensor_status_ExpectAndReturn(1);

    TEST_ASSERT_EQUAL(check_obstacle(), FRONT | RIGHT);
}

void test_check_obstacle_withLeftRightObstacle() {
    front_sensor_status_ExpectAndReturn(0);
    left_sensor_status_ExpectAndReturn(1);
    right_sensor_status_ExpectAndReturn(1);
    TEST_ASSERT_EQUAL(check_obstacle(), LEFT | RIGHT);
}

void test_check_obstacle_withFrontLeftRightObstacle() {
    front_sensor_status_ExpectAndReturn(1);
    left_sensor_status_ExpectAndReturn(1);
    right_sensor_status_ExpectAndReturn(1);
    TEST_ASSERT_EQUAL(check_obstacle(), FRONT | LEFT | RIGHT);
}

void test_check_dust_withNoDust() {
    dust_sensor_status_ExpectAndReturn(0);
    TEST_ASSERT_EQUAL(check_dust(), 0);
}

void test_check_dust_withDust() {
    dust_sensor_status_ExpectAndReturn(1);
    TEST_ASSERT_EQUAL(check_dust(), 1);
}

void test_cleaner_control_withDustWhileMoveForward() {
    move_forward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    cleaner_power_up_Expect();
    cleaner_control(1, FORWARD);
}

void test_cleaner_control_withNoDustWhileMoveForward() {
    cleaner_control(0, FORWARD);
    // No Assert or Expectation as it is intended to do nothing
}

void test_motor_control_withNoObstacleWhileMoveForward() {
    Direction dir = FORWARD;
    motor_control(NONE, &dir);
    TEST_ASSERT_EQUAL(dir, FORWARD);
}

void test_motor_control_withLeftRightObstacleWhileMoveForward() {
    Direction dir = FORWARD;
    motor_control(LEFT | RIGHT, &dir);
    TEST_ASSERT_EQUAL(dir, FORWARD);
}

void test_motor_control_withFrontLeftRightObstacleWhileMoveForward() {
    Direction dir = FORWARD;
    move_forward_Expect(DISABLE);
    cleaner_Expect(OFF);
    move_backward_Expect(ENABLE);
    motor_control(FRONT | LEFT | RIGHT, &dir);
    TEST_ASSERT_EQUAL(dir, BACKWARD);
}

void test_motor_control_withFrontLeftObstacleWhileMoveForward() {
    Direction dir = FORWARD;
    move_forward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    cleaner_Expect(OFF);
    cleaner_Expect(ON);
    turn_right_Expect();
    motor_control(FRONT | LEFT, &dir);
    TEST_ASSERT_EQUAL(dir, FORWARD);
}

void test_motor_control_withFrontRightObstacleWhileMoveForward() {
    Direction dir = FORWARD;
    move_forward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    cleaner_Expect(OFF);
    cleaner_Expect(ON);
    turn_left_Expect();
    motor_control(FRONT | RIGHT, &dir);
    TEST_ASSERT_EQUAL(dir, FORWARD);
}

void test_motor_control_withLeftRightObstacleWhileMovebackward() {
    Direction dir = BACKWARD;
    // Run
    motor_control(LEFT | RIGHT, &dir);

    // Assert
    TEST_ASSERT_EQUAL(dir, BACKWARD);
}

void test_motor_control_withNoLeftRightObstacleWhileMovebackward() {
    Direction dir = BACKWARD;
    // Expectation
    move_backward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    turn_left_Expect();
    cleaner_Expect(ON);

    // Run
    motor_control(NONE, &dir);

    // Assert
    TEST_ASSERT_EQUAL(dir, FORWARD);
}


void test_motor_control_withNoLeftObstacleWhileMovebackward() {
    Direction dir = BACKWARD;
    // Expectation
    move_backward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    turn_left_Expect();
    cleaner_Expect(ON);

    // Run
    motor_control(RIGHT, &dir);

    // Assert
    TEST_ASSERT_EQUAL(dir, FORWARD);
}

void test_motor_control_withNoRightObstacleWhileMovebackward() {
    Direction dir = BACKWARD;
    // Expectation
    move_backward_Expect(DISABLE);
    move_forward_Expect(ENABLE);
    turn_right_Expect();
    cleaner_Expect(ON);

    // Run
    motor_control(LEFT, &dir);

    // Assert
    TEST_ASSERT_EQUAL(dir, FORWARD);
}