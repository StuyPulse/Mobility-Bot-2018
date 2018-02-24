/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <math.h>

// Robot Dimensions
    constexpr double DISTANCE_LINE_SENSOR_IS_FROM_FRONT_BUMPER_OF_BOT = 3.75; //
    constexpr double LENGTH_OF_BOT = 39.5; // (not including grabber)
    constexpr double WIDTH_OF_BOT = 34.5; //
    constexpr double MIDDLE_OF_BOT_LENGTHWISE = LENGTH_OF_BOT / 2;
    constexpr double MIDDLE_OF_BOT_WIDTHWISE = WIDTH_OF_BOT / 2;
    constexpr double DIFFERENCE_BETWEEN_LENGTH_OF_ROBOT_AND_WIDTH_OF_ROBOT_AFTER_TURN = (LENGTH_OF_BOT - WIDTH_OF_BOT) / 2;

// Gamepad Ports
    constexpr int DRIVER_GAMEPAD_PORT = 0;
    constexpr int OPERATOR_GAMEPAD_PORT = 1;

// Drivetrain Motor Ports
    constexpr int DRIVETRAIN_LEFT_TOP_MOTOR_PORT = 3;
    constexpr int DRIVETRAIN_LEFT_MIDDLE_MOTOR_PORT = 2;
    constexpr int DRIVETRAIN_LEFT_BOTTOM_MOTOR_PORT = 1;

    constexpr int DRIVETRAIN_RIGHT_TOP_MOTOR_PORT = 6;
    constexpr int DRIVETRAIN_RIGHT_MIDDLE_MOTOR_PORT = 5;
    constexpr int DRIVETRAIN_RIGHT_BOTTOM_MOTOR_PORT = 4;

// Drivetrain Encoder/Movement Constants
    constexpr double DRIVETRAIN_WHEEL_DIAMETER = 6.0;
    constexpr int DRIVETRAIN_ENCODERS_PULSES_PER_REVOLUTION = 256;
    constexpr int DRIVETRAIN_ENCODERS_FACTOR = 4; // encoder has four quadrants
    constexpr double DRIVETRAIN_ENCODERS_INCHES_PER_REVOLUTION = M_PI * DRIVETRAIN_WHEEL_DIAMETER;

    constexpr double DRIVETRAIN_RAW_MULTIPLIER =
           (161.5 / 1210.0) * DRIVETRAIN_ENCODERS_INCHES_PER_REVOLUTION
           / (DRIVETRAIN_ENCODERS_PULSES_PER_REVOLUTION * DRIVETRAIN_ENCODERS_FACTOR);

// Spatula and CrabArm Constants (in seconds)
    constexpr double PRE_FLIP_WAIT_TIME = 0.25;
    constexpr double POST_FLIP_WAIT_TIME = 0.5;
    constexpr double FLAP_OUT_SPEED = 1;

// Spatula Motor Ports
    constexpr int SPATULA_LEFT_MOTOR_PORT = 11;
    constexpr int SPATULA_RIGHT_MOTOR_PORT = 12;

// Spatula Limit Switch
    constexpr int SPATULA_LIMIT_SWITCH_PORT = 1;

// Lift Motor Ports
    constexpr int LIFT_INNER_LEFT_MOTOR_PORT = 7;
    constexpr int LIFT_INNER_RIGHT_MOTOR_PORT = 9;
    constexpr int LIFT_OUTER_LEFT_MOTOR_PORT = 8;
    constexpr int LIFT_OUTER_RIGHT_MOTOR_PORT = 10;

// Lift Constants
    constexpr double LIFT_DIAMETER_OF_ENCODER_SPROCKET = 2.873;
    constexpr double LIFT_TOTAL_CARRIAGE_MOVEMENT = 92.25;
    constexpr double LIFT_ENCODER_RAW_MULTIPLIER = LIFT_DIAMETER_OF_ENCODER_SPROCKET * M_PI * 3 / 1024;

    constexpr double MIN_HEIGHT_OF_LIFT = 23;
    constexpr double MAX_HEIGHT_OF_LIFT = LIFT_TOTAL_CARRIAGE_MOVEMENT + MIN_HEIGHT_OF_LIFT;
    constexpr double LIFT_MAX_SPEED = 1;
    constexpr double LIFT_BRAKE_SPEED = 0.16667;

    constexpr double LIFT_MIN_SPEED = 0.25;
    constexpr double LIFT_RAMP_HEIGHT_THRESHOLD = 20.0;
    constexpr double LIFT_RAMP_SLOPE = (LIFT_MAX_SPEED - LIFT_MIN_SPEED) / LIFT_RAMP_HEIGHT_THRESHOLD;
    constexpr double LIFT_JOYSTICK_MOVE_THRESHOLD = .05;
    constexpr double LIFT_CLOSE_ENOUGH_HEIGHT_THRESHOLD = 2;

// Lift Limit Switch
    constexpr int LIFT_TOP_LIMIT_SWITCH_PORT = 2;
    constexpr int LIFT_BOTTOM_LIMIT_SWITCH_PORT = 0;

// CrabArm Ports
    constexpr int CRAB_ARM_LEFT_MOTOR_PORT = 13;
    constexpr int CRAB_ARM_RIGHT_MOTOR_PORT = 14;

// Crab Arm Flap Constants
    constexpr double CRAB_ARM_COAST_POWER = 0.5;
    constexpr double CRAB_ARM_PUSH_POWER = 0.5;

// Solenoid Ports
    constexpr int GEAR_SHIFT_CHANNEL = 7;

    constexpr int GRABBER_SOLENOID_OPEN_PORT = 2;
    constexpr int GRABBER_SOLENOID_CLOSE_PORT = 3;

    constexpr int SPATULA_FLIP_UP_PORT = 6;
    constexpr int SPATULA_FLIP_DOWN_PORT = 5;

// Analog Ports
    constexpr int DRIVETRAIN_LINE_SENSOR_LEFT_PORT = 1;
    constexpr int DRIVETRAIN_LINE_SENSOR_RIGHT_PORT = 2;



