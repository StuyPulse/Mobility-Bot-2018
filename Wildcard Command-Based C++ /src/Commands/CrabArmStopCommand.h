#ifndef CrabArmStopCommand_H
#define CrabArmStopCommand_H

#include "Commands/InstantCommand.h"

class CrabArmStopCommand : public InstantCommand {
public:
	CrabArmStopCommand();
	void Initialize();
};

#endif  // CrabArmStopCommand_H
