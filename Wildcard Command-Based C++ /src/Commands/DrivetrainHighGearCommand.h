#ifndef DrivetrainHighGearCommand_H
#define DrivetrainHighGearCommand_H

#include "Commands/InstantCommand.h"

class DrivetrainHighGearCommand : public InstantCommand {
public:
	DrivetrainHighGearCommand();
	void Initialize();
};

#endif  // DrivetrainHighGearCommand_H
