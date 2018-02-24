#include <CrabArmAcquireCommand.h>
#include <Robot.cpp>
#include <Commands/Command.h>

CrabArmAcquireCommand::CrabArmAcquireCommand() {
	void Requires(Robot::crabArm.get());
}

void CrabArmAcquireCommand::Execute() {
	Robot::crabArm->Acquire();
}

bool CrabArmAcquireCommand::IsFinished() {
	return false;
}

void CrabArmAcquireCommand::End() {
	Robot::crabArm->Stop();
}
