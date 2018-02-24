#ifndef LiftMoveToBottomCommand_H
#define LiftMoveToBottomCommand_H

#include "Commands/Subsystem.h"

class LiftMoveToBottomCommand : public Command {
public:
	LiftMoveToBottomCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftMoveToBottomCommand_H
