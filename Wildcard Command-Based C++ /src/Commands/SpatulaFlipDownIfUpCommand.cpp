#include <Commands/FlapAndFlipDownCommand.h>
#include <Commands/SpatulaFlipDownIfUpCommand.h>
#include <Robot.cpp>
#include <Subsystems/Spatula.h>

SpatulaFlipDownIfUpCommand::SpatulaFlipDownIfUpCommand() {
	ConditionalCommand(new FlapAndFlipDownCommand());
}

bool Condition() {
    return Robot::spatula->IsSpatulaUp();
}
