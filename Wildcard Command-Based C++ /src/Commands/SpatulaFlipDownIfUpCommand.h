#ifndef SpatulaFlipDownIfUpCommand_H
#define SpatulaFlipDownIfUpCommand_H

#include "Commands/ConditionalCommand.h"

class SpatulaFlipDownIfUpCommand : public ConditionalCommand {
public:
	SpatulaFlipDownIfUpCommand();
	bool Condition();
};

#endif  // SpatulaFlipDownIfUpCommand_H
