#include "LiftMoveToHeightCommand.h"
#include <Robot.cpp>
#include <math.h>
#include <RobotMap.h>

LiftMoveToHeightCommand::LiftMoveToHeightCommand(double height) {
	targetHeight = height;
	void Requires(Robot::lift.get());
}

void LiftMoveToHeightCommand::Execute() {
	Robot::lift->SetHeight(targetHeight);
}

bool LiftMoveToHeightCommand::IsFinished() {
    return (abs(Robot::lift->GetLiftHeight() - targetHeight) < LIFT_CLOSE_ENOUGH_HEIGHT_THRESHOLD)
            || (Robot::lift->IsAtBottom() && Robot::lift->GetMotorVelocity() < 0)
            || (Robot::lift->IsAtTop() && Robot::lift->GetMotorVelocity() > 0);
}

void LiftMoveToHeightCommand::End() {
	Robot::lift->Stop();
}

