#ifndef SpatulaRightDeacquireCommand_H
#define SpatulaRightDeacquireCommand_H

#include "Commands/Subsystem.h"

class SpatulaRightDeacquireCommand : public Command {
public:
	SpatulaRightDeacquireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpatulaRightDeacquireCommand_H
