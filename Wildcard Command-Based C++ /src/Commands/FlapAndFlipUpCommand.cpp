#include <Commands/CrabArmFlapOutCommand.h>
#include <Commands/FlapAndFlipUpCommand.h>
#include <Commands/TimedSpatulaFlipUpCommand.h>
#include <RobotMap.h>

FlapAndFlipUpCommand::FlapAndFlipUpCommand() {
	AddParallel(new CrabArmFlapOutCommand(), PRE_FLIP_WAIT_TIME + POST_FLIP_WAIT_TIME + 0.75);
	AddSequential(new TimedSpatulaFlipUpCommand());
}
