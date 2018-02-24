#include <Commands/SpatulaFlipUpCommand.h>
#include <Commands/TimedSpatulaFlipUpCommand.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

TimedSpatulaFlipUpCommand::TimedSpatulaFlipUpCommand() {
	 AddSequential(new WaitCommand(PRE_FLIP_WAIT_TIME + 0.75));
	 AddSequential(new SpatulaFlipUpCommand());
	 AddSequential(new WaitCommand(POST_FLIP_WAIT_TIME));
}
