#include "SpatulaFlipToggleCommand.h"
#include <Robot.cpp>

SpatulaFlipToggleCommand::SpatulaFlipToggleCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaFlipToggleCommand::Initialize() {
	Robot::spatula->Toggle();
}
