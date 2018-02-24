#include "Lift.h"
#include "../RobotMap.h"

#include <ctre/Phoenix.h>
#include <DigitalInput.h>
#include <math.h>

Lift::Lift() : Subsystem("ExampleSubsystem") {
	innerLeftMotor = new WPI_TalonSRX(LIFT_INNER_LEFT_MOTOR_PORT);
	innerRightMotor = new WPI_TalonSRX(LIFT_INNER_RIGHT_MOTOR_PORT);
	//We will be using encoder data from the left motor only, and leaving it as a TalonSRX.

	outerLeftMotor = new WPI_VictorSPX(LIFT_OUTER_LEFT_MOTOR_PORT);
	outerRightMotor = new WPI_VictorSPX(LIFT_OUTER_RIGHT_MOTOR_PORT);

	innerLeftMotor->SetNeutralMode(NeutralMode::Brake);
	innerRightMotor->SetNeutralMode(NeutralMode::Brake);

	outerLeftMotor->SetNeutralMode(NeutralMode::Brake);
	outerRightMotor->SetNeutralMode(NeutralMode::Brake);

	innerRightMotor->Follow(*innerLeftMotor);
	outerRightMotor->Follow(*innerLeftMotor);
	outerLeftMotor->Follow(*innerLeftMotor);

	innerLeftMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	innerRightMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

	// should get middle value from SmartDashboard
	innerLeftMotor->Config_kP(0, 0.3, 0);

	innerLeftMotor->SetSensorPhase(true);
	innerRightMotor->SetSensorPhase(true);

	topLimitSwitch = new DigitalInput(LIFT_TOP_LIMIT_SWITCH_PORT);
	bottomLimitSwitch = new DigitalInput(LIFT_BOTTOM_LIMIT_SWITCH_PORT);
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Lift::ResetEncoders() {
    innerLeftMotor->SetSelectedSensorPosition(0, 0, 0);
    innerRightMotor->SetSelectedSensorPosition(0, 0, 0);
}

double Lift::GetSpeed() {
    return innerLeftMotor->Get();
}

void Lift::Stop() {
    innerLeftMotor->Set(ControlMode::PercentOutput, 0);
}

bool Lift::GetBrakeStatus() {
    return false;
}

bool Lift::IsAtBottom() {
    return !(bottomLimitSwitch->Get());
}

bool Lift::IsAtTop() {
    return !(topLimitSwitch->Get());
}

double Lift::GetLeftRawEncoderDistance() {
    return innerLeftMotor->GetSelectedSensorPosition(0);
}

double Lift::GetRightRawEncoderDistance() {
    return innerRightMotor->GetSelectedSensorPosition(0);
}

double Lift::GetLeftEncoderDistance() {
    return GetLeftRawEncoderDistance() * LIFT_ENCODER_RAW_MULTIPLIER;
}

double Lift::GetRightEncoderDistance() {
    return GetRightRawEncoderDistance() * LIFT_ENCODER_RAW_MULTIPLIER;
}

double Lift::GetLiftHeight() {
    return fmax(GetLeftEncoderDistance(), GetRightEncoderDistance());
}

void Lift::SetHeight(double height) {
    innerLeftMotor->Set(ControlMode::Position, height / LIFT_ENCODER_RAW_MULTIPLIER);
}

double Lift::GetMotorVelocity() {
    return innerLeftMotor->GetSelectedSensorVelocity(0);
}


void Lift::MoveLift(double speed) {
    if ((IsAtTop() && speed > 0) || (IsAtBottom() && speed < 0)) {
        Stop();
    } else {
        innerLeftMotor->Set(ControlMode::PercentOutput,speed);
    }
}

void Lift::Move(double currentSpeed) {
    double currentHeight = GetLiftHeight();
    double speed = currentSpeed;
    if (currentHeight < 0) {
        speed = fmax(-LIFT_MIN_SPEED, speed);
    } else if (currentSpeed < 0) {
        if (currentHeight < LIFT_RAMP_HEIGHT_THRESHOLD) {
            speed = -(LIFT_RAMP_SLOPE * currentHeight + LIFT_MIN_SPEED);
            speed = fmax(speed, currentSpeed);
        }
    } else {
        if (currentHeight > LIFT_TOTAL_CARRIAGE_MOVEMENT - LIFT_RAMP_HEIGHT_THRESHOLD) {
            speed = LIFT_RAMP_SLOPE * (LIFT_TOTAL_CARRIAGE_MOVEMENT - currentHeight) + LIFT_MIN_SPEED;
            speed = fmin(speed, currentSpeed);
        }
    }
    MoveLift(speed);
}

void Lift::Periodic() {
    if (IsAtBottom()) {
        ResetEncoders();
    }
}

