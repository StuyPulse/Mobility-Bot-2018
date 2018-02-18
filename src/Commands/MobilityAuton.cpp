/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/MobilityAuton.h>

MobilityAuton::MobilityAuton() {
	Requires(Robot::Drivetrain);
}

// Called just before this Command runs the first time
void MobilityAuton::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MobilityAuton::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool MobilityAuton::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MobilityAuton::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MobilityAuton::Interrupted() {}
