#include "Drivetrain.h"
#include "../RobotMap.h"
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include <Solenoid.h>
#include <math.h>

// no line sensors or gyro

Drivetrain::Drivetrain() : Subsystem("ExampleSubsystem") {
	leftTopMotor = new WPI_VictorSPX(DRIVETRAIN_LEFT_TOP_MOTOR_PORT);
	leftMiddleMotor = new WPI_VictorSPX(DRIVETRAIN_LEFT_MIDDLE_MOTOR_PORT);
	leftBottomMotor = new WPI_TalonSRX(DRIVETRAIN_LEFT_BOTTOM_MOTOR_PORT);

	leftMiddleMotor->Follow(*leftBottomMotor);
	leftTopMotor->Follow(*leftBottomMotor);

	rightTopMotor = new WPI_VictorSPX(DRIVETRAIN_RIGHT_TOP_MOTOR_PORT);
	rightMiddleMotor = new WPI_VictorSPX(DRIVETRAIN_RIGHT_MIDDLE_MOTOR_PORT);
	rightBottomMotor = new WPI_TalonSRX(DRIVETRAIN_RIGHT_BOTTOM_MOTOR_PORT);
	//master-follower, rightBottomMotor designated master
	rightMiddleMotor->Follow(*rightBottomMotor);
	rightTopMotor->Follow(*rightBottomMotor);

	rightTopMotor->SetInverted(true);
	rightMiddleMotor->SetInverted(true);
	rightBottomMotor->SetInverted(true);
	leftTopMotor->SetInverted(true);
	leftMiddleMotor->SetInverted(true);
	leftBottomMotor->SetInverted(true);

	leftTopMotor->SetNeutralMode(NeutralMode::Brake);
	leftMiddleMotor->SetNeutralMode(NeutralMode::Brake);
	leftBottomMotor->SetNeutralMode(NeutralMode::Brake);
	rightTopMotor->SetNeutralMode(NeutralMode::Brake);
	rightMiddleMotor->SetNeutralMode(NeutralMode::Brake);
	rightBottomMotor->SetNeutralMode(NeutralMode::Brake);

	leftBottomMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
	rightBottomMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

	gearShift = new Solenoid(GEAR_SHIFT_CHANNEL);

	differentialDrive = new DifferentialDrive(*leftBottomMotor, *rightBottomMotor);
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double Drivetrain::GetLeftSpeed() {
	return leftBottomMotor->GetSelectedSensorPosition(0);
}

double Drivetrain::GetRightSpeed() {
    return rightBottomMotor->GetSelectedSensorVelocity(0);
}

double Drivetrain::GetSpeed() {
   return fmax(abs(GetLeftSpeed()), abs(GetRightSpeed()));
}

double Drivetrain::GetLeftRawEncoderDistance() {
    return leftBottomMotor->GetSelectedSensorPosition(0);
}

double Drivetrain::GetRightRawEncoderDistance() {
    return -1 * rightBottomMotor->GetSelectedSensorPosition(0);
}

double Drivetrain::GetRawEncoderDistance() {
    return abs(fmax(GetLeftRawEncoderDistance(), GetRightRawEncoderDistance()));
}

double Drivetrain::GetLeftEncoderDistance() {
    return GetLeftRawEncoderDistance() * DRIVETRAIN_RAW_MULTIPLIER;
}

double Drivetrain::GetRightEncoderDistance() {
    return GetRightRawEncoderDistance() * DRIVETRAIN_RAW_MULTIPLIER;
}

double Drivetrain::GetEncoderDistance() {
    return abs(fmax(GetLeftEncoderDistance(), GetRightEncoderDistance()));
}

void Drivetrain::ResetEncoders() {
    leftBottomMotor->SetSelectedSensorPosition(0, 0, 0);
    rightBottomMotor->SetSelectedSensorPosition(0, 0, 0);
}

void Drivetrain::SetEncoders(double inches){
    leftBottomMotor->SetSelectedSensorPosition((int) (GetLeftRawEncoderDistance() + (inches / DRIVETRAIN_RAW_MULTIPLIER)), 0,0);
    rightBottomMotor->SetSelectedSensorPosition((int) (GetRightRawEncoderDistance() + (inches / DRIVETRAIN_RAW_MULTIPLIER)), 0,0);
}

void Drivetrain::TankDrive(double left, double right) {
    differentialDrive->TankDrive(left, right);
}

void Drivetrain::ArcadeDrive(double speed, double rotation) {
    differentialDrive->ArcadeDrive(speed, rotation);
}

void Drivetrain::CurvatureDrive(double speed, double rotation, bool turn) {
    differentialDrive->CurvatureDrive(speed, rotation, turn);
}

void Drivetrain::Stop() {
    TankDrive(0, 0);
}

void Drivetrain::HighGearShift() {
    gearShift->Set(false);
}

void Drivetrain::LowGearShift() {
    gearShift->Set(true);
}

void Drivetrain::ToggleGearShift() {
    bool m = !(Drivetrain::gearShift->Get());
    gearShift->Set(m);
}

void Drivetrain::GearShiftInput(bool isShifted) {
    gearShift->Set(isShifted);
}

bool Drivetrain::IsGearShift() {
    return gearShift->Get();
}

void Drivetrain::SetRamp(double rampSeconds) {
    leftTopMotor->ConfigOpenloopRamp(rampSeconds, 0);
    rightTopMotor->ConfigOpenloopRamp(rampSeconds, 0);
    leftBottomMotor->ConfigOpenloopRamp(rampSeconds, 0);
    rightBottomMotor->ConfigOpenloopRamp(rampSeconds, 0);
}
