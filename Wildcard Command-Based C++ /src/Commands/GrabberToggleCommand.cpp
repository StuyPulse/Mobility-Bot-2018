#include "GrabberToggleCommand.h"
#include <Robot.cpp>

GrabberToggleCommand::GrabberToggleCommand() {
	void Requires(Robot::grabber.get());
}

// Called once when the command executes
void GrabberToggleCommand::Initialize() {
	Robot::grabber->Toggle();
}
