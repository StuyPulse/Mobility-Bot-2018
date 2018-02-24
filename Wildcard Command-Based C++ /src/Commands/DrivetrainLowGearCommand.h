#ifndef DrivetrainLowGearCommand_H
#define DrivetrainLowGearCommand_H

#include "Commands/InstantCommand.h"

class DrivetrainLowGearCommand : public InstantCommand {
public:
	DrivetrainLowGearCommand();
	void Initialize();
};

#endif  // DrivetrainLowGearCommand_H
