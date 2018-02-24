/*
 * TankDriveOutput.h
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#ifndef SRC_TANKDRIVEOUTPUT_H_
#define SRC_TANKDRIVEOUTPUT_H_
#include <PIDOutput.h>
#include "ctre/Phoenix.h"
#include "Drive/DifferentialDrive.h"


class TankDriveOutput {
private:

	frc::DifferentialDrive * _pidDrive;
	double * _maxValue;

public:
	TankDriveOutput(frc::DifferentialDrive drive);
	void pidWrite(double output);
	virtual ~TankDriveOutput();
};

#endif /* SRC_TANKDRIVEOUTPUT_H_ */
