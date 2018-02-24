#include <Commands/CrabArmFlappingCommand.h>
#include <Robot.cpp>
#include <Timer.h>

CrabArmFlappingCommand::CrabArmFlappingCommand() {
	timer = new Timer();
	seconds = -1;
	void Requires(Robot::crabArm.get());
}

void CrabArmFlappingCommand::Initialize() {
	timer->Reset();
	timer->Start();
}
void CrabArmFlappingCommand::Execute() {
	Robot::crabArm->FlapPush();
	if (timer->Get() >= seconds) {
		Robot::crabArm->FlapCoast();
		timer->Reset();
		timer->Start();
	}
}

bool CrabArmFlappingCommand::IsFinished() {
	return false;
}

void CrabArmFlappingCommand::End() {
	timer->Stop();
}
