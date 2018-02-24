#include "LiftMoveToBottomCommand.h"
#include <Robot.cpp>

LiftMoveToBottomCommand::LiftMoveToBottomCommand() {
	void Requires(Robot::lift.get());
}

void LiftMoveToBottomCommand::Execute() {
	Robot::lift->Move(-1);
}

bool LiftMoveToBottomCommand::IsFinished() {
	return Robot::lift->IsAtBottom();
}

void LiftMoveToBottomCommand::End() {
	Robot::lift->Stop();
}
