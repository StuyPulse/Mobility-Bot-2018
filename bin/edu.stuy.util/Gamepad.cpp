/*
 * Gamepad.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: evang
 */

#include <edu.stuy.util/Gamepad.h>
#include <Joystick.h>

static enum Direction{
		UP, DOWN, LEFT, RIGHT
	};

Gamepad::DPadButton::DPadButton(Gamepad gamepad, Direction direction){

	_gamepad = new Gamepad;
	_direction = new Direction;

	gamepad = _gamepad;
	direction = _direction;
}
bool Gamepad::DPadButton::Get(){
	switch (_direction){
	case UP:
		return _gamepad->GetRawDPadUp();
	case DOWN:
		return _gamepad->GetRawDPadDown();
	case LEFT:
		return _gamepad->GetRawDPadLeft();
	case RIGHT:
		return _gamepad->GetRawDPadRight();
	default:
		return false;
	}
}

//Gamepad must be in D Mode
Gamepad::Gamepad(int port) {
	frc::Joystick(port);
}
double Gamepad::GetLeftX(){
	return GetRawAxis(0);
}
double Gamepad::GetLeftY(){
	return GetRawAxis(1);
}
double Gamepad::GetRightX(){
	return GetRawAxis(2);
}
double Gamepad::GetRightY(){
	return GetRawAxis(3);
}
bool Gamepad::GetRawDPadUp(){
	return GetPOV() == 0;
}
Gamepad::DPadButton Gamepad::GetDPadUp(){
	return new DPadButton(this, UP);
}
bool Gamepad::GetRawDPadDown(){
	return GetPOV() == 180;
}
Gamepad::DPadButton Gamepad::GetDPadDown(){
	return new DPadButton(this, DOWN);
}
bool Gamepad::GetRawDPadLeft(){
	return GetPOV() == 270;
}
Gamepad::DPadButton Gamepad::GetDPadLeft(){
	return new DPadButton(this, LEFT);
}
bool Gamepad::GetRawDPadRight(){
	return GetPOV() == 90;
}
Gamepad::DPadButton Gamepad::GetDPadRight(){
	return new DPadButton(this, RIGHT);
}
bool Gamepad::GetRawLeftBumper(){
	return GetRawButton(5);
}
frc::JoystickButton Gamepad::GetLeftBumper(){
	return new frc::JoystickButton(this, 5);
}
bool Gamepad::GetRawRightBumper(){
	return GetRawButton(6);
}
frc::JoystickButton Gamepad::GetRightBumper(){
	return new frc::JoystickButton(this, 6);
}
bool Gamepad::GetRawLeftTrigger(){
	return GetRawButton(7);
}
frc::JoystickButton Gamepad::GetLeftTrigger(){
	return new frc::JoystickButton(this, 7);
}
bool Gamepad::GetRawRightTrigger(){
	return GetRawButton(8);
}
frc::JoystickButton Gamepad::GetRightTrigger(){
	return new frc::JoystickButton(this, 8);
}
bool Gamepad::GetRawLeftButton(){
	return GetRawButton(1);
}
frc::JoystickButton Gamepad::GetLeftButton(){
	return new frc::JoystickButton(this, 1);
}
bool Gamepad::GetRawBottomButton(){
	return GetRawButton(2);
}
frc::JoystickButton Gamepad::GetBottomButton(){
	return new frc::JoystickButton(this, 2);
}
bool Gamepad::GetRawRightButton(){
	return GetRawButton(3);
}
frc::JoystickButton Gamepad::GetRightButton(){
	return new frc::JoystickButton(this, 3);
}
bool Gamepad::GetRawTopButton(){
	return GetRawButton(4);
}
frc::JoystickButton Gamepad::GetTopButton(){
	return new frc::JoystickButton(this, 4);
}
bool Gamepad::GetRawSelectButton(){
	return GetRawButton(9);
}
frc::JoystickButton Gamepad::GetSelectButton(){
	return new frc::JoystickButton(this, 9);
}
bool Gamepad::getRawStartButton(){
	return GetRawButton(10);
}
frc::JoystickButton Gamepad::GetStartButton(){
	return new frc::JoystickButton(this, 10);
}
bool Gamepad::GetRawLeftAnalogButton(){
	return GetRawButton(11);
}
frc::JoystickButton Gamepad::GetLeftAnalogButton(){
	return new frc::JoystickButton(this, 11);
}
bool Gamepad::GetRawRightAnalogButton(){
	return GetRawButton(12);
}
frc::JoystickButton Gamepad::GetRightAnlogButton(){
	return new frc::JoystickButton(this, 12);
}

Gamepad::~Gamepad() {
}


