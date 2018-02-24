#include <Commands/BITCOINCommand.h>
#include <Commands/BITCOINCubeDetectedCommand.h>
#include <Commands/CrabArrowAcquireUntilAcquiredCommand.h>
#include <Robot.cpp>

BITCOINCubeDetectedCommand::BITCOINCubeDetectedCommand() {
	ConditionalCommand(new BITCOINCommand(), new CrabArrowAcquireUntilAcquiredCommand());
}

bool Condition() {
	return Robot::spatula->IsCubeDetected();
}
