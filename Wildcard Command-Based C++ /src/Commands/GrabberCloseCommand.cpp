#include "GrabberCloseCommand.h"
#include <Robot.cpp>

GrabberCloseCommand::GrabberCloseCommand() {
	void Requires(Robot::grabber.get());
}

// Called once when the command executes
void GrabberCloseCommand::Initialize() {
	Robot::grabber->Close();
}
