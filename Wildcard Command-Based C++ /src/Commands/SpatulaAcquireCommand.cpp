#include "SpatulaAcquireCommand.h"
#include <Robot.cpp>

SpatulaAcquireCommand::SpatulaAcquireCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaAcquireCommand::Execute() {
	Robot::spatula->Acquire();
}

bool SpatulaAcquireCommand::IsFinished() {
	return false;
}

void SpatulaAcquireCommand::End() {
	Robot::spatula->Stop();
}
