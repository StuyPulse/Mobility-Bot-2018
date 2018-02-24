#include <Commands/CrabArmFlapOutCommand.h>
#include <Commands/TimedToggleCrabArmFlapOutAndSpatulaFlipCommand.h>
#include <Commands/ToggleCrabArmFlapOutAndSpatulaFlipCommand.h>
#include <RobotMap.h>

ToggleCrabArmFlapOutAndSpatulaFlipCommand::ToggleCrabArmFlapOutAndSpatulaFlipCommand() {
	AddParallel(new CrabArmFlapOutCommand(), PRE_FLIP_WAIT_TIME + POST_FLIP_WAIT_TIME);
	AddSequential(new TimedToggleCrabArmFlapOutAndSpatulaFlipCommand());
}
