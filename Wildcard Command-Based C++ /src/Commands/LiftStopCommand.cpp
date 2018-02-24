#include "LiftStopCommand.h"
#include "Robot.cpp"

LiftStopCommand::LiftStopCommand() {
	void Requires(Robot::lift.get());
}

// Called once when the command executes
void LiftStopCommand::Initialize() {
	Robot::lift->Stop();
}
