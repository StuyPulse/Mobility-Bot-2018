#ifndef SpatulaDeacquireCommand_H
#define SpatulaDeacquireCommand_H

#include "Commands/Subsystem.h"

class SpatulaDeacquireCommand : public Command {
public:
	SpatulaDeacquireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpatulaDeacquireCommand_H
