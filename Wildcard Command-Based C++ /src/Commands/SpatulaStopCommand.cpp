#include "SpatulaStopCommand.h"
#include <Robot.cpp>

SpatulaStopCommand::SpatulaStopCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaStopCommand::Initialize() {
	Robot::spatula->Stop();
}
