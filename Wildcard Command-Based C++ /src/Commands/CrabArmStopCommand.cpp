#include "CrabArmStopCommand.h"
#include <Robot.cpp>

CrabArmStopCommand::CrabArmStopCommand() {
	void Requires(Robot::crabArm.get());
}

void CrabArmStopCommand::Initialize() {
	Robot::crabArm->Stop();
}
