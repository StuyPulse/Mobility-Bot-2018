#include "BITCOINAutomationOffCommand.h"
#include <Robot.cpp>

BITCOINAutomationOffCommand::BITCOINAutomationOffCommand() {
}

void BITCOINAutomationOffCommand::Initialize() {
	Robot::spatula->isBITCOINAutomation = false;
}
