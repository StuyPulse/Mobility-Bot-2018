#ifndef CrabArmsAcquireCommand_H
#define CrabArmsAcquireCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.cpp"

class CrabArmAcquireCommand : public Command {
public:
	CrabArmAcquireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabArmsAcquireCommand_H
