#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include <Solenoid.h>

// no line sensors or gyro

class Drivetrain : public Subsystem {
private:
	WPI_VictorSPX * leftTopMotor;
	WPI_VictorSPX * leftMiddleMotor;
	WPI_TalonSRX * leftBottomMotor;
	WPI_VictorSPX * rightTopMotor;
	WPI_VictorSPX * rightMiddleMotor;
	WPI_TalonSRX * rightBottomMotor;

	DifferentialDrive * differentialDrive;

    Solenoid * gearShift;
public:
	Drivetrain();
	void InitDefaultCommand();
	double GetLeftSpeed();
	double GetRightSpeed();
	double GetSpeed();
	double GetRawEncoderDistance();
	double GetEncoderDistance();
	double GetLeftEncoderDistance();
	double GetRightEncoderDistance();
	double GetLeftRawEncoderDistance();
	double GetRightRawEncoderDistance();
	void ResetEncoders();
	void SetEncoders(double inches);
	void TankDrive(double left, double right);
	void ArcadeDrive(double speed, double rotation);
	void CurvatureDrive(double speed, double rotation, bool turn);
	void Stop();
	void HighGearShift();
	void LowGearShift();
	void ToggleGearShift();
	void GearShiftInput(bool isShifted);
	bool IsGearShift();
	double GetGyroAngle();
	void SetRamp(double rampSeconds);
};

#endif  // Drivetrain_H
