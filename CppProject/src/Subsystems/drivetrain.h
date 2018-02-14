#ifndef drivetrain_H
#define drivetrain_H

#include <Commands/Subsystem.h>
#include <WPIlib.h>
#include <Talon.h>

class drivetrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	drivetrain();
	void InitDefaultCommand();
};

#endif  // drivetrain_H
