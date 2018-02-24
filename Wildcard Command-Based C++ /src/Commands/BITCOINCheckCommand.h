#ifndef BITCOINCheckCommand_H
#define BITCOINCheckCommand_H

#include "Commands/ConditionalCommand.h"
#include "Commands/Command.h"

class BITCOINCheckCommand : public ConditionalCommand {
public:
	BITCOINCheckCommand();
	bool Condition();
};

#endif  // BITCOINCheckCommand_H
