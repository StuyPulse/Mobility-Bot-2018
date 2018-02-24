#include "SpatulaFlipUpCommand.h"
#include <Robot.cpp>

SpatulaFlipUpCommand::SpatulaFlipUpCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaFlipUpCommand::Initialize() {
	Robot::spatula->FlipUp();
}
