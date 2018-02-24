#include "SpatulaFlipDownCommand.h"
#include <Robot.cpp>

SpatulaFlipDownCommand::SpatulaFlipDownCommand() {
	void Requires(Robot::spatula.get());
}

void SpatulaFlipDownCommand::Initialize() {
	Robot::spatula->FlipDown();
}
