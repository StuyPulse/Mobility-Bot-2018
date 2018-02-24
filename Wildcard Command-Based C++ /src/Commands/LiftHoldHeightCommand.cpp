#include "LiftHoldHeightCommand.h"
#include <Robot.cpp>

LiftHoldHeightCommand::LiftHoldHeightCommand() {
	currentHeight = 0;
	void Requires(Robot::lift.get());
}

void LiftHoldHeightCommand::Initialize() {
	currentHeight = Robot::lift->GetLiftHeight();
}

void LiftHoldHeightCommand::Execute() {
	Robot::lift->SetHeight(currentHeight);
}

bool LiftHoldHeightCommand::IsFinished() {
	return false;
}

void LiftHoldHeightCommand::End() {
	Robot::lift->Stop();
}

