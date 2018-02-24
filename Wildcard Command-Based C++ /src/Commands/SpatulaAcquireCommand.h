#ifndef SpatulaAcquireCommand_H
#define SpatulaAcquireCommand_H

#include "Commands/Subsystem.h"

class SpatulaAcquireCommand : public Command {
public:
	SpatulaAcquireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpatulaAcquireCommand_H
