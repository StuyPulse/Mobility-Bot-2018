/*
 * Gamepad.h
 *
 *  Created on: Feb 23, 2018
 *      Author: evang
 */

#ifndef SRC_EDU_STUY_UTIL_GAMEPAD_H_
#define SRC_EDU_STUY_UTIL_GAMEPAD_H_
#include <Joystick.h>
#include <buttons/JoystickButton.h>

class Gamepad : public frc::Joystick{
public:
	static class DPadButton : public frc::Button{
	public:
		static enum Direction{};
		Gamepad * _gamepad;
		Direction * _direction;
		DPadButton(Gamepad gamepad, Direction direction);
		bool DPadButton::Get();
	};

	Gamepad(int port);

	double GetLeftX();
	double GetLeftY();

	double GetRightX();
	double GetRightY();

	bool GetRawDPadUp();
	DPadButton GetDPadUp();

	bool GetRawDPadDown();
	DPadButton GetDPadDown();

	bool GetRawDPadLeft();
	DPadButton GetDPadLeft();

	bool GetRawDPadRight();
	DPadButton GetDPadRight();

	bool GetRawLeftBumper();
	frc::JoystickButton GetLeftBumper();

	bool GetRawRightBumper();
	frc::JoystickButton GetRightBumper();

	bool GetRawLeftTrigger();
	frc::JoystickButton GetLeftTrigger();

	bool GetRawRightTrigger();
	frc::JoystickButton GetRightTrigger();

	bool GetRawLeftButton();
	frc::JoystickButton GetLeftButton();

	bool GetRawBottomButton();
	frc::JoystickButton GetBottomButton();

	bool GetRawRightButton();
	frc::JoystickButton GetRightButton();

	bool GetRawTopButton();
	frc::JoystickButton GetTopButton();

	bool GetRawSelectButton();
	frc::JoystickButton GetSelectButton();

	bool getRawStartButton();
	frc::JoystickButton GetStartButton();

	bool GetRawLeftAnalogButton();
	frc::JoystickButton GetLeftAnalogButton();

	bool GetRawRightAnalogButton();
	frc::JoystickButton GetRightAnlogButton();

	virtual ~Gamepad();
};


#endif /* SRC_EDU_STUY_UTIL_GAMEPAD_H_ */
