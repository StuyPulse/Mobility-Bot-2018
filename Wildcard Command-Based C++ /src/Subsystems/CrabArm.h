#ifndef CrabArm_H
#define CrabArm_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <SpeedControllerGroup.h>

class CrabArm : public Subsystem {
private:
	WPI_VictorSPX * leftCrabArmMotor;
	WPI_VictorSPX * rightCrabArmMotor;
	SpeedControllerGroup * crabArmMotors;

public:
	CrabArm();
	void InitDefaultCommand();
	void Acquire();
	void FlapOut();
	void FlapPush();
	void FlapCoast();
	void Stop();
};

#endif  // CrabArm_H
