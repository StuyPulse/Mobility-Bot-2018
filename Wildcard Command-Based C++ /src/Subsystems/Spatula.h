#ifndef Spatula_H
#define Spatula_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <DoubleSolenoid.h>
#include <SpeedControllerGroup.h>
#include <DigitalInput.h>

class Spatula : public Subsystem {
private:
    WPI_VictorSPX * leftSpatulaMotor;
    WPI_VictorSPX * rightSpatulaMotor;
    DoubleSolenoid * spatulaFlipSolenoid;

    SpeedControllerGroup * spatulaMotors;
    DigitalInput * spatulaLimitSwitch;

    bool isBITCOINAutomation;
public:
	Spatula();
	void InitDefaultCommand();
	void Acquire();
	void Deacquire();
	void AcquireSpeed(double speed);
	void LeftSpatulaDeacquire();
	void RightSpatulaDeacquire();
	void Stop();
	void FlipUp();
	void FlipDown();
	bool IsCubeDetected();
	void Toggle();
	bool IsSpatulaUp();
};

#endif  // Spatula_H
