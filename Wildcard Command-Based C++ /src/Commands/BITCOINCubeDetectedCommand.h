#ifndef BITCOINCubeDetectedCommand_H
#define BITCOINCubeDetectedCommand_H

#include "Commands/ConditionalCommand.h"

class BITCOINCubeDetectedCommand : public ConditionalCommand {
public:
	BITCOINCubeDetectedCommand();
	bool Condition();
};

#endif  // BITCOINCubeDetectedCommand_H
