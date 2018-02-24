#ifndef CrabArmFlapOutCommand_H
#define CrabArmFlapOutCommand_H

#include "Commands/Subsystem.h"

class CrabArmFlapOutCommand : public Command {
public:
	CrabArmFlapOutCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrabArmFlapOutCommand_H
