#include "CrabArmDeployCommand.h"
#include <Robot.cpp>
#include "Timer.h"

CrabArmDeployCommand::CrabArmDeployCommand() {
	void Requires(Robot::crabArm.get());
	timer = new Timer();
}

void CrabArmDeployCommand::Initialize() {
	timer->Reset();
	timer->Start();
}

void CrabArmDeployCommand::Execute() {
	Robot::crabArm->Acquire();
}

bool CrabArmDeployCommand::IsFinished() {
	return (timer->Get() >= 4);
}

void CrabArmDeployCommand::End() {
	Robot::crabArm->Stop();
	timer->Stop();
}
