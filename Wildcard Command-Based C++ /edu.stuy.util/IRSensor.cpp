/*
 * IRSensor.cpp
 */

#include "edu.stuy.util/IRSensor.h"

#include <AnalogInput.h>
#include <SmartDashboard/SmartDashboard.h>

namespace frc {
class SmartDashboard;
} /* namespace frc */

IRSensor::IRSensor() {
    cubeSensor = new AnalogInput(IR_SENSOR_PORT);
}

double IRSensor::getSensorVoltage() {
	return cubeSensor->GetVoltage();
}

bool IRSensor::isCubeDetected() {
    return getSensorVoltage() > frc::SmartDashboard::GetNumber("IRVoltageThreshold", IR_SENSOR_THRESHOLD);
    }

IRSensor::~IRSensor() {
}

