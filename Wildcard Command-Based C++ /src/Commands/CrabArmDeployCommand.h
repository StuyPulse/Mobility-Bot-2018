#ifndef CrabArmDeployCommand_H
#define CrabArmDeployCommand_H

#include "Commands/Subsystem.h"
#include <Timer.h>

class CrabArmDeployCommand : public Command {
	Timer * timer;
public:
	CrabArmDeployCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabArmDeployCommand_H
