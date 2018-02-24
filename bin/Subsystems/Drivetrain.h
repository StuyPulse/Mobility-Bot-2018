/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "Drive/DifferentialDrive.h"
#include <Encoder.h>
#include <Solenoid.h>
#include <ADXRS450_Gyro.h>
#include <PIDController.h>
#include <edu.stuy.util/TankDriveOutput.h>

class Drivetrain : public frc::Subsystem {
private:

	frc::Encoder * _leftEncoders;
	frc::Encoder * _rightEncoders;

	WPI_TalonSRX * _leftFrontMotor;
	WPI_TalonSRX * _leftRearMotor;
	WPI_TalonSRX * _rightFrontMotor;
	WPI_TalonSRX * _rightRearMotor;

	frc::DifferentialDrive * _differentialDrive;

	frc::ADXRS450_Gyro * _gyro;

	frc::Solenoid * _gearShift;

	double * _currents[];

	TankDriveOutput _out;

	frc::PIDController * _pid;

    bool * _gearUp; // Stores the state of the gear shift
    bool * _overrideAutoGearShifting; // True if automatic gear shifting is not being used
    bool * _autoGearShiftingState; // True if automatic gear shifting was disabled and never re-enabled

public:
	Drivetrain();
	void InitDefaultCommand() override;
	double GetGyroAngle();
	void EncodersReset();
	double GetLeftEncoderDistance();
	double GetRightEncoderDistance();
	double GetEncoderDistance();
	void TankDrive(double left, double right);
	void ArcadeDrive(double y, double x);
	void DrivetrainStop();
	virtual ~Drivetrain();
};

