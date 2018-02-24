#ifndef LiftMoveSpeedCommand_H
#define LiftMoveSpeedCommand_H

#include "Commands/Subsystem.h"

class LiftMoveSpeedCommand : public Command {
	double speed;
public:
	LiftMoveSpeedCommand(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftMoveSpeedCommand_H
