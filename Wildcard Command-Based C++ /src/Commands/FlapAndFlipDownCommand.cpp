#include <Commands/CrabArmFlapOutCommand.h>
#include <Commands/FlapAndFlipDownCommand.h>
#include <Commands/TimedSpatulaFlipDownCommand.h>
#include <RobotMap.h>

FlapAndFlipDownCommand::FlapAndFlipDownCommand() {
	IsInterruptible() = false;
	AddParallel(new CrabArmFlapOutCommand(), PRE_FLIP_WAIT_TIME + POST_FLIP_WAIT_TIME);
	AddSequential(new TimedSpatulaFlipDownCommand());
}
