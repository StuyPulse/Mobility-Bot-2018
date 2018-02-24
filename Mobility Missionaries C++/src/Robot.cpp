/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <math.h>
#include <IterativeRobot.h>
#include "ctre/Phoenix.h"
#include "Drive/DifferentialDrive.h"
#include "Joystick.h"
#include "Timer.h"
#include "Encoder.h"

class Robot : public frc::IterativeRobot {
public:

	Encoder * _leftEncoders = new Encoder(0, 1);
	Encoder * _rightEncoders = new Encoder(2, 3);

	WPI_TalonSRX * _rightFrontMotor = new WPI_TalonSRX(1);
	WPI_TalonSRX * _rightRearMotor = new WPI_TalonSRX(2);
	WPI_TalonSRX * _leftFrontMotor = new WPI_TalonSRX(4);
	WPI_TalonSRX * _leftRearMotor = new WPI_TalonSRX(3);

	WPI_TalonSRX * _dropdownMotor = new WPI_TalonSRX(8);

	WPI_TalonSRX * _shooterMotor = new WPI_TalonSRX(7);

	WPI_TalonSRX * _hopperMotor = new WPI_TalonSRX(5);

	WPI_TalonSRX * _acquirerMotor = new WPI_TalonSRX(6);

	Joystick * _driverPad  = new Joystick(0);
	Joystick * _operatorPad = new Joystick(1);

	DifferentialDrive * _differentialDrive = new DifferentialDrive(_leftRearMotor, _rightRearMotor);

	Timer * _timer = new Timer();

	void RobotInit() {
		_leftFrontMotor->Follow(*_leftRearMotor);
		_rightFrontMotor->Follow(*_rightRearMotor);

		_leftFrontMotor->SetInverted(true);
		_leftRearMotor->SetInverted(true);
		_rightFrontMotor->SetInverted(true);
		_rightRearMotor->SetInverted(true);

		_dropdownMotor->SetInverted(true);

		_rightEncoders->SetDistancePerPulse((8 * M_PI) / 360);
		_leftEncoders->SetDistancePerPulse((8 * M_PI) / 360);

		_rightEncoders->Reset();
		_leftEncoders->Reset();
	}

	void AutonomousInit() override {
		_rightEncoders->Reset();
		_leftEncoders->Reset();
		_timer->Reset();
		_timer->Start();
	}

	void AutonomousPeriodic() {
		using namespace std;
		cout<<_rightEncoders->GetDistance()<<endl;
		cout<<_leftEncoders->GetDistance()<<endl;
		/*_differentialDrive->ArcadeDrive(1, 0, false);
		_differentialDrive->TankDrive(1, 1, false);
		if(_timer->Get() >= 1.5){
			_differentialDrive->TankDrive(0, 0, false);
			_timer->Stop();
		}
		*/
		if(_rightEncoders->GetDistance() < 20){
			_differentialDrive->TankDrive(1, 1, false);
		}
		else{
			_differentialDrive->TankDrive(0, 0, false);
		}
	}

	void TeleopInit() {
		_rightEncoders->Reset();
		_leftEncoders->Reset();
	}

	void TeleopPeriodic() {
		using namespace std;
		cout<<_rightEncoders->GetDistance()<<endl;
		cout<<_leftEncoders->GetDistance()<<endl;
		if(_operatorPad->GetRawButton(1) == true){
			_hopperMotor->Set(1);
		}
		else{
			_hopperMotor->Set(0);
		}
		//_shooterMotor->Set(_operatorPad->GetRawAxis(3));
		_dropdownMotor->Set(_operatorPad->GetRawAxis(1));
		_differentialDrive->ArcadeDrive(-1 * _driverPad->GetRawAxis(1), _driverPad->GetRawAxis(4), false);
		_acquirerMotor->Set(-1 * _operatorPad->GetRawAxis(2));
	}

	void TestPeriodic() {
	}
};

START_ROBOT_CLASS(Robot)
