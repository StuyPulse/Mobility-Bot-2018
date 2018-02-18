/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/Drivetrain.h>
#include "../RobotMap.h"

Drivetrain::Drivetrain() :
	Subsystem("Drivetrain") {
	TopLeftMotor = RobotMap::TOP_LEFT_MOTOR;
	TopRightMotor = RobotMap::TOP_RIGHT_MOTOR;
	BottomLeftMotor = RobotMap::BOTTOM_LEFT_MOTOR;
	BottomRightMotor = RobotMap::BOTTOM_RIGHT_MOTOR;
}
void Drivetrain::InitDefaultCommand() {

}
void Drivetrain::MoveForward() {
	TopLeftMotor->Set(1);
	TopRightMotor->Set(1);
	BottomLeftMotor->Set(1);
	BottomRightMotor->Set(1);
}
