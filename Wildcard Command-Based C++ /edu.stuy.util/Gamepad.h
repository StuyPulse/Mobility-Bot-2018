/*
 * Gamepad.h
*/

#ifndef EDU_STUY_UTIL_GAMEPAD_H_
#define EDU_STUY_UTIL_GAMEPAD_H_

#include <buttons/Button.h>
#include <Joystick.h>
#include <buttons/JoystickButton.h>

class Gamepad : public Joystick {
private:
	constexpr double RAW_TRIGGER_PRESS_AXIS_THRESHOLD = 0.1;

public:
	static class DPadButton;
	static class LeftTriggerButton;
	static class RightTriggerButton;

	enum GamepadSwitchMode {
			SWITCH_X,
			SWITCH_D,
			PS4
	};

	GamepadSwitchMode switchMode;

	Gamepad(int port, GamepadSwitchMode switchMode);
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
	JoystickButton GetLeftBumper();
	bool GetRawRightBumper();
	JoystickButton GetRightBumper();
	double GetRawLeftTriggerAxis();
	bool GetRawLeftTrigger();
	JoystickButton GetLeftTrigger();
	double GetRawRightTriggerAxis();
	bool GetRawRightTrigger();
	JoystickButton GetRightTrigger();
	bool GetRawLeftButton();
	JoystickButton GetLeftButton();
	bool GetRawBottomButton();
	JoystickButton GetBottomButton();
	bool GetRawRightButton();
	JoystickButton GetRightButton();
	bool GetRawTopButton();
	JoystickButton GetTopButton();
	bool GetRawSelectButton();
	JoystickButton GetSelectButton();
	bool GetRawStartButton();
	JoystickButton GetStartButton();
	bool GetRawLeftAnalogButton();
	JoystickButton GetLeftAnalogButton();
	bool GetRawRightAnalogButton();
	JoystickButton GetRightAnalogButton();
	bool GetRawOptionButton();
	bool Get();

	virtual ~Gamepad();
};

#endif /* EDU_STUY_UTIL_GAMEPAD_H_ */
