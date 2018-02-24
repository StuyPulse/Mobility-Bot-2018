/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string>

	// Gamepad ports
    constexpr int DRIVER_GAMEPAD = 0;
    constexpr int OPERATOR_GAMEPAD = 1;

    // Drivetrain CANTalon channels
    constexpr int RIGHT_FRONT_MOTOR_PORT = 1;
    constexpr int RIGHT_REAR_MOTOR_PORT = 2;
    constexpr int LEFT_REAR_MOTOR_PORT = 3;
    constexpr int LEFT_FRONT_MOTOR_PORT = 4;

    // CANTalon channels for other subsystems
    constexpr int HOPPER_MOTOR_CHANNEL = 5;
    constexpr int ACQUIRER_MOTOR_CHANNEL = 6;
    constexpr int SHOOTER_MOTOR_CHANNEL = 7;
    constexpr int DROPDOWN_MOTOR_CHANNEL = 8;

    // Solenoid ports
    constexpr int HOOD_SOLENOID_CHANNEL = 6;
    constexpr int GEAR_SHIFT_CHANNEL = 3;

    // Tuneable threshold for current (used in gear shifting for drivetrain)
    constexpr int GEAR_SHIFT_THRESHOLD = 40;

    // DropDown Constants
    constexpr double DROP_DOWN_DEADBAND = 0.01;

    // Hood Constants
    constexpr bool HOOD_UP_POSITION = true;
    constexpr bool HOOD_DOWN_POSITION = false;

    // Hopper Constants
    constexpr double HOPPER_SENSOR_THRESHOLD = 1.25;

    // Digital IO Ports
    constexpr int LEFT_ENCODER_CHANNEL_A = 0;
    constexpr int LEFT_ENCODER_CHANNEL_B = 1;
    constexpr int RIGHT_ENCODER_CHANNEL_A = 2;
    constexpr int RIGHT_ENCODER_CHANNEL_B = 3;
    constexpr int SHOOTER_ENCODER_A_CHANNEL = 4;
    constexpr int SHOOTER_ENCODER_B_CHANNEL = 5;
    constexpr int LIMIT_SWITCH_CHANNEL = 6;
    constexpr int FLASHLIGHT_CHANNEL = 7;

    // Analog ports
    constexpr int ACQUIRER_POTENTIOMETER_CHANNEL = 0;
    constexpr int HOPPER_SENSOR_CHANNEL = 3;

    // Potentiometer
    constexpr double INITIAL_VOLTAGE = 287.5; // Equal to 0 degrees
    constexpr double CONVERSION_FACTOR = 11.25;
    constexpr double EPSILON = 0.0005;

    // Physical constants
    constexpr int SHOOTER_WHEEL_DIAMETER = 4;
    constexpr double SHOOTER_ENCODER_MAXSPEED = 3600.0;
    constexpr int DIO_ENCODER_PULSES_PER_REVOLUTION = 360;
    constexpr int DRIVETRAIN_WHEEL_DIAMETER = 8;
    constexpr double DRIVETRAIN_WHEEL_CIRCUMFERENCE = DRIVETRAIN_WHEEL_DIAMETER * M_PI;
    constexpr double DRIVETRAIN_ENCODER_INCHES_PER_PULSE = DRIVETRAIN_WHEEL_CIRCUMFERENCE / DIO_ENCODER_PULSES_PER_REVOLUTION;
    constexpr double DISTANCE_BETWEEN_SONAR = 1.0;

    // Sonar
    constexpr int SONAR_ERROR_MARGIN = 5;
    constexpr double DISTANCE_TO_WALL = 14 * 12; // 14ft in inches

    // PID tuning values
    constexpr double PID_MAX_ROBOT_SPEED = 0.75;
    constexpr double GYRO_P = 1.0;
    constexpr double GYRO_I = 1.0;
    constexpr double GYRO_D = 1.0;

    // Smart Dashboard
    constexpr std::string SHOOTER_SPEED_LABEL = "Shooter Speed";

    // Auton
    constexpr double ROCK_WALL_CURRENT_THRESHOLD = 0.0;
    constexpr int ARM_CROSSING_OBSTACLE_ANGLE = 50;

    constexpr double SLOT_ANGLE_TO_GOAL_1 = 39.614; // UNUSED (lowbar)
    constexpr double SLOT_ANGLE_TO_GOAL_2 = 29.535;
    constexpr double SLOT_ANGLE_TO_GOAL_3 = 16.987;
    constexpr double SLOT_ANGLE_TO_GOAL_4 = -12.228;
    constexpr double SLOT_ANGLE_TO_GOAL_5 = -25.539;

    // CV
    constexpr double MAX_DEGREES_OFF_AUTO_AIMING = 1.0;
    constexpr int CAMERA_FRAME_PX_HEIGHT = 270;
    constexpr int CAMERA_FRAME_PX_WIDTH = 360;
    constexpr double CAMERA_TILT_ANGLE = 34;
    constexpr double CAMERA_DIST_TO_BOT_FRONT = 28.0; // from camera to low omniwheel on arm when arm lowered

    constexpr double CAMERA_VIEWING_ANGLE_X = 61; // angular height of frame
    constexpr double CAMERA_VIEWING_ANGLE_Y = 34.3; // angular width of frame
    constexpr double LAYUP_SHOOTING_DISTANCE = 3.8 * 12.0; // front omniwheel (on arm) 4 ft from tower
    constexpr double COURTYARD_SHOOTING_DISTANCE = 103.1; // front omniwheel (on arm) 8 ft from tower

    constexpr double HIGH_GOAL_HEIGHT = 90.0; // inches to center of goal from floor (measured)
    constexpr double CAMERA_HEIGHT_FROM_GROUND = 29.0; // inches

    // Signal Lights
    constexpr int SIGNAL_LIGHT_RED_PORT = 4;
    constexpr int SIGNAL_LIGHT_YELLOW_PORT = 5;
    constexpr int SIGNAL_LIGHT_BLUE_PORT = 6;

    // Operator IDs
    constexpr int JONAH_ID = 0;
    constexpr int YUBIN_ID = 1;
