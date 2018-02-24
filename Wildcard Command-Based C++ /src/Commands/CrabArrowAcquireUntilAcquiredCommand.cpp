#include "CrabArrowAcquireUntilAcquiredCommand.h"
#include  <Robot.cpp>

CrabArrowAcquireUntilAcquiredCommand::CrabArrowAcquireUntilAcquiredCommand() {

}

bool IsFinished() {
	return Robot::spatula->IsCubeDetected();
}

