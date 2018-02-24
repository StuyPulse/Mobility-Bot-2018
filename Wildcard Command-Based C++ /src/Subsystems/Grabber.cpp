#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() : Subsystem("ExampleSubsystem") {
	grabberSolenoid = new DoubleSolenoid(GRABBER_SOLENOID_OPEN_PORT, GRABBER_SOLENOID_CLOSE_PORT);
}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Grabber::Open(){
	grabberSolenoid->Set(DoubleSolenoid::Value::kReverse);
}

void Grabber::Close(){
	grabberSolenoid->Set(DoubleSolenoid::Value::kForward);
}

void Grabber::Toggle() {
	if (grabberSolenoid->Get() == DoubleSolenoid::Value::kReverse) {
		Close();
	} else
		Open();
}
