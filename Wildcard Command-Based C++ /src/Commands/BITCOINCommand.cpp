#include <Commands/BITCOINCommand.h>
#include <Commands/FlapAndFlipUpCommand.h>
#include <Commands/GrabberCloseCommand.h>
#include <Commands/GrabberOpenCommand.h>
#include <Commands/LiftMoveToBottomCommand.h>
#include <Commands/SpatulaAcquireCommand.h>
#include <Commands/WaitCommand.h>
#include <RobotMap.h>
#include <Robot.cpp>

BITCOINCommand::BITCOINCommand() {
	initialBITCOINAutomation = Robot::spatula->isBITCOINAutomation;

	SetInterruptible(false);

	AddSequential(new LiftMoveToBottomCommand());
	AddSequential(new GrabberOpenCommand());

	AddParallel(new SpatulaAcquireCommand(), PRE_FLIP_WAIT_TIME + POST_FLIP_WAIT_TIME);

	AddSequential(new FlapAndFlipUpCommand());

	AddSequential(new WaitCommand(0.25));

	AddSequential(new GrabberCloseCommand());
}

bool IsFinished() {
        return Robot::spatula->isBITCOINAutomation != BITCOINCommand::initialBITCOINAutomation ||
                CommandGroup::IsFinished;
