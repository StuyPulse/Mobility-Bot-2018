#include "SpatulaMoveSpeedCommand.h"
#include <Robot.cpp>

SpatulaMoveSpeedCommand::SpatulaMoveSpeedCommand(double speed) {
	this->speed = speed;
	void Requires(Robot::spatula.get());
}

void SpatulaMoveSpeedCommand::Execute() {
	Robot::spatula->AcquireSpeed(speed);
}

bool SpatulaMoveSpeedCommand::IsFinished() {
	return false;
}

void SpatulaMoveSpeedCommand::End() {
	Robot::spatula->Stop();
}
