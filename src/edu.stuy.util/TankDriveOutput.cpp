/*
 * TankDriveOutput.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#include <TankDriveOutput.h>
#include <RobotMap.h>

TankDriveOutput::TankDriveOutput(frc::DifferentialDrive drive) {
	_pidDrive = drive;
	_maxValue = PID_MAX_ROBOT_SPEED;
}
void TankDriveOutput::pidWrite(double output){
	if (abs(output) > _maxValue) {
				output = _maxValue * (output / abs(output));
			}
			_pidDrive->TankDrive(output, -output);
}
TankDriveOutput::~TankDriveOutput() {
}

