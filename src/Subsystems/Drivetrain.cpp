/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotMap.h"
#include "Drivetrain.h"
#include <SmartDashboard/SmartDashboard.h>

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
	_leftFrontMotor = new WPI_TalonSRX(LEFT_FRONT_MOTOR_PORT);
	_leftRearMotor = new WPI_TalonSRX(LEFT_REAR_MOTOR_PORT);
	_rightFrontMotor = new WPI_TalonSRX(RIGHT_FRONT_MOTOR_PORT);
	_rightRearMotor = new WPI_TalonSRX(RIGHT_REAR_MOTOR_PORT);

	_leftEncoders = new frc::Encoder(LEFT_ENCODER_CHANNEL_A, LEFT_ENCODER_CHANNEL_B);
	_rightEncoders = new frc::Encoder(RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B);

	_gearShift = new frc::Solenoid(GEAR_SHIFT_CHANNEL);

	_gyro = new frc::ADXRS450_Gyro();

	_out = new TankDriveOutput(_differentialDrive);

	_pid = new frc::PIDController(frc::SmartDashboard::GetNumber("Gyro P: ", 0), frc::SmartDashboard::GetNumber("Gyro I: ", 0), frc::SmartDashboard::GetNumber("Gyro D: ", 0), _gyro, _out);

	_differentialDrive = new frc::DifferentialDrive(_leftRearMotor, _rightRearMotor);

	_leftFrontMotor->Follow(*_leftRearMotor);
	_rightFrontMotor->Follow(*_rightRearMotor);

	_leftFrontMotor->SetInverted(true);
	_leftRearMotor->SetInverted(true);
	_rightFrontMotor->SetInverted(true);
	_rightRearMotor->SetInverted(true);

	_leftEncoders->SetDistancePerPulse(DRIVETRAIN_ENCODER_INCHES_PER_PULSE);
	_rightEncoders->SetDistancePerPulse(DRIVETRAIN_ENCODER_INCHES_PER_PULSE);

	_gearUp = false;
	_overrideAutoGearShifting = false;
	_autoGearShiftingState = true;
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Drivetrain::EncodersReset(){
	_leftEncoders->Reset();
	_rightEncoders->Reset();
}
double Drivetrain::GetLeftEncoderDistance(){
	return _leftEncoders->GetDistance();
}
double Drivetrain::GetRightEncoderDistance(){
	return _rightEncoders->GetDistance();
}
double Drivetrain::GetEncoderDistance(){
	double left = GetLeftEncoderDistance();
	double right = GetRightEncoderDistance();
	return std::max(left, right);
}
void Drivetrain::TankDrive(double left, double right){
	_differentialDrive->TankDrive(left, right, false);
}
void Drivetrain::ArcadeDrive(double y, double x){
	_differentialDrive->ArcadeDrive(y, x, false);
}
void Drivetrain::DrivetrainStop(){
	_differentialDrive->TankDrive(0, 0, false);
	_differentialDrive->ArcadeDrive(0, 0, false);
}
Drivetrain::~Drivetrain(){
}

