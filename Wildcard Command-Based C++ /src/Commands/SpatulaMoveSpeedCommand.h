#ifndef SpatulaMoveSpeedCommand_H
#define SpatulaMoveSpeedCommand_H

#include "Commands/Subsystem.h"

class SpatulaMoveSpeedCommand : public Command {
	double speed;
public:
	SpatulaMoveSpeedCommand(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpatulaMoveSpeedCommand_H
