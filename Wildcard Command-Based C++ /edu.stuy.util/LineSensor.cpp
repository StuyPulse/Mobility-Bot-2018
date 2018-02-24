/*
 * LineSensor.cpp
 */

#include "edu.stuy.util/LineSensor.h"

#include <Math.h>

LineSensor::LineSensor(int port) {
	framesExisted = 0;
	ambientLight = 0;
	isChangedBefore = false;
	max = 0;
	rawValue = mySensor->GetValue();
	setupDone = false;
	mySensor = new AnalogInput(port);
}

double LineSensor::GetRawData() {
	rawValue = mySensor->GetValue();
	return rawValue;
}

void LineSensor::InitialLoop() {
	setupDone = (framesExisted == DRIVETRAIN_LINE_SENSOR_INITIALIZE_TIME);
	ambientLight = rawValue;
}

void LineSensor::MainLoop() {
	framesExisted += 1;
	GetRawData();
	if (!setupDone) {
		InitialLoop();
	}
}

void LineSensor::ResetAmbient() {
	framesExisted = 0;
	setupDone = false;
}

bool LineSensor::BasicFind() {
	if ((abs(rawValue - ambientLight)) > max) {
		max = abs(rawValue - ambientLight);
	}
	bool temp = isChangedBefore;
	isChangedBefore = abs(rawValue - ambientLight) < DRIVETRAIN_LINE_SENSOR_THRESHOLD;
	return (!temp) && isChangedBefore;
 }
LineSensor::~LineSensor() {
}

