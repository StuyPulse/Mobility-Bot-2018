#include <Commands/CrabArmStopCommand.h>
#include <Commands/CrabArrowStopCommand.h>
#include <Commands/SpatulaStopCommand.h>

CrabArrowStopCommand::CrabArrowStopCommand() {
    AddParallel(new CrabArmStopCommand());
    AddSequential(new SpatulaStopCommand());
}
