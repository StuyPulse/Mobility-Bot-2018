#include "CrabArmFlapOutCommand.h"
#include <Robot.cpp>

CrabArmFlapOutCommand::CrabArmFlapOutCommand() {
	void Requires(Robot::crabArm.get());
}

void CrabArmFlapOutCommand::Execute() {
	Robot::crabArm->FlapOut();
}

bool CrabArmFlapOutCommand::IsFinished() {
	return false;
}

void CrabArmFlapOutCommand::End() {
	Robot::crabArm->Stop();
}

