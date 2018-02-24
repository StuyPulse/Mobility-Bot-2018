#include "DrivetrainHighGearCommand.h"
#include <Robot.cpp>

DrivetrainHighGearCommand::DrivetrainHighGearCommand() {
	void Requires(Robot::drivetrain.get());
}

// Called once when the command executes
void DrivetrainHighGearCommand::Initialize() {
	Robot::drivetrain->HighGearShift();
}
