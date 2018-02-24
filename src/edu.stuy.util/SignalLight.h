/*
 * SignalLight.h
 *
 *  Created on: Feb 22, 2018
 *      Author: evang
 */

#ifndef SRC_EDU_STUY_UTIL_SIGNALLIGHT_H_
#define SRC_EDU_STUY_UTIL_SIGNALLIGHT_H_
#include <DigitalOutput.h>
#include "Timer.h"

class SignalLight {
private:

	constexpr static double blinkPeriod = 1.5;

	bool * _lastSetOn;
	bool * _blinking;
	bool * _blinkingStart;

	frc::DigitalOutput * _light;
	bool * _lightOnValue;

	Timer * _timer = new Timer();

public:
	SignalLight(int port, bool onValue);
	void SetLight(bool on);
	void StayOn();
	bool GetBlinking();
	void SetBlinking(bool blink);
	void Tick();
	virtual ~SignalLight();
};

#endif /* SRC_EDU_STUY_UTIL_SIGNALLIGHT_H_ */
