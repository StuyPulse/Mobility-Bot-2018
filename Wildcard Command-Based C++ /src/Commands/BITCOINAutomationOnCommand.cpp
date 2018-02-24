#include "BITCOINAutomationOnCommand.h"
#include <Robot.cpp>

BITCOINAutomationOnCommand::BITCOINAutomationOnCommand() {
}

void BITCOINAutomationOnCommand::Initialize() {
	Robot::spatula->isBITCOINAutomation = true;
}
