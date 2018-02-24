#ifndef GrabberCloseCommand_H
#define GrabberCloseCommand_H

#include "Commands/InstantCommand.h"

class GrabberCloseCommand : public InstantCommand {
public:
	GrabberCloseCommand();
	void Initialize();
};

#endif  // GrabberCloseCommand_H
