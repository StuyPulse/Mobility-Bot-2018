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

class Shooter : public frc::Subsystem {
private:
	WPI_TalonSRX * _shooterMotor;
public:
	Shooter();
	void InitDefaultCommand() override;

	~Shooter();
};

