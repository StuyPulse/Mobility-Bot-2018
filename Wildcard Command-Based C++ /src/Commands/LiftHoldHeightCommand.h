#ifndef LiftHoldHeightCommand_H
#define LiftHoldHeightCommand_H

#include "Commands/Subsystem.h"

class LiftHoldHeightCommand : public Command {
	double currentHeight;
public:
	LiftHoldHeightCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftHoldHeightCommand_H
