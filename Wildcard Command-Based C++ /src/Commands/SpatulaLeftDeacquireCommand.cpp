#include "SpatulaLeftDeacquireCommand.h"
#include <Robot.cpp>

SpatulaLeftDeacquireCommand::SpatulaLeftDeacquireCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaLeftDeacquireCommand::Execute() {
	Robot::spatula->LeftSpatulaDeacquire();
}

bool SpatulaLeftDeacquireCommand::IsFinished() {
	return false;
}

void SpatulaLeftDeacquireCommand::End() {
	Robot::spatula->Stop();
}
