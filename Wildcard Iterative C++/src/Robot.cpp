/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include "ctre/Phoenix.h"
#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include <Timer.h>
#include <Joystick.h>
#include <math.h>
#include <Solenoid.h>
#include <SpeedControllerGroup.h>
#include <DoubleSolenoid.h>

class Robot : public frc::IterativeRobot {
	WPI_VictorSPX * leftTopMotor;
	WPI_VictorSPX * leftMiddleMotor;
	WPI_TalonSRX * leftBottomMotor;
	WPI_VictorSPX * rightTopMotor;
	WPI_VictorSPX * rightMiddleMotor;
	WPI_TalonSRX * rightBottomMotor;
	DifferentialDrive * differentialDrive;

	WPI_VictorSPX * leftCrabArmMotor;
	WPI_VictorSPX * rightCrabArmMotor;

	SpeedControllerGroup * crabArms;

	Solenoid * grabberSolenoid;
	bool isOpen;

	WPI_VictorSPX * leftSpatulaMotor;
	WPI_VictorSPX * rightSpatulaMotor;
	SpeedControllerGroup *spatulaMotors;
	DoubleSolenoid * spatulaFlipSolenoid;

	WPI_TalonSRX * innerLeftLiftMotor;
	WPI_TalonSRX * innerRightLiftMotor;
	WPI_VictorSPX * outerLeftLiftMotor;
	WPI_VictorSPX * outerRightLiftMotor;

	Timer * timer;

	Joystick * joystick;

public:
	void RobotInit() {
		leftTopMotor = new WPI_VictorSPX(3);
		leftMiddleMotor = new WPI_VictorSPX(2);
		leftBottomMotor = new WPI_TalonSRX(1);
		rightTopMotor = new WPI_VictorSPX(6);
		rightMiddleMotor = new WPI_VictorSPX(5);
		rightBottomMotor = new WPI_TalonSRX(4);
		differentialDrive = new DifferentialDrive(*leftBottomMotor, *rightBottomMotor);

		leftTopMotor->Follow(*leftBottomMotor);
		leftMiddleMotor->Follow(*leftBottomMotor);
		rightTopMotor->Follow(*rightBottomMotor);
		rightMiddleMotor->Follow(*rightBottomMotor);

		leftTopMotor->SetInverted(true);
		leftMiddleMotor->SetInverted(true);
		leftBottomMotor->SetInverted(true);

		rightTopMotor->SetInverted(true);
		rightMiddleMotor->SetInverted(true);
		rightBottomMotor->SetInverted(true);

		leftBottomMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
		rightBottomMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

		leftCrabArmMotor = new WPI_VictorSPX(13);
		rightCrabArmMotor = new WPI_VictorSPX(14);

		rightCrabArmMotor->SetInverted(true);

		crabArms = new SpeedControllerGroup(*leftCrabArmMotor, *rightCrabArmMotor);

		grabberSolenoid = new Solenoid(2, 3);
		isOpen = grabberSolenoid->Get();

		leftSpatulaMotor = new WPI_VictorSPX(11);
		rightSpatulaMotor = new WPI_VictorSPX(12);
		rightSpatulaMotor->SetInverted(true);
		spatulaMotors = new SpeedControllerGroup(*leftSpatulaMotor, *rightSpatulaMotor);
		spatulaFlipSolenoid = new DoubleSolenoid(6, 5);

		innerLeftLiftMotor = new WPI_TalonSRX(7);
		innerRightLiftMotor = new WPI_TalonSRX(9);
		outerLeftLiftMotor = new WPI_VictorSPX(8);
		outerRightLiftMotor = new WPI_VictorSPX(10);

		innerRightLiftMotor->Follow(*innerLeftLiftMotor);
		outerLeftLiftMotor->Follow(*innerLeftLiftMotor);
		outerRightLiftMotor->Follow(*innerLeftLiftMotor);

		timer = new Timer();

		joystick = new Joystick(0);
	}

	void AutonomousInit() override {
		ResetEncoders();
	}

	void AutonomousPeriodic() {
		differentialDrive->TankDrive(1, 1);
		if (GetEncoderDistance() >= 128) {
			differentialDrive->TankDrive(0, 0);
		}
	}

	void TeleopInit() {}

	void TeleopPeriodic() {
		differentialDrive->ArcadeDrive(joystick->GetRawAxis(1), joystick->GetRawAxis(2));

		if (joystick->GetRawButton(1)) {
			CrabArmsAcquire();
		} else {
			CrabArmsStop();
		}

		if (joystick->GetRawButtonPressed(2)) {
			GrabberToggle();
		}

		if (joystick->GetRawButtonPressed(3)) {
			SpatulaToggle();
		}

		innerLeftLiftMotor->Set(joystick->GetRawAxis(5));
	}
	void TestPeriodic() {}

	void ResetEncoders() {
		leftBottomMotor->SetSelectedSensorPosition(0, 0, 0);
		rightBottomMotor->SetSelectedSensorPosition(0, 0, 0);
	}

	double GetLeftEncoderDistance() {
		return ((leftBottomMotor->GetSelectedSensorPosition(0))
				* (161.5 / 1210) * M_PI * 6 / 256 * 4);
	}

	double GetRightEncoderDistance() {
		return ((rightBottomMotor->GetSelectedSensorPosition(0))
				* (161.5 / 1210) * M_PI * 6 / 256 * 4);
	}

	double GetEncoderDistance() {
		return (fmax(GetLeftEncoderDistance(), GetRightEncoderDistance()));
	}

	void CrabArmsAcquire() {
		crabArms->Set(1);
	}

	void CrabArmsDeacquire() {
		crabArms->Set(-1);
	}

	void CrabArmsStop() {
		crabArms->Set(0);
	}

	void GrabberOpen() {
		grabberSolenoid->Set(true);
	}

	void GrabberClose() {
		grabberSolenoid->Set(false);
	}

	void GrabberToggle() {
		if (isOpen) {
			GrabberClose();
		} else {
			GrabberOpen();
		}
	}

	void SpatulaAcqure() {
		spatulaMotors->Set(1);
	}

	void SpatulaDeacquire() {
		spatulaMotors->Set(-1);
	}

	void SpatulaStop() {
		spatulaMotors->Set(0);
	}

	void SpatulaFlipUp() {
		spatulaFlipSolenoid->Set(DoubleSolenoid::Value::kForward);
	}

	void SpatulaFlipDown() {
		spatulaFlipSolenoid->Set(DoubleSolenoid::Value::kReverse);
	}

	void SpatulaToggle() {
		if (spatulaFlipSolenoid->Get() == DoubleSolenoid::Value::kForward) {
			SpatulaFlipDown();
		} else {
			SpatulaFlipUp();
		}
	}

private:
};

START_ROBOT_CLASS(Robot)
