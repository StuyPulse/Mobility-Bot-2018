#ifndef Grabber_H
#define Grabber_H

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>

class Grabber : public Subsystem {
private:
	DoubleSolenoid * grabberSolenoid;

public:
	Grabber();
	void InitDefaultCommand();
	void Open();
	void Close();
	void Toggle();
};

#endif  // Grabber_H
