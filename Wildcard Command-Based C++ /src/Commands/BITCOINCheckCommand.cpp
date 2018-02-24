#include <Commands/BITCOINCheckCommand.h>
#include <Commands/CrabArrowAcquireCommand.h>
#include <Robot.cpp>

BITCOINCheckCommand::BITCOINCheckCommand() {
	ConditionalCommand(new BITCOINCubeDetectedCommand(), new CrabArrowAcquireCommand());
}

bool Condition() {
	return Robot::spatula->isBITCOINAutomation;
}
