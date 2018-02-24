/*
 * Gamepad.cpp
 */

#include "edu.stuy.util/Gamepad.h"


Gamepad::Gamepad(int port, GamepadSwitchMode switchMode = GamepadSwitchMode::SWITCH_D) {
	Joystick(port);
	this->switchMode = switchMode;
}

static class Gamepad::DPadButton : public Button {
	static enum Direction {
			UP, DOWN, LEFT, RIGHT
	};

	private:
		Gamepad * gamepad;
		Direction * direction;

	public:
		DPadButton(Gamepad gamepad, Direction direction) {
			this->gamepad = gamepad;
			this->direction = direction;
		};
};

double Gamepad::GetLeftX() {
	return GetRawAxis(0);
}

double Gamepad::GetLeftY() {
	return -GetRawAxis(1);
}

double Gamepad::GetRightX() {
	switch (switchMode) {
		case SWITCH_D:
			return GetRawAxis(4);
		case SWITCH_X:
			return GetRawAxis(0);
		case PS4:
		    return GetRawAxis(2);
		default:
			return 0;
	}
}

double Gamepad::GetRightY() {
	switch (switchMode) {
		case SWITCH_D:
			return -GetRawAxis(3);
		case SWITCH_X:
		case PS4:
			return -GetRawAxis(5);
		default:
			return 0;
	}
}

bool Gamepad::GetRawDPadUp() {
	return GetPOV() == 0;
}

Gamepad::DPadButton Gamepad::GetDPadUp() {
	return new Gamepad::DPadButton::DPadButton(this, Gamepad::DPadButton::UP);
}

bool Gamepad::GetRawDPadDown() {
	return GetPOV() == 180;
}

Gamepad::DPadButton GetDPadDown() {
	return new Gamepad::DPadButton::DPadButton(this, Gamepad::DPadButton::DOWN);
}

bool Gamepad::GetRawDPadLeft() {
	return GetPOV() == 270;
}

Gamepad::DPadButton getDPadLeft() {
	return new Gamepad::DPadButton::DPadButton(this, Gamepad::DPadButton::LEFT);
}

bool Gamepad::GetRawDPadRight() {
		return GetPOV() == 90;
}

Gamepad::DPadButton Gamepad::GetDPadRight() {
	return new Gamepad::DPadButton::DPadButton(this, Gamepad::DPadButton::RIGHT);
}

bool Gamepad::GetRawLeftBumper() {
	return GetRawButton(5);
}

JoystickButton Gamepad::GetLeftBumper() {
	return new JoystickButton(this, 5);
}

bool Gamepad::GetRawRightBumper() {
	return GetRawButton(6);
}

JoystickButton Gamepad::GetRightBumper() {
	return new JoystickButton(this, 6);
}

double Gamepad::GetRawLeftTriggerAxis() {
	switch (switchMode) {
		case SWITCH_D:
			return GetRawLeftTrigger() ? 1 : 0;
		case SWITCH_X:
			return GetRawAxis(2);
		case PS4:
		    return (GetRawAxis(3) + 1) / 2;
		default:
			return 0;
	}
}

bool Gamepad::GetRawLeftTrigger() {
	switch (switchMode) {
		case SWITCH_D:
			return GetRawButton(7);
		case SWITCH_X:
		case PS4:
			return GetRawLeftTriggerAxis() > RAW_TRIGGER_PRESS_AXIS_THRESHOLD;
		default:
			return false;
	}
}

JoystickButton Gamepad::GetLeftTrigger() {
		switch (switchMode) {
			case SWITCH_D:
				return new JoystickButton(this, 7);
			case PS4:
			    return new JoystickButton(this, 1);
			case SWITCH_X:
			    return new LeftTriggerButton(this);
			default:
				return nullptr;
		}
	}

double Gamepad::GetRawRightTriggerAxis() {
	switch (switchMode) {
		case SWITCH_D:
			return GetRawLeftTrigger() ? 1 : 0;
		case SWITCH_X:
			return GetRawAxis(3);
		case PS4:
		    return (GetRawAxis(4) + 1) / 2;
		default:
			return 0;
	}
}

bool Gamepad::GetRawRightTrigger() {
	switch (switchMode) {
		case SWITCH_D:
			return GetRawButton(8);
		case SWITCH_X:
		case PS4:
			return GetRawRightTriggerAxis() > RAW_TRIGGER_PRESS_AXIS_THRESHOLD;
		default:
			return false;
	}
}

JoystickButton Gamepad::GetRightTrigger() {
	switch (switchMode) {
		case SWITCH_D:
			return new JoystickButton(this, 8);
		case PS4:
		    return new JoystickButton(this, 1);
		case SWITCH_X:
			return new RightTriggerButton(this);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawLeftButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(1);
		case SWITCH_X:
			return GetRawButton(3);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetLeftButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 1);
		case SWITCH_X:
			return new JoystickButton(this, 3);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawBottomButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(2);
		case SWITCH_X:
			return GetRawButton(1);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetBottomButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 2);
		case SWITCH_X:
			return new JoystickButton(this, 1);
		default:
			return nullptr;
		}
	}

bool Gamepad::GetRawRightButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(3);
		case SWITCH_X:
			return GetRawButton(2);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetRightButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 3);
		case SWITCH_X:
			return new JoystickButton(this, 2);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawTopButton() {
	return GetRawButton(4);
}

JoystickButton Gamepad::GetTopButton() {
	return new JoystickButton(this, 4);
}

bool Gamepad::GetRawSelectButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(9);
		case SWITCH_X:
			return GetRawButton(7);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetSelectButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 9);
		case SWITCH_X:
			return new JoystickButton(this, 7);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawStartButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(10);
		case SWITCH_X:
			return GetRawButton(8);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetStartButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 10);
		case SWITCH_X:
			return new JoystickButton(this, 8);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawLeftAnalogButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(11);
		case SWITCH_X:
			return GetRawButton(9);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetLeftAnalogButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 11);
		case SWITCH_X:
			return new JoystickButton(this, 9);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawRightAnalogButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return GetRawButton(12);
		case SWITCH_X:
			return GetRawButton(10);
		default:
			return false;
	}
}

JoystickButton Gamepad::GetRightAnalogButton() {
	switch (switchMode) {
		case SWITCH_D:
		case PS4:
			return new JoystickButton(this, 12);
		case SWITCH_X:
			return new JoystickButton(this, 10);
		default:
			return nullptr;
	}
}

bool Gamepad::GetRawOptionButton() {
	switch(switchMode) {
		case PS4:
	        return GetRawButton(10);
	    case SWITCH_D:
	    case SWITCH_X:
	    default:
	    		return false;
	}
}

bool Gamepad::Get() {
	switch (Gamepad::DPadButton::direction) {
		case Gamepad::DPadButton::UP:
			return Gamepad::DPadButton::gamepad->GetRawDPadUp();
		case Gamepad::DPadButton::DOWN:
			return Gamepad::DPadButton::gamepad->GetRawDPadDown();
		case Gamepad::DPadButton::LEFT:
			return Gamepad::DPadButton::gamepad->GetRawDPadLeft();
		case Gamepad::DPadButton::RIGHT:
			return Gamepad::DPadButton::gamepad->GetRawDPadRight();
		default: // Never reached
			return false;
	}
}

static class LeftTriggerButton : public Button {
	private:
		Gamepad * gamepad;
	public:
		LeftTriggerButton(Gamepad gamepad) {
	        this->gamepad = gamepad;
	    }

//	    @Override
	    bool Get() {
	        return gamepad->GetRawLeftTrigger();
	    }
	};

static class RightTriggerButton: public Button {
	private:
		Gamepad * gamepad;
	public:
		RightTriggerButton(Gamepad gamepad) {
            this->gamepad = gamepad;
        }

//        @Override
        bool Get() {
            return gamepad->GetRawRightTrigger();
        }
};

Gamepad::~Gamepad() {
	// TODO Auto-generated destructor stub
}

