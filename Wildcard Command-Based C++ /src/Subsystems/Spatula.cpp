#include <ctre/Phoenix.h>
#include <RobotMap.h>
#include <Subsystems/Spatula.h>
#include <DoubleSolenoid.h>

Spatula::Spatula() : Subsystem("ExampleSubsystem") {
	leftSpatulaMotor = new WPI_VictorSPX(SPATULA_LEFT_MOTOR_PORT);
	rightSpatulaMotor = new WPI_VictorSPX(SPATULA_RIGHT_MOTOR_PORT);
	leftSpatulaMotor->SetNeutralMode(NeutralMode::Brake);
	rightSpatulaMotor->SetNeutralMode(NeutralMode::Brake);
	rightSpatulaMotor->SetInverted(true);

	spatulaFlipSolenoid = new DoubleSolenoid(SPATULA_FLIP_UP_PORT, SPATULA_FLIP_DOWN_PORT);

	spatulaMotors = new SpeedControllerGroup(*leftSpatulaMotor, *rightSpatulaMotor);
	spatulaLimitSwitch = new DigitalInput(SPATULA_LIMIT_SWITCH_PORT);

	isBITCOINAutomation = true;
}

void Spatula::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Spatula::Acquire() {
	spatulaMotors->Set(1);
}

void Spatula::Deacquire() {
	spatulaMotors->Set(-1);
}

void Spatula::AcquireSpeed(double speed) {
	spatulaMotors->Set(speed);
}

void Spatula::LeftSpatulaDeacquire() {
	leftSpatulaMotor->Set(1);
	rightSpatulaMotor->Set(-1);
}

void Spatula::RightSpatulaDeacquire() {
	leftSpatulaMotor->Set(-1);
	rightSpatulaMotor->Set(1);
}

void Spatula::Stop() {
	spatulaMotors->Set(0);
}

void Spatula::FlipUp() {
	spatulaFlipSolenoid->Set(DoubleSolenoid::Value::kForward);
}

void Spatula::FlipDown() {
	spatulaFlipSolenoid->Set(DoubleSolenoid::Value::kReverse);
}

bool Spatula::IsCubeDetected() {
	return !(spatulaLimitSwitch->Get());
}

bool Spatula::IsSpatulaUp() {
	DoubleSolenoid::Value val = spatulaFlipSolenoid->Get();
	return (val == DoubleSolenoid::Value::kForward || val == DoubleSolenoid::Value::kOff);
}

void Spatula::Toggle() {
	if (IsSpatulaUp()) {
		FlipDown();
	} else {
		FlipUp();
	}
}
