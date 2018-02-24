#ifndef LiftMoveToHeightCommand_H
#define LiftMoveToHeightCommand_H

#include "Commands/Subsystem.h"

class LiftMoveToHeightCommand : public Command {
	double targetHeight;
public:
	LiftMoveToHeightCommand(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftMoveToHeightCommand_H
