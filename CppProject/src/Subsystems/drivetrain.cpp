#include "drivetrain.h"
#include "../RobotMap.h"

drivetrain::drivetrain() : Subsystem("Subsystem") {

	pLeftFrontMotor = new WPI_TalonSRX(RobotMap.LEFT_FRONT_MOTOR);
	pLeftRearMotor = new WPI_TalonSRX(RobotMap.LEFT_REAR_MOTOR);
	pRightFrontMotor = new WPI_TalonSRX(RobotMap.RIGHT_FRONT_MOTOR);
	pRightRearMotor = new WPI_TalonSRX(RobotMap.RIGHT_REAR_MOTOR);
}

void Command::Requires();

void drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
