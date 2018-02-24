#include <Commands/SpatulaFlipDownCommand.h>
#include <Commands/TimedSpatulaFlipDownCommand.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

TimedSpatulaFlipDownCommand::TimedSpatulaFlipDownCommand() {
	AddSequential(new WaitCommand(PRE_FLIP_WAIT_TIME));
	AddSequential(new SpatulaFlipDownCommand());
	AddSequential(new WaitCommand(POST_FLIP_WAIT_TIME));
}
