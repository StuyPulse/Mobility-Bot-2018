#include <Commands/SpatulaFlipToggleCommand.h>
#include <Commands/TimedToggleCrabArmFlapOutAndSpatulaFlipCommand.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

TimedToggleCrabArmFlapOutAndSpatulaFlipCommand::TimedToggleCrabArmFlapOutAndSpatulaFlipCommand() {
	AddSequential(new WaitCommand(PRE_FLIP_WAIT_TIME));
	AddSequential(new SpatulaFlipToggleCommand());
	AddSequential(new WaitCommand(POST_FLIP_WAIT_TIME));
}
