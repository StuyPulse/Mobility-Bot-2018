/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/CrabArm.h>
#include <Subsystems/Drivetrain.h>
#include <Subsystems/Grabber.h>
#include <Subsystems/Lift.h>
#include <Subsystems/Spatula.h>
#include <TimedRobot.h>

class Robot : public frc::TimedRobot {
public:
//	std::shared_ptr<Drivetrain> Robot::drivetrain;
//	std::shared_ptr<Spatula> Robot::spatula;
//	std::shared_ptr<CrabArm> Robot::crabArm;
//	std::shared_ptr<Grabber> Robot::grabber;
//	std::shared_ptr<Lift> Robot::lift;

	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<Spatula> spatula;
	static std::shared_ptr<CrabArm> crabArm;
	static std::shared_ptr<Grabber> grabber;
	static std::shared_ptr<Lift> lift;

//	Drivetrain * drivetrain;
//	Spatula * spatula;
//	CrabArm * crabArm;
//	Grabber * grabber;
//	Lift * lift;

	void RobotInit() override {
		drivetrain.reset(new Drivetrain);
		spatula.reset(new Spatula());
     	crabArm.reset(new CrabArm());
		grabber.reset(new Grabber());
		lift.reset(new Lift());
	}

	void DisabledInit() override {
	}

	void DisabledPeriodic() override {
	}

	void AutonomousInit() override {
	}

	void AutonomousPeriodic() override {
	}

	void TeleopInit() override {
	}

	void TeleopPeriodic() override {
	}

	void TestPeriodic() override {
	}

private:
	};


