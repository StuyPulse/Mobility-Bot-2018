/*
 * SignalLight.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#include <edu.stuy.util/SignalLight.h>

SignalLight::SignalLight(int port, bool onValue) {
	_light = new frc::DigitalOutput(port);
	_lightOnValue = onValue;
	_blinking = false;
	_lastSetOn = false;
	_blinkingStart = false;
}
void SignalLight::SetLight(bool on){
	if(on) {
		_light->Set(_lightOnValue);
	}else {
		_light->Set(!_lightOnValue);
	}

	//_light->Set(on ? _lightOnValue : !_lightOnValue); //Small Problem, c++ doesn't see the statement as a boolean
	_lastSetOn = on;
}
void SignalLight::StayOn(){
	SignalLight::SetLight(true);
	_blinking = false;
}
bool SignalLight::GetBlinking(){
	return _blinking;
}
void SignalLight::SetBlinking(bool blink){
	if (blink) {
		SignalLight::SetLight(false);
		_blinking = true;
		_blinkingStart = _timer->GetFPGATimestamp();
	}else {
		_blinking = false;
	}
}
void SignalLight::Tick(){
	if (_blinking) {
		double now = _timer->GetFPGATimestamp();
		double dt = (now - _blinkingStart) % blinkPeriod;
			if (dt < blinkPeriod / 2) {
				// During the first half-period, the light is off
					if (_lastSetOn) {
						SignalLight::SetLight(false);
					}
			} else {
				// During the second half-period, the light is on
				if (!_lastSetOn) {
					SignalLight::SetLight(true);
				}
			}
	}
}
SignalLight::~SignalLight() {
}

