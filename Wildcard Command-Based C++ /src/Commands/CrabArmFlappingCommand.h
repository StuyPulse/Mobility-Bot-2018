#ifndef CrabArmFlapping_H
#define CrabArmFlapping_H

#include "Commands/Subsystem.h"
#include "Timer.h"

class CrabArmFlappingCommand : public Command {
	int seconds;
	Timer * timer;

public:
	CrabArmFlappingCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabArmFlapping_H
