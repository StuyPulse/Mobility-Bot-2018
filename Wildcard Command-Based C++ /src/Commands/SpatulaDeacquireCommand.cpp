#include "SpatulaDeacquireCommand.h"
#include <Robot.cpp>

SpatulaDeacquireCommand::SpatulaDeacquireCommand() {
	void	 Requires(Robot::spatula.get());
}

void SpatulaDeacquireCommand::Execute() {
	Robot::spatula->Deacquire();
}

bool SpatulaDeacquireCommand::IsFinished() {
	return false;
}

void SpatulaDeacquireCommand::End() {
	Robot::spatula->Stop();
}

