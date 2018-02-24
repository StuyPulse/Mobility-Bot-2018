#include <Commands/CrabArmAcquireCommand.h>
#include <Commands/CrabArrowAcquireCommand.h>
#include <Commands/LiftMoveToHeightCommand.h>
#include <Commands/SpatulaAcquireCommand.h>

CrabArrowAcquireCommand::CrabArrowAcquireCommand() {
//	AddSequential(new SpatulaFlipUpIfDownCommand);
	AddParallel(new LiftMoveToHeightCommand(0));
	AddParallel(new CrabArmAcquireCommand());
	AddSequential(new SpatulaAcquireCommand());
}
