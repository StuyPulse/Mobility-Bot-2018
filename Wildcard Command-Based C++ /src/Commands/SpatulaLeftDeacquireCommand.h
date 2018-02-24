#ifndef SpatulaLeftDeacquireCommand_H
#define SpatulaLeftDeacquireCommand_H

#include "Commands/Subsystem.h"

class SpatulaLeftDeacquireCommand : public Command {
public:
	SpatulaLeftDeacquireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpatulaLeftDeacquireCommand_H
