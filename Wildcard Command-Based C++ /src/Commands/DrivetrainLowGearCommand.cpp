#include "DrivetrainLowGearCommand.h"
#include <Robot.cpp>

DrivetrainLowGearCommand::DrivetrainLowGearCommand() {
	void Requires(Robot::drivetrain.get());
}

void DrivetrainLowGearCommand::Initialize() {
	Robot::drivetrain->LowGearShift();
}
