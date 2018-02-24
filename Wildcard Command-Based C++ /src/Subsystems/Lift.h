#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <DigitalInput.h>

class Lift : public Subsystem {
private:
	WPI_TalonSRX * innerLeftMotor;
	WPI_TalonSRX * innerRightMotor;
	WPI_VictorSPX * outerLeftMotor;
	WPI_VictorSPX * outerRightMotor;

	DigitalInput * topLimitSwitch;
	DigitalInput * bottomLimitSwitch;
public:
	Lift();
	void InitDefaultCommand();
    void Periodic();
    void ResetEncoders();
    void MoveLift(double speed);
    void Move(double currentSpeed);
    double GetSpeed();
    void Stop();
    bool GetBrakeStatus();
    bool IsAtBottom();
    bool IsAtTop();
    double GetLeftRawEncoderDistance();
    double GetRightRawEncoderDistance();
    double GetLeftEncoderDistance();
    double GetRightEncoderDistance();
    double GetLiftHeight();
    void SetHeight(double height);
    double GetMotorVelocity();
};

#endif  // Lift_H
