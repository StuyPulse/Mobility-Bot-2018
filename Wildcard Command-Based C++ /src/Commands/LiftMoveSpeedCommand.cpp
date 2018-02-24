#include "LiftMoveSpeedCommand.h"
#include <Robot.cpp>

LiftMoveSpeedCommand::LiftMoveSpeedCommand(double speed) {
	this->speed = speed;
	void Requires(Robot::lift.get());
}

void LiftMoveSpeedCommand::Execute() {
	Robot::lift->Move(speed);
}

bool LiftMoveSpeedCommand::IsFinished() {
	return false;
}

void LiftMoveSpeedCommand::End() {
	Robot::lift->Stop();
}
