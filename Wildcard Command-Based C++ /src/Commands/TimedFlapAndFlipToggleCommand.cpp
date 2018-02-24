#include <Commands/FlapAndFlipUpCommand.h>
#include <Commands/TimedFlapAndFlipToggleCommand.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>

TimedFlapAndFlipToggleCommand::TimedFlapAndFlipToggleCommand() {
    AddSequential(new WaitCommand(PRE_FLIP_WAIT_TIME));
    AddSequential(new FlapAndFlipUpCommand());
    AddSequential(new WaitCommand(POST_FLIP_WAIT_TIME));
}
