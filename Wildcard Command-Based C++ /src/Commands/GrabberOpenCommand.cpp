#include "GrabberOpenCommand.h"
#include <Robot.cpp>

GrabberOpenCommand::GrabberOpenCommand() {
	void Requires(Robot::grabber.get());
}

// Called once when the command executes
void GrabberOpenCommand::Initialize() {
	Robot::grabber->Open();
}
