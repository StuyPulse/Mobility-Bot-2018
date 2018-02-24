#include "SpatulaRightDeacquireCommand.h"
#include <Robot.cpp>

SpatulaRightDeacquireCommand::SpatulaRightDeacquireCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaRightDeacquireCommand::Execute() {
	Robot::spatula->RightSpatulaDeacquire();
}

bool SpatulaRightDeacquireCommand::IsFinished() {
	return false;
}

void SpatulaRightDeacquireCommand::End() {
	Robot::spatula->Stop();
}

