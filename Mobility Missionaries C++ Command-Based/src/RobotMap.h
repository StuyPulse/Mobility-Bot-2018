/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <math.h>

	constexpr int DRIVER_PAD_PORT = 0;
	constexpr int OPERATOR_PAD_PORT = 1;

	constexpr int RIGHT_FRONT_MOTOR_PORT = 1;
	constexpr int RIGHT_REAR_MOTOR_PORT = 2;
	constexpr int LEFT_REAR_MOTOR_PORT = 3;
	constexpr int LEFT_FRONT_MOTOR_PORT = 4;

	constexpr int HOPPER_MOTOR_PORT = 5;

	constexpr int ACQUIRER_MOTOR_PORT = 6;

	constexpr int SHOOTER_MOTOR_PORT = 7;

	constexpr int DROP_DOWN_MOTOR_PORT = 8;

	constexpr int LEFT_ENCODER_CHANNEL_A = 0;
	constexpr int LEFT_ENCODER_CHANNEL_B = 1;
	constexpr int RIGHT_ENCODER_CHANNEL_A = 2;
	constexpr int RIGHT_ENCODER_CHANNEL_B = 3;

	constexpr int DIAMETER_OF_WHEELS = 8;
	constexpr double CIRCUMFERENCE_OF_WHEELS = 8 * M_PI;
	constexpr int DIO_ENCODER_PULSES_PER_REVOLUTION = 360;
	constexpr double DRIVETRAIN_ENCODER_INCHES_PER_PULSE = CIRCUMFERENCE_OF_WHEELS / DIO_ENCODER_PULSES_PER_REVOLUTION;
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
