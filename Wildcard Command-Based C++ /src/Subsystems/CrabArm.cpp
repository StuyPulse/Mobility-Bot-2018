#include "CrabArm.h"
#include "../RobotMap.h"

#include <ctre/Phoenix.h>

CrabArm::CrabArm() : Subsystem("ExampleSubsystem") {
	leftCrabArmMotor = new WPI_VictorSPX(CRAB_ARM_LEFT_MOTOR_PORT);
	rightCrabArmMotor = new WPI_VictorSPX(CRAB_ARM_RIGHT_MOTOR_PORT);
	leftCrabArmMotor->SetNeutralMode(NeutralMode::Coast);
	rightCrabArmMotor->SetNeutralMode(NeutralMode::Coast);

	rightCrabArmMotor->SetInverted(true);

	crabArmMotors = new SpeedControllerGroup(*leftCrabArmMotor, *rightCrabArmMotor);
}

void CrabArm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void CrabArm::Acquire() {
    crabArmMotors->Set(1);
}

void CrabArm::FlapOut() {
    crabArmMotors->Set(-1 * FLAP_OUT_SPEED);
}

void CrabArm::FlapPush() {
    crabArmMotors->Set(-1 * CRAB_ARM_PUSH_POWER);
}

void CrabArm::FlapCoast() {
    crabArmMotors->Set(-1 * CRAB_ARM_COAST_POWER);
}

void CrabArm::Stop() {
    crabArmMotors->Set(0);
}
