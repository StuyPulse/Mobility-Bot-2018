#ifndef LiftStopCommand_H
#define LiftStopCommand_H

#include "Commands/InstantCommand.h"

class LiftStopCommand : public InstantCommand {
public:
	LiftStopCommand();
	void Initialize();
};

#endif  // LiftStopCommand_H
